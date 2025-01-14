#!/usr/bin/env python3
from sympy import *
import numpy as np
import rospy
from sensor_msgs.msg import JointState
from cmath import sqrt
import rospy
import numpy as np
import math
from sensor_msgs.msg import JointState
import sys, select, termios, tty


if __name__ == '__main__':
    x = 0.1
    y = 0.1
    z = 0.1
    T1 = math.atan2(y,x)
    r1 = abs(sqrt(x*x+y*y))
    r2 = (z - 0.32265)
    r3 = abs(sqrt(r1*r1+r2*r2))
    temp1 = ((r3*r3)/(2*0.394*r3))
    ph1 = math.acos(temp1)
    ph2 = math.atan2(r2,r1)
    temp = (r3*r3 - 0.312845)/(-0.312836)
    ph3 = math.acos(temp)
    T2 = ph2 - ph1
    T3 = 1.57 - ph3 
    a1 = 0.32422
    a2 = 0.46000
    a3 = 0.39998
    PT = [[T1,np.pi/2,0,a1],[T2,0,a2,0],[T3,0,a3,0]]
    rospy.init_node('try', anonymous=True)
    pub = rospy.Publisher("/joint_states",JointState,queue_size = 500)
    while not rospy.is_shutdown():
        
        joint = JointState()
        joint.header.stamp = rospy.Time.now()
        joint.name = ["J1_2","J2_3","J3_4","J4_5","J5_6","J6_7","J6_8"]
        joint.velocity = []
        joint.effort = []
        HTM0_1 = [[np.cos(PT[0][0]),-np.sin(PT[0][0])*np.cos(PT[0][1]),np.sin(PT[0][0])*np.sin(PT[0][1]),PT[0][2]*np.cos(PT[0][0])],
        [np.sin(PT[0][0]),np.cos(PT[0][0])*np.cos(PT[0][1]),-np.cos(PT[0][0])*np.sin(PT[0][1]),PT[0][2]*np.sin(PT[0][0])],
        [0,np.sin(PT[0][1]),np.cos(PT[0][1]),PT[0][3]],
        [0,0,0,1]]
        i =1
        HTM1_2= [[np.cos(PT[i][0]),-np.sin(PT[i][0])*np.cos(PT[i][1]),np.sin(PT[i][0])*np.sin(PT[i][1]),PT[i][2]*np.cos(PT[i][0])],
        [np.sin(PT[i][0]),np.cos(PT[i][0])*np.cos(PT[i][1]),-np.cos(PT[i][0])*np.sin(PT[i][1]),PT[i][2]*np.sin(PT[i][0])],
        [0,np.sin(PT[i][1]),np.cos(PT[i][1]),PT[i][3]],
        [0,0,0,1]]
        i = 2
        HTM2_3= [[np.cos(PT[i][0]),-np.sin(PT[i][0])*np.cos(PT[i][1]),np.sin(PT[i][0])*np.sin(PT[i][1]),PT[i][2]*np.cos(PT[i][0])],
        [np.sin(PT[i][0]),np.cos(PT[i][0])*np.cos(PT[i][1]),-np.cos(PT[i][0])*np.sin(PT[i][1]),PT[i][2]*np.sin(PT[i][0])],
        [0,np.sin(PT[i][1]),np.cos(PT[i][1]),PT[i][3]],
        [0,0,0,1]]
        
        HTM0_2 = np.dot(HTM0_1,HTM1_2)
        HTM0_3 = np.dot(HTM0_2,HTM2_3)
        joint.position = [T1,T2,T3,0,0,0,0]
        rospy.loginfo("x = %f,y = %f z = %f",HTM0_3[0][3],HTM0_3[1][3],HTM0_3[2][3])
        pub.publish(joint)
    