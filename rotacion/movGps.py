#!/usr/bin/env python
# from tf.transformations import euler_from_quaternion
import roslib; #roslib.load_manifest('rotacion')
import rospy
from geopy.distance import geodesic

#tf2_msgs/TFMessage
import tf2_ros
import tf2_msgs.msg
from tf2_msgs.msg import TFMessage
import geometry_msgs.msg
import sensor_msgs.msg
from sensor_msgs.msg import NavSatFix


class publisher():
    def __init__(self):
        self.pub_tf = rospy.Publisher("/tf", TFMessage, queue_size=10)

    
    def sendTf(self,tx,ty,tz,rx,ry,rz,rw):

        newport_ri = (tx,ty)
        cleveland_oh = (rx, ry)
        print(geodesic(newport_ri, cleveland_oh).miles)
        # t = geometry_msgs.msg.TransformStamped()
        # t.header.frame_id = "turtle1"
        # t.header.stamp = rospy.Time.now()
        # t.child_frame_id = "carrot1"
        # t.transform.translation.x = tx
        # t.transform.translation.y = ty
        # t.transform.translation.z = tz
        # t.transform.rotation.x = rx
        # t.transform.rotation.y = ry
        # t.transform.rotation.z = rz
        # t.transform.rotation.w = rw
        # tfm = tf2_msgs.msg.TFMessage([t])
        # self.pub_tf.publish(tfm)
         


p = publisher()



def make_tf(data):
    #print(data)
    print(data.latitude)
    print(data.longitude)
    p.sendTf(0,0,1,0,0,0,1)
    




def listener():
    rospy.Subscriber("/wamv/sensors/gps/gps/fix", sensor_msgs.msg.NavSatFix, make_tf)
    print("se subscribe")
    rospy.spin()




if __name__ == '__main__':
    rospy.init_node('rotacion')
    listener()