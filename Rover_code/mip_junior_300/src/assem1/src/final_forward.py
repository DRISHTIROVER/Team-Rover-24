#!/usr/bin/env python3
from sympy import *
import numpy as np
import rospy
from sensor_msgs.msg import JointState

if __name__ == '__main__':
    T1 = 20
    T2 = 20
    T3 = 20
    T1=(T1*np.pi)/180
    T2=(T2*np.pi)/180
    T3=(T3*np.pi)/180
    a1 = 0.32422
    a2 = 0.40000
    a3 = 0.39998
    PT = [[T1,np.pi/2,0,a1],[T2,0,a2,0],[T3,0,a3,0]]
    rospy.init_node('try', anonymous=True)
    pub = rospy.Publisher("/joint_states",JointState,queue_size = 500)
    joint = JointState()
    while not rospy.is_shutdown():
        r = rospy.Rate(0.5)
        joint.header.stamp = rospy.Time.now()
        joint.name = ["J1_2","J2_3","J3_4","J4_5","J5_6","J6_7","J6_8"]
        joint.velocity = []
        joint.effort = []
        r.sleep()
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
        rospy.loginfo("x = %f,y = %f z = %f",HTM0_3[0][3]+0.08,HTM0_3[1][3]+0.10,HTM0_3[2][3])
        pub.publish(joint)
    