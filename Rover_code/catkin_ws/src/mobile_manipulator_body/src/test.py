#!/usr/bin/env python3
import rospy
from geometry_msgs.msg import Twist
pub = rospy.Publisher('cmd_vel',Twist,queue_size = 10)
rospy.init_node('Arduino_pe_bhej_rha')
rate = rospy.Rate(0.125)
def publisher(a, b, c, d):
    vel = Twist()
    vel.linear.x = a#pwm1
    vel.linear.y = b#pwm2
    vel.linear.z = c#dir1
    vel.angular.x = d#dir2
    pub.publish(vel)
if __name__ ==  '__main__':
    while not rospy.is_shutdown():
        publisher(60,60,0,0)
        print("forward")
        rate.sleep()
        publisher(60,60,1,0)
        print("sleft")
        rate.sleep()
        publisher(60,60,0,1)
        print("sright")
        rate.sleep()
        if not rospy.is_shutdown():
            publisher(60,60,1,1)
            print("reverse")
            rate.sleep()
            publisher(0,60,0,0)
            print("smoothleft")
            rate.sleep()
            publisher(60,0,0,0)
            print("smoothright")
            rate.sleep()