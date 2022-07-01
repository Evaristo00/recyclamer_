#!/usr/bin/env python
from tf.transformations import euler_from_quaternion
import roslib; #roslib.load_manifest('rotacion')
import rospy
import math 


import utm
import geometry_msgs.msg
import sensor_msgs.msg
from sensor_msgs.msg import NavSatFix
from std_msgs.msg import Float64


class publisher():
    def __init__(self):
        self.linealPub = rospy.Publisher("/state_lineal_pidRef", Float64)
        self.angularPub = rospy.Publisher("/state_angular_pidRef", Float64)

    #hacer revision de si esta a menos de un metro publicar 0
    def sendLinealMessege(self,distance):
        msg = Float64()
        msg.data = distance
        # rospy.loginfo(msg)
        self.linealPub.publish(msg)
    
    def sendAngularMessege(self, angle):
        msg = Float64()
        msg.data = angle
        # rospy.loginfo(msg)
        self.angularPub.publish(msg)

         


p = publisher()
angle = 0
distance = 0
ImuOrientation= 0

def calculateAngle(x,y):
    global ImuOrientation
    #problema el angulo va 0-360-(-360)-(-0)
    print("Imu angle: {a}".format(a=ImuOrientation))
    return 0

def calc_dif(data):
    print("GPS latitude: {lat}, longitud: {long}".format(lat = data.latitude,long= data.longitude))
    posX , posY = utm.from_latlon(data.latitude, data.longitude)[0:2]
    print("posX: {posX}, posY: {posY}".format(posX = posX,posY= posY))
    global goalX
    print("goalX :  {goalX}".format(goalX=goalX))
    RelativeGoalX = goalX - posX
    print("relative goalX: {g}".format(g=RelativeGoalX))
    global goalY
    print("goalY :  {goalY}".format(goalY=goalY))
    RelativeGoalY = goalY - posY
    print("relative goalY: {g}".format(g=RelativeGoalY))

    distance = (RelativeGoalX**2 + RelativeGoalY**2)**0.5
    print("distance {d}".format(d=distance) )
    angle = calculateAngle(RelativeGoalX,RelativeGoalY)
    
    print("\n\n ------------------------------- \n\n")



    
def setImu(data):
    
    w_orientation = data.orientation.w
    x_orientation = data.orientation.x
    y_orientation = data.orientation.y
    z_orientation = data.orientation.z
    global ImuOrientation
    ImuOrientation = euler_from_quaternion(quaternion=[x_orientation,y_orientation,z_orientation,w_orientation])[2]
    # print("caso ywzw:{a} ".format(a=ImuOrientation))
    ImuOrientation = ImuOrientation * 360 / 3.14
    # print("angulo corrimiento:{a} ".format(a=ImuOrientation))



def listener():
    rospy.Subscriber("/wamv/sensors/imu/imu/data", sensor_msgs.msg.Imu, setImu)
    rospy.Subscriber("/wamv/sensors/gps/gps/fix", sensor_msgs.msg.NavSatFix, calc_dif)
    print("se subscribe posicion actual")
    rospy.spin()



if __name__ == '__main__':
    rospy.init_node('movGPS')
    global goalX
    # goalX = float(input('Enter a Latitude: '))
    goalX = 21.31109
    global goalY
    # goalY= float(input('Enter a Longitude: '))
    goalY = -157.88858
    goalX, goalY = utm.from_latlon(goalX,goalY)[0:2]
    listener()
