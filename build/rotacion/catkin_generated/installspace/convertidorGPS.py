#!/usr/bin/env python2
# from tf.transformations import euler_from_quaternion
# import roslib; #roslib.load_manifest('rotacion')
from itertools import count
import rospy

#rotacion/movement  
# from custom_msg.msg import movement
from std_msgs.msg import Float64
from std_msgs.msg import Float32


class publisher():
    def __init__(self):
        self.left = rospy.Publisher("/wamv/thrusters/left_thrust_cmd", Float32)
        self.right = rospy.Publisher("/wamv/thrusters/right_thrust_cmd", Float32)



    #hacer revision de si esta a menos de 6 metros publicar 0
    def publish(self,distance,angle):
        
        
        msgL = Float32()
        msgR = Float32()
        print("\n----------------------------------------\n")

        if (distance  == 0):
            angle *= 100 
        else:
            distance /= 20
            angle /= (3.14*2) 

        print("distance: {d}, angle: {a}".format(d = distance,a = angle))

        msgR.data =  float((distance + angle)/ 2)
        msgL.data =  float((distance - angle)/ 2)
        
        
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
distance = 99999
angle = 0
count_away = 0
angle_state = False

def reduce_distance(data):
    global distance
    if (data >= distance):
        global count_away
        count_away +=1
        if (count_away > 10):
            count_away= 300
            return True
    return False

def linealConversion(data):
    print("entre en lineal")
    global angle_state
    if(not angle_state):
        global angle_state
        angle_state= reduce_distance(data.data)
        global distance
        distance = data.data
    else:
        global distance
        distance = 0
        global count_away
        count_away-= 1
        global angle_state
        print("angle antes de comparacion: {d}".format(d= angle_state))
        angle_state = count_away != 0
        print("angle despues de comparacion: {d}".format(d= angle_state))
    print("distance: {d}".format(d= distance))
    print("count_away: {d}".format(d= count_away))
    print("angle: {d}".format(d= angle_state))
    p.publish(distance,angle)

def angularConversion(data):
    print("entre en angular, distance: {d}".format(d= distance))
    global angle_state
    if(angle_state):
        global angle
        angle = data.data * 5
    else:
        global angle
        angle = data.data
    p.publish(distance,angle)
    rospy.sleep(100)


def listener():
    rospy.Subscriber("/lineal_velocity", Float64, linealConversion)
    rospy.Subscriber("/angular_velocity", Float64, angularConversion)
    print("se subscribe")
    rospy.spin()




if __name__ == '__main__':
    rospy.init_node('convertidorGPS')
    listener()