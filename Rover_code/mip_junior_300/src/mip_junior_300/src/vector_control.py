#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist
import cmath
import time
def callback(msg):
  rospy.init_node('motor',10)
  pub = rospy.Publisher('cmd_vel',Twist,10)
  drive = Twist()
  r1 = msg.linear.y
  r2 = msg.linear.z
  r3 = msg.angular.y
  ohm = 2*cmath.phase(complex (r1 * 0.707, -r1 * 0.707) + complex(r3 * 0.707, r3 * 0.707) +   complex (0, 0))
  k = abs(((r1 - r3) / (r1 + r3)) * 16.667 * 3.5)
  if r2 < 10:
      drive.linear.x = 0
      drive.linear.y = 1
      drive.angular.x = 0
      drive.linear.y = 1
      pub.publish(drive)
      time.sleep(1) 
      if r1 > r3:
       drive.linear.x = 0
       drive.angular.x = 0
       drive.linear.y = 0
       drive.angular.y = 1
       pub.publish(drive)
       time.sleep(1.5) 
      else:
       drive.linear.x = 0
       drive.angular.x = 0
       drive.linear.y = 1
       drive.angular.y = 0
       pub.publish(drive)
       time.sleep(1.5) 
  elif(ohm >= 0 and ohm < 60):
       drive.linear.x = k * cmath.sin(ohm)
       drive.angular.x = k * cmath.sin(ohm)
       drive.linear.y = 0
       drive.angular.y = 0
       pub.publish(drive)
  elif(ohm >= 60):
       drive.linear.x = k * cmath.sin(ohm)
       drive.angular.x = k * cmath.sin(ohm)
       drive.linear.y = 0
       drive.angular.y = 1
       pub.publish(drive)
  elif(ohm < 0 and ohm > -60):
       drive.linear.x = k * cmath.sin(ohm)
       drive.angular.x = k * cmath.sin(ohm)
       drive.linear.y = 0
       drive.angular.y = 0
       pub.publish(drive)
  elif(ohm <= -60):
       drive.linear.x = k * cmath.sin(ohm)
       drive.angular.x = k * cmath.sin(ohm)
       drive.linear.y = 1
       drive.angular.y = 0
       pub.publish(drive)

def listener():

    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber('chatter', Twist, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

listener()