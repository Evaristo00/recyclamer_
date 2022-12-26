#!/usr/bin/env python3
from tf.transformations import euler_from_quaternion
import roslib; #roslib.load_manifest('rotacion')
import rospy

#tf2_msgs/TFMessage
import tf2_ros
import tf2_msgs.msg
import geometry_msgs.msg

#rotacion/movement  
#from custom_msg.msg import movement
from std_msgs.msg import Float64

class publisher():
    def __init__(self):
        self.linealPub = rospy.Publisher("/state_lineal_pidRef", Float64)
        self.angularPub = rospy.Publisher("/state_angular_pidRef", Float64)

    #hacer revision de si esta a menos de un metro publicar 0
    def sendLinealMessege(self,distance):
        msg = Float64()
        if (distance < 1):
            msg.data = 0
        else:
            msg.data = distance
        # rospy.loginfo(msg)
        self.linealPub.publish(msg)
    
    def sendAngularMessege(self, angle):
        msg = Float64()
        msg.data = angle
        # rospy.loginfo(msg)
        self.angularPub.publish(msg)


p = publisher()


def make_rotation(data):
    #print("entro a la funcion")
    x_rotation = data.transforms[0].transform.rotation.x
    y_rotation = data.transforms[0].transform.rotation.y
    z_rotation = data.transforms[0].transform.rotation.z
    w_rotation = data.transforms[0].transform.rotation.w

    print(data.transforms[0].child_frame_id)
    #if its negative you will move to the right and vice versa
    angle = euler_from_quaternion(quaternion=[w_rotation,x_rotation,y_rotation,z_rotation], axes='sxyz')[1]
    
    p.sendAngularMessege(angle)

    x_translation = data.transforms[0].transform.translation.x
    z_translation = data.transforms[0].transform.translation.z
    distance = (x_translation**2 + z_translation**2)**0.5

    print("angle: {angle}, distance : {distance}".format(angle = angle, distance= distance))

    p.sendLinealMessege(distance)

def listener():
    rospy.Subscriber("/tf", tf2_msgs.msg.TFMessage, make_rotation)
    print("se subscribe")
    rospy.spin()




if __name__ == '__main__':
    rospy.init_node('rotacion')
    listener()