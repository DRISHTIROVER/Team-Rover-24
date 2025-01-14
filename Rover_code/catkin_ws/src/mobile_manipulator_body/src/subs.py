#!/usr/bin/env python3
import rospy
from geometry_msgs.msg import Twist

def callback(data):
    rospy.loginfo("x = %f, y = %f, z = %f, t = %f \n", data.linear.x, data.linear.y, data.linear.z, data.angular.x)
    
def listener():

    rospy.init_node('hearer', anonymous=True)

    rospy.Subscriber("cmd_vel", Twist, callback)  #chatter---topic

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

listener()