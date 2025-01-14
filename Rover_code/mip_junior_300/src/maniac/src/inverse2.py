#!/usr/bin/env python3
from cmath import sqrt
import rospy
import numpy as np
import math
from sensor_msgs.msg import JointState
import sys, select, termios, tty

def getKey(key_timeout):
    settings = termios.tcgetattr(sys.stdin)
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], key_timeout)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN,settings)
    return key

def fk(d,t1,t2,t3):
    pt =[[0,0,0,0.16935+d],[t1,0,0.3008,-0.055],[t2,0,0.3,-0.04510],[t3,0,0,0]]
    for i in range(4):
        h =[[np.cos(pt[i][0]),-np.sin(pt[i][0])*np.cos(pt[i][1]),np.sin(pt[i][0])*np.sin(pt[i][1]),pt[i][2]*np.cos(pt[i][0])],
        [np.sin(pt[i][0]),np.cos(pt[i][0])*np.cos(pt[i][1]),-np.cos(pt[i][0])*np.sin(pt[i][1]),pt[i][2]*np.sin(pt[i][0])],
        [0,np.sin(pt[i][1]),np.cos(pt[i][1]),pt[i][3]],
        [0,0,0,1]]
        if i == 0:
            h01=h
        elif i==1:
            h12=h
        elif i==2:
            h23=h
        elif i==3:  
            h34=h

    h02 = np.dot(h01,h12)
    h03 = np.dot(h02,h23)
    A12 = np.dot(h12,h23)
    print(np.array(A12))
    h04 = np.dot(h03,h34)
    #rospy.loginfo("x = %f, y = %f, z = %f\n",h04[0][3],h04[1][3],h04[2][3])
def main():
    rospy.init_node('try', anonymous=True)
    pub = rospy.Publisher("/joint_states",JointState,queue_size = 500)
    joint = JointState()
    joint.header.stamp = rospy.Time.now()
    joint.name = ["J1_2","J2_3","J3_4","J4_5","J5_6","J6_7","J6_8"]
    joint.velocity = []
    joint.position = [0,0,0,0,0,0]
    joint.effort = []
    pub.publish(joint)
     
    while not rospy.is_shutdown():
        print("Enter input [y/n/r]:")
        key_timeout = 0.5
        key = getKey(key_timeout)
        if key == 'y':
         x = float(input('Enter the y coordinates:'))
         y = float(input('Enter the x coordinates:'))
         z = float(input('Enter the z coordinates:'))
         t1 = math.atan2(y,x)
         r1 = abs(sqrt(x*x+y*y))
         r2 = z - 0.32265
         r3 = abs(sqrt(r1*r1+r2*r2))
         temp1 = ((r3*r3)/2*0.394*r3)
         ph1 = math.acos(temp1)
         ph2 = math.atan2(r2,r1)
         temp = (r3*r3 - 0.312845)/(-0.312836)
         ph3 = math.acos(temp)
         t2 = ph2 - ph1
         t3 = 1.57 - ph3
         joint.velocity = []
         joint.position = [t1,t2,t3,0,0,0,0]
         joint.effort = []
         pub.publish(joint)
         print("hello")
         print(t1)
         print(t2)
        elif key == 'n':
          break
        else :
          print('put valid key')
main()