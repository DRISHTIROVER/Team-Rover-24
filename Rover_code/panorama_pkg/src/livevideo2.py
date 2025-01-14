import numpy as np
import cv2
import os
import time

cap=cv2.VideoCapture(0)
fourcc=cv2.VideoWriter_fourcc(*'XVID')

mainfolder='video'
myFolders = os.listdir(mainfolder)
num=1
for folder in myFolders:
    videopath = mainfolder+'/'+folder #path = video/1
    print(videopath)
    myList = os.listdir(videopath)
    if(len(myList)==0):
        out=cv2.VideoWriter(videopath+'/'+'1'+'.mp4',fourcc,20.0,(640,480))
        time.sleep(0.1)
        break


while(cap.isOpened()):
    ret,frame=cap.read()
    if(ret==True):
        out.write(frame)
        cv2.imshow('output',frame)
        if(cv2.waitKey(1) & 0xFF == ord('q')):
            break
    
    else:
        break
cap.release()
cv2.destryAllWindows()