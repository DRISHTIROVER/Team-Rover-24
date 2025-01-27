#!/usr/bin/env python3
import rospy
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

def publ(d,t1,t2):
    joint = JointState()
    joint.header.stamp = rospy.Time.now()
    joint.name = ["prismatic1","revolute1","revolute2","revolute3","EE_right","EE_left"]
    joint.velocity = []
    joint.position = [d,t1,t2,0.0,0.0,0.0]
    joint.effort = []
    pub.publish(joint)


rospy.init_node('try', anonymous=True)
pub = rospy.Publisher("/joint_states",JointState,queue_size = 500)
rospy.sleep(1.5)
publ(0.0,0.0,0.0)
runonce = 0
a = 0
b = 0
c = 0

while not rospy.is_shutdown():
    key_timeout = 0.5
    key = getKey(key_timeout)
    if runonce == 0:
        print('''    >>Press y to enter coordinates or +__+
    >>Press p to reach previous position/rewind the motion or :-)
    >>Press r to reset _
    >>Press space bar and Ctrl+C to exit :-/''')
        runonce = 1
    if key == 'y':
        y = float(input('Enter the x coordinates:'))
        x = float(input('Enter the y coordinates:'))
        z = float(input('Enter the z coordinates:'))
        if z > 0.324 or z < 0.06925 or x == 0 or y == 0:
            print("**Wrong coordinates entered**")
        else:
            runonce = 0
            temp1 = (x*x + y*y - 0.18)/0.18
            t2 = min(-math.acos(temp1),2.06)
            temp2 = 0.3*math.sin(t2)/(0.3+0.3*math.cos(t2))
            t1 = min(math.atan2(x,y) - math.atan(temp2),2.06)
            d = z  - 0.06925
            x = (t1-a)/1000
            y = (t2-b)/1000
            z = (d-c)/1000
            i = 0
            t1 = 0
            t2 = 0
            d = 0
            while i < 1000:
                rospy.sleep(0.01)
                t1 = a + x*i
                t2 = b + y*i
                d = c + z*i
                publ(d,t1,t2)
                i = i + 1
                print("t1 t2 d",t1,t2,d)

            a = t1
            b = t2
            c = d
    elif key == 'p':
        i = 0
        t1 = 0
        t2 = 0
        d = 0
        while i < 1000:
            rospy.sleep(0.01)
            t1 = a - x*i
            t2 = b - y*i
            d = c - z*i
            publ(d,t1,t2)
            i = i + 1
            
    elif key == 'r':
        x = a/1000
        y = b/1000
        z = c/1000
        i = 0
        t1 = 0
        t2 = 0
        d = 0
        while i < 1000:
            rospy.sleep(0.01)
            t1 = a - x*i
            t2 = b - y*i
            d = c - z*i
            publ(d,t1,t2)
            i = i + 1
    elif key == ' ':
        break