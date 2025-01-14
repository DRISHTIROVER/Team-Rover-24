#!/usr/bin/env python3
import devlib as dev
from math import pi
class Joint:
    def __init__(self,type_of_joint,t_matrix,r_matrix,axis):
        self.coordinate = t_matrix
        self.euler = r_matrix
        self.type = type_of_joint
        self.axis = axis
    
    def rotate_frame(r,p,y):
        dev.rot_x(r)
    
    def transform(source_frame,target_frame):
        r = target_frame.euler
        
if __name__=="__main__":
    rev1 = Joint("revolute",[0,0,0.1],[1.57,0,0],[0,1,0])
    prism2 = Joint("prismatic",[0,0.2,0],[0,0,0],[0,1,0])
    rev3 = Joint("revolute",[0.0877,1.06,0.1338],[-2.1511,0.011486,-1.5783],[0,0,1])
    rev4 = Joint("revolute",[0.9089,0.0634,0.00758],[3.1416,-1.4872,-0.02747],[0 1 0])
    
    
    