#!/usr/bin/env python2
from tf.transformations import euler_from_quaternion
import roslib; #roslib.load_manifest('rotacion')
import rospy

#rotacion/movement  
# from custom_msg.msg import movement
from std_msgs.msg import Float64
from std_msgs.msg import Float32

max_value = 1


class publisher():
    def __init__(self):
        self.left = rospy.Publisher("/wamv/thrusters/left_thrust_cmd", Float32)
        self.right = rospy.Publisher("/wamv/thrusters/right_thrust_cmd", Float32)


    #hacer revision de si esta a menos de un metro publicar 0
    def publish(self,distance,angle):
        
        
        msgL = Float32()
        msgR = Float32()
        print("\n----------------------------------------\n")
        print("distance: {d}, angle: {a}".format(d = distance,a = angle))

        msgR.data = - float((distance + angle)/(max_value))
        msgL.data = - float((distance - angle)/(max_value))
        
        
        #avoid out of range
        msgR.data = 1 if (msgR.data > 1) else (-1 if(msgR.data < -1) else msgR.data)
        msgL.data = 1 if (msgL.data > 1) else (-1 if(msgL.data < -1) else msgL.data)
        
        print("motorL: {d}, motorR: {a}".format(d = msgL.data,a = msgR.data))
        print("\n----------------------------------------\n")
        # rospy.loginfo(msgL)
        # rospy.loginfo(msgR)
        self.left.publish(msgL)
        self.right.publish(msgR)



p = publisher()
distance = 0
angle = 0

def linealConversion(data):
    global distance
    distance = data.data
    p.publish(distance,angle)

def angularConversion(data):
    global angle
    angle = data.data
    p.publish(distance,angle)


def listener():
    rospy.Subscriber("/control_lineal", Float64, linealConversion)
    rospy.Subscriber("/control_angular",    Float64, angularConversion)
    print("se subscribe")
    rospy.spin()




if __name__ == '__main__':
    rospy.init_node('convertidor')
    listener()