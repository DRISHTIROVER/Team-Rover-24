import cv2
from cv_bridge import CvBridge
import rospy
from sensor_msgs.msg import Image
import numpy as np
import time
import os   
fourcc=cv2.VideoWriter_fourcc(*'XVID')
mainfolder='video'
myFolders = os.listdir(mainfolder)
num=1
count = 0

for folder in myFolders :
        if count==0:
            global videopath
            videopath = mainfolder+'/'+folder #path = video/1
            print(videopath)
            myList = os.listdir(videopath)
            if(len(myList)==0):
                count = 1
                out=cv2.VideoWriter(videopath+'/'+'1'+'.mp4',fourcc,20.0,(640,480))
                time.sleep(0.1)
                break

def callback(data):
    global videopath
    global out
    br = CvBridge()


    rospy.loginfo("receiving video frame")
    current_frame = br.imgmsg_to_cv2(data)
    
    out.write(current_frame)
    rospy.loginfo("frame_written")
    cv2.imshow('output',current_frame)
    cv2.waitKey(1)


def listener():
    rospy.init_node("listener", anonymous=True)
    rospy.Subscriber("webcam", Image, callback)

    rospy.spin()

    cv2.destroyAllWindows()


if __name__ == "__main__":
    listener()