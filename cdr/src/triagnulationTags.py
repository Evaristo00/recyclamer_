#!/usr/bin/env python
from tf.transformations import euler_from_quaternion
import roslib; #roslib.load_manifest('rotacion')
import rospy

#tf2_msgs/TFMessage
import tf2_ros
import tf2_msgs.msg
import geometry_msgs.msg

#this makes a processing form 4 makers/tags that must have this distribution:

                        #   market2
                        #   1 meter
#               market1    -2 meters-    market0


class publisher():
    def __init__(self):
        self.pub = rospy.Publisher("/tf_process",  tf2_msgs.msg.TFMessage)

    #hacer revision de si esta a menos de un metro publicar 0
    def sendLinealMessege(self,distance):
        msg = Float64()
        msg.data = distance
        rospy.loginfo(msg)
        self.linealPub.publish(msg)


p = publisher()


distance = 0
angle= 0





def processPos():




def listener():
    rospy.Subscriber("/tf", tf2_msgs.msg.TFMessage, processPos)
    print("se subscribe")
    rospy.spin()




if __name__ == '__main__':
    rospy.init_node('rotacion')
    listener()
