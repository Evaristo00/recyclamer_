#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

//Comando para ejecutar el nodo rosserial
//sudo chmod a+rw /dev/ttyUSB0
//rosrun rosserial_python serial_node-py /dev/ttyACM0
//rosrun rosserial_python serial_node.py _port:=/dev/ttyUSB0 _baud:=57600



//#include <Servo.h>
#include <ros.h>


#include <std_msgs/Float32.h> //incluimos tipo de mensaje float32 para simulador
#include <std_msgs/Float64.h> //incluimos tipo de mensaje float64 para PID

//---------
const float l = 1.2; //Ancho del robot marino-//  

ros::NodeHandle  nh;
int a;

double vel_ang= 0;    //Velocidad angular control(Recibida del PID,Control) -Control_vel_angular-
double vel_lineal= 0; //Velocidad lineal control (Recibida del PID,Control) -Control_vel_lineal- 

float r; //Radio de giro, distancia del centro del vehiculo al punto de giro

float vl;   //velocidad helice izquierda Fisica
float vr;   //velocidad helice derecha  Fisica
float vm;   //velocidad helice central  Fisica

//msgs para la publicacion de control en el simulador
std_msgs::Float32 msgL;   
std_msgs::Float32 msgR;
std_msgs::Float32 msgM;

//Msg para el suscriptor del PID
std_msgs::Float64 msgVelAng;
std_msgs::Float64 msgVelLineal;


//msgs para el PID (Prueba)
std_msgs::Float64 msgStateAngular;
std_msgs::Float64 msgStateLineal;

//Publicadores de helices simulador
ros::Publisher pVelRigth("/wamv/thrusters/right_thrust_cmd", &msgR);   
ros::Publisher pVelLeft("/wamv/thrusters/left_thrust_cmd", &msgL);    
ros::Publisher pVelMid("/wamv/thrusters/rear_thrust_cmd", &msgM);    

//publocadores pid(Prueba)
ros::Publisher state_vel_angular("/state_vel_angular",&msgStateAngular);
ros::Publisher state_vel_lineal("/state_vel_lineal",&msgStateLineal);

//Declaracion helices fisicas
//Servo motorleft;
//Servo motorright;
//Servo motormiddle;



void subscripcion_vel_lineal(const std_msgs::Float64& msgVelLineal);       //Suscriptor al pid_ControlVelLineal
void subscripcion_vel_angular(const std_msgs::Float64& msgVelAng);      //Suscriptor al pid_ControlVelLineal
void publicador_helices(); //Publicador de control de helices en el simulador 


//Suscriptores al pid de control de velocidad lineal y angular
ros::Subscriber<std_msgs::Float64> subVelLineal("/control_vel_lineal", &subscripcion_vel_lineal);
ros::Subscriber<std_msgs::Float64> subVelAngular("/control_vel_angular", &subscripcion_vel_angular);

void setup(){

    nh.initNode();

    //Crea los nodos
    nh.advertise(pVelRigth);
    nh.advertise(pVelLeft);
    nh.advertise(pVelMid);
    nh.advertise(state_vel_angular);
    nh.advertise(state_vel_lineal);
    
    nh.subscribe(subVelLineal);
    nh.subscribe(subVelAngular);
    // ros::Subscriber subLineal= nh.subscribe("control_vel_lineal", 1000, &subscripcion_vel_lineal);
    // ros::Subscriber subAngular= nh.subscribe("control_vel_angular", 1000, &subscripcion_vel_angular);
    
    //Define los puertos del arduino para enviar el control PWM a cada helice fisica
    //motorleft.attach(8); //attach it to pin 8
    //motorright.attach(9); //attach it to pin 9
    //motormiddle.attach(10); //attach it to pin 9
}

void loop(){
  nh.spinOnce();
  
  //publicador_helices();
  delay(1000);
}

//Recibe los datos del PID de velocidad lineal y publica la velocidad para cada helice (Simulador: publicador helices) (fisicas:)
void subscripcion_vel_lineal(const std_msgs::Float64& msgVelLineal){
    vel_lineal = msgVelLineal.data;
  //  if (!vel_ang){
        publicador_helices();
    //}
}

//Recibe los datos del PID de velocidad angular y publica la velocidad para cada helice (Simulador: publicador helices (fisicas: ) 
void subscripcion_vel_angular(const std_msgs::Float64& msgVelAng){
    vel_ang = msgVelAng.data;
   // if (!vel_lineal){
        publicador_helices();
    //}
}

void publicador_helices(){

    /********************************************************************************************************
    Conversion de datos de velocidad lineal y velocidad angular a valores que los motores izq y der interpreten  
    **********************************************************************************************************/
   /*
    if((-1<vel_ang) && (vel_ang<1)) 
    {
      
      msgL.data=0.8;
      msgR.data=0.8;
      
      
    }else
    { 
      r= vel_lineal/vel_ang;   //Se calculo la distancia desde el vehiculo al centro de giro
      vl=vel_ang*(r-l/2)+vel_lineal;      //Se calcula la velocidad requerida para helice izquierda
      vr= vel_ang*(r+l/2)+vel_lineal;    //Se calcula la velocidad requerida para helice derecha
    }
     */
      /*******************Nueva conversion de velocidad a las helices******************************/
      vl=(0.1) *(vel_lineal-vel_ang);
      
      vr= (0.1) *(vel_lineal+vel_ang);

      // //Mapeo LINEAL para publicar los mensajes al SIMULADOR (Valores entre -1 y 1)
     //msgL.data = map(vl, -10, 10, -1, 1);
     //msgR.data = map(vr, -10, 10, -1, 1);
     msgL.data=vl;
     msgR.data=vr;
     msgM.data = vel_lineal;
  

     /********************************************************** */
    /***********************************************************************************************************/


      //Mapeo LINEAL de los valores al rango de valores FISICOS de PWM de las helices
     //vl = map(vl, 0, 10, 60, 120); //Mapeo el valor de velocidad con los valores posibles de velocidad del motor
     //vr = map(vr, 0, 10, 60, 120);  // (60 valor min de funcionamiento del moto, 120 valor maximo)
    // vm = 0.8 Helice central 


    
     
     

    //Valores de prueba para el SIMULADOR
    //msgL.data = 0.5;   
    //msgR.data = 0.5;     
    //msgM.data = 1;      

    //Conversion de valores realeas del PWM a una estimacion de velocidad angular y lineal de control para el PID(prueba)
      
      
      //msgStateAngular.data= 0.5 * vel_ang;
      
      //msgStateAngular.data= 0.5 * vel_lineal;


    //Publico los valores en topico del SIMULADOR
    pVelRigth.publish(&msgL);
    pVelLeft.publish(&msgR);
    pVelMid.publish(&msgM);

    //state_vel_angular.publish(&msgStateAngular);
    //state_vel_lineal.publish(&msgStateLineal);
    
    //Seteo de valores FISICOS de PWM a cada helice
    //motorleft.write(vl);
    //motorright.write(vr);    //set servo angle, should be from 60-120
    //motormiddle.write(vm);
 
}
