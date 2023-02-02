#!/usr/bin/env python
# from tf.transformations import euler_from_quaternion
# import roslib; #roslib.load_manifest('rotacion')
from itertools import count
import rospy

#rotacion/movement  
# from custom_msg.msg import movement
from std_msgs.msg import Float64
from std_msgs.msg import Float32


class pub():


    def __init__(self):
        self.left = rospy.Publisher("/wamv/thrusters/left_thrust_cmd", Float32)
        self.right = rospy.Publisher("/wamv/thrusters/right_thrust_cmd", Float32)
 
    def publicar(self,right,left,until):
        
        
        msgL = Float32()
        msgR = Float32()

        msgL.data = left
        msgR.data  = right
        
        print("motorL: {d}, motorR: {a}".format(d = msgL.data,a = msgR.data))
        print("\n----------------------------------------\n")
        # rospy.loginfo(msgL)
        # rospy.loginfo(msgR)
        for x in range(0,until):
            self.left.publish(msgL)
            self.right.publish(msgR)
            rospy.sleep(0.01)
            # print(x)
        




p = pub()
distance = 99999
antDistnace= 99999
angle = 0
antAngle = 0
leftMotor = 1
rightMotor = 1

def outOfRange(left,right):
    #avoid out of range
    left = 1 if (left > 1) else (-1 if(left < -1) else left)
    right = 1 if (right > 1) else (-1 if(right < -1) else right)

    return (left, right)

def aumentrarGiroDer():
    global leftMotor
    leftMotor += 0.25
    global rightMotor
    rightMotor -= 0.25
    leftMotor , rightMotor = outOfRange(leftMotor,rightMotor)
    p.publicar(leftMotor,rightMotor,75)
    p.publicar(1,1,35)

def aumentarGiroIzq():
    global leftMotor
    leftMotor -= 0.25
    global rightMotor
    rightMotor += 0.25
    leftMotor , rightMotor = outOfRange(leftMotor,rightMotor)
    p.publicar(leftMotor,rightMotor,75)
    p.publicar(1,1,35)

def irDerecho():
    global leftMotor
    leftMotor += 0.25
    global rightMotor
    rightMotor += 0.25
    leftMotor , rightMotor = outOfRange(leftMotor,rightMotor)
    p.publicar(leftMotor,rightMotor,50)
    

def giro180():
    global leftMotor
    leftMotor = 1
    global rightMotor
    rightMotor = 1
    p.publicar(-1,1,1200)
    p.publicar(leftMotor,rightMotor,35)

def stateMachine():
    global distance 
    global antDistnace
    localDistance = distance
    localAntDistance = antDistnace
    antDistnace = localDistance

    if(localDistance > (localAntDistance + 0.1)):
        print("giro 180")
        giro180()
    else:
        global angle
        global antAngle
        localAngle = angle
        localAntAngle = antAngle
        antAngle = localAngle
        
        print("angulo: {d}, antAngle: {a}".format(d = localAngle,a = localAntAngle))
        print("\n----------------------------------------\n")


        #si disminuye el angulo debo girar a la derecha, si aumenta giro a la izquierda
        if (localAntAngle > localAngle + 0.3 ): # 0.3 grades of tolerance
            print("girar derecha")
            aumentrarGiroDer()
        elif (localAntAngle + 0.3 < localAngle):
            print("girar izq")
            aumentarGiroIzq()
        else:
            print("derecho")
            irDerecho()

    return 0
    




def linealConversion(data):
    global distance
    distance = data.data

def angularConversion(data):
    global angle
    angle = data.data


def listener():
    rospy.Subscriber("/lineal_velocity", Float64, linealConversion)
    rospy.Subscriber("/angular_velocity", Float64, angularConversion)
    print("se subscribe")
    while True:
        print("\n----------------------------------------\n")
        print("cominezo proceso")
        print("\n----------------------------------------\n")
        stateMachine()
    # rospy.spin()




if __name__ == '__main__':
    rospy.init_node('convertidorOrientacion')
    listener()