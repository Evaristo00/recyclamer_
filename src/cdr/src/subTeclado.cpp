// Este programa publica aleatoriamente mensajes de velocidad
// para el simulador turtlesim
#include <ros/ros.h>
#include <std_msgs/Float32.h> //incluimos tipo de mensaje
#include <geometry_msgs/Twist.h> //incluimos tipo de mensaje
//#include <stdlib.h> // para poder utilizar funcion rand()

//creamos un arreglo global de objetos publicadores
ros::Publisher pub[2];

void poseMensajeRecibido(const geometry_msgs::Twist& msg);

int main(int argc, char **argv)
{
	//inicializamos sistema ROS
	ros::init(argc, argv, "subTeclados");
	ros::NodeHandle nh;

	pub[0] =nh.advertise<std_msgs::Float32>("/wamv/thrusters/left_thrust_cmd", 1000);
	pub[1] =nh.advertise<std_msgs::Float32>("/wamv/thrusters/right_thrust_cmd", 1000);
	//creamos un objeto suscriptor
	ros::Subscriber sub= nh.subscribe("cmd_vel", 1000, &poseMensajeRecibido);
	//cedemos control a ROS
	ros::spin();
}

// funcion del topico, esta funcion es llamada cada vez que un nuevo mensaje es recibido
void poseMensajeRecibido(const geometry_msgs::Twist& msg)
{

	double velLineal = msg.linear.x;
	double velAngular = msg.angular.z;

	std_msgs::Float32 motorIzq, motorDer;

	motorIzq.data= velLineal - velAngular;
	motorDer.data= velLineal + velAngular;

	ROS_INFO_STREAM("velocidad del motor a izquierda=" << motorIzq.data);
	ROS_INFO_STREAM("velocidad del motor a derecha=" << motorDer.data);

	pub[0].publish(motorIzq);
	pub[1].publish(motorDer);
}