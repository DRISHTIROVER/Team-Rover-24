#!/usr/bin/env python3
import rospy
import math
from sensor_msgs.msg import JointState

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
    if runonce == 0:
        runonce = 1
        y = float(input('Enter the x coordinates:'))
        x = float(input('Enter the y coordinates:'))
        z = float(input('Enter the z coordinates:'))
        if z > 0.324 or z < 0.06925 or x == 0 or y == 0:
            print("**Wrong coordinates entered**")
        else:
            runonce = 0
            temp1 = (x*x + y*y - 0.02)/0.02
            t2 = min(-math.acos(temp1),2.06)
            temp2 = 0.3*math.sin(t2)/(0.1+0.1*math.cos(t2))
            t1 = min(math.atan2(x,y) - math.atan(temp2),2.06)
            x = (t1-a)/1000
            y = (t2-b)/1000
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
            print("t1 t2 \n",math.degrees(t1),math.degrees(t2))
            