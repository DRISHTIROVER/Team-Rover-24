#!/usr/bin/env python3
import rospy
from geometry_msgs.msg import Twist

pub = rospy.Publisher('/cmd_vel',Twist,queue_size = 10)
rospy.init_node('Arduino_pe_bhej_rha')
rate = rospy.Rate(0.125)

def callback(data):
    rospy.loginfo("y = %f, x = %f", data.linear.x,data.angular.x)
    vx = data.linear.x
    wx = data.angular.x
    vel = Twist()
    vx_mod = abs(vx)
    if vx_mod > 20:
        if vx > 0:
            c = 0
            d = 0
        else:
            c = 1
            d = 1
        if wx > 0:
            a = vx_mod + wx
            b = vx_mod
        elif wx < 0:
            a = vx_mod
            b = vx_mod - wx
    elif -20 < vx < 20:
        if wx > 20:
            c = 0
            d = 1
            a = wx
            b = wx
        elif wx < -20:
            c = 1
            d = 0
            a = wx
            b = wx
        else:
            a = 0
            b = 0
            c = 0
            d = 0
    vel.linear.x = a#pwm1
    vel.linear.y = b#pwm2
    vel.linear.z = c#dir1
    vel.angular.x = d#dir2
    pub.publish(vel)
    
def listener():
    rospy.Subscriber("/joystick", Twist, callback)
    rospy.spin()

listener()