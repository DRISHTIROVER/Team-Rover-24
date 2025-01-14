#!/usr/bin/env python3
# Description:
# - Subscribes to real-time streaming video from your built-in webcam.
#
# Author:
# - Addison Sears-Collins
# - https://automaticaddison.com
 
# Import the necessary libraries
from _future_ import print_function
import rospy,time # Python library for ROS
from sensor_msgs.msg import Image # Image is the message type
from cv_bridge import CvBridge # Package to convert between ROS and OpenCV Images
import cv2 # OpenCV library
import os
count = 0  
def receive_message():
  # os.chdir(r'home/niyati/vihaan_rover/src/cv_basics/src')
  # Tells rospy the name of the node.
  # Anonymous = True makes sure the node has a unique name. Random
  # numbers are added to the end of the name. 
  
  # Node is subscribing to the video_frames topic
  
  rospy.init_node('video_sub_py', anonymous=True)
  rospy.Subscriber('/camera/image_raw', Image, callback)
    
  # spin() simply keeps python from exiting until this node is stopped
  rospy.spin()
  
  # Close down the video stream when done
  cv2.destroyAllWindows()

def callback(data):
      
  global count  
  current = rospy.get_time()
  # Used to convert between ROS and OpenCV images
  br = CvBridge()
  fourcc = cv2.VideoWriter_fourcc('M','J','P','G')
  current_frame = br.imgmsg_to_cv2(data)
  writer= cv2.VideoWriter('/home/niyati/vihaan_rover/src/cv_basics/src/videos/1/basicvideo.avi', fourcc, 20,(640,480))
  writer.write(current_frame)
  # Output debugging information to the terminal
  rospy.loginfo("receiving video frame")
  cv2.imwrite('/home/niyati/vihaan_rover/src/cv_basics/src/Images/1/image'+str(count)+'.png', current_frame)
  print("Creating file..."+str(count))
  count = count + 1
  last_time = current
  time.sleep(1)
  # Convert ROS Image message to OpenCV image
  return count,current
  
  
if _name_ == '_main_':
  receive_message()