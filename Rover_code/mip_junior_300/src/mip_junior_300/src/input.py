#!/usr/bin/env python3
import rospy
import numpy as np
from sensor_msgs.msg import JointState
import sys, select, termios, tty

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
    h04 = np.dot(h03,h34)
    #rospy.loginfo("x = %f, y = %f, z = %f\n",h04[0][3],h04[1][3],h04[2][3])
def getKey(key_timeout):
    settings = termios.tcgetattr(sys.stdin)
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], key_timeout)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

def main():
    rospy.init_node('try', anonymous=True)
    pub = rospy.Publisher("/joint_states",JointState,queue_size = 500)
    joint = JointState()
    joint.header.stamp = rospy.Time.now()
    joint.name = ["prismatic1","revolute1","revolute2","revolute3","EE_right","EE_left"]
    joint.velocity = []
    joint.position = [0,0,0,0,0,0]
    joint.effort = []
    pub.publish(joint)
    t1 = int(input('Enter angle for revolute1:'))
    t2 = 0#int(input('Enter angle for revolute2:'))
    d = 0#float(input('Enter angle for hieght:'))
    t3 = 0#int(input('Enter angle for revolute3:'))
    t1=(t1/180)*np.pi
    t2=(t2/180)*np.pi
    t3=(t3/180)*np.pi   
    while not rospy.is_shutdown():
        x = getKey(0.5)
        if x == "i":
            print('enter t1')
            t1 =getKey(100)
            print(t1)
            joint.velocity = []
            joint.position = [d,t1,t2,t3,0,0]
            joint.effort = []
            pub.publish(joint)
            rospy.sleep

if __name__ == '__main__':
    main()