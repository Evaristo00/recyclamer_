#!/usr/bin/env python
# from tf.transformations import euler_from_quaternion
import roslib; #roslib.load_manifest('rotacion')
import rospy
import math 

#tf2_msgs/TFMessage
# import tf2_ros
# import tf2_msgs.msg
# from tf2_msgs.msg import TFMessage
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


def calc_dif(data):
    #print(data)
    print("GPS latitude: {lat}, longitud: {long}".format(lat = data.latitude,long= data.longitude))
    global goalLat
    global goalLong
    print("Goal latitude: {lat}, longitud: {long}".format(lat = goalLat,long= goalLong))
    diflat = data.latitude - goalLat
    difLong = data.longitude - goalLong
    print("Dif latitude: {lat}, longitud: {long}".format(lat = diflat,long= difLong))
    diflat = int(diflat * 10**7)
    diflat = float(diflat* 10**-2)
    difLong = int(difLong * 10**7)
    difLong = float(diflat * 10**-2)
    print("Dif INT latitude: {lat}, longitud: {long}".format(lat = diflat,long= difLong))
    distance = (diflat**2 + difLong**2)**0.5
    angle = math.atan(difLong/diflat)
    print("distance: {d}, angle: {a}".format(d = distance,a= angle))
    p.sendLinealMessege(distance)
    p.sendAngularMessege(angle)

    
    




def listener():
    rospy.Subscriber("/wamv/sensors/gps/gps/fix", sensor_msgs.msg.NavSatFix, calc_dif)
    print("se subscribe posicion actual")
    rospy.spin()




if __name__ == '__main__':
    rospy.init_node('movGPS')
    global goalLat
    # goalLat = float(input('Enter a Latitude: '))
    goalLat = 21.31110
    global goalLong
    # goalLong= float(input('Enter a Longitude: '))
    goalLong = -157.88854
    listener()