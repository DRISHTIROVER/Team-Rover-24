from math import atan,acos,asin,pi,sqrt,cos,sin,log
import numpy as np

class Joint:
	def __init__(self,name,number,type_):
		self.jointNumber = number
		self.jointName = name
		self.jointType = type_
		
	def param(self,xyz,rpy,axis):
		self.co_ordinates = xyz
		self.orientation = rpy[0]
		self.axis = axis
		
	def tree(self,parent,child):
		self.parent = parent
		self.child = child
		
	def limit(self,lower,upper,effort,velocity):
		self.upper = upper
		self.lower = lower
		self.effort = effort
		self.velocity = velocity

def getinfo(type_,jointnumber,info,jointarray=[]):		
	array = []
	flag = False
	for i in range(30):
		try:
			data = getdata(type_,jointnumber,i,info,jointarray)
		except:
			flag = True
		finally:
			if flag == False:
				array.append(data)
			flag = False
	return array
	
def generatemessage(object):
	message = f"\nJoint {object.jointNumber} found, named as {object.jointName}.\nParent: {object.parent}\nChild : {object.child}\nType  : {object.jointType}\nXYZ   : {object.co_ordinates}\nRPY   : {object.orientation}\nAxis  : {object.axis}"
	return message
	
def getdata(type_,num,nodenum,attri,jointarray = []):
	strlist = list((jointarray[num].childNodes[nodenum].getAttribute(attri)).split(" "))
	if type_ == "string":
		return strlist
	else:
		outlist = [float(numeric_string) for numeric_string in strlist]
		return outlist

def rot_x(theta):
    matrix = np.array([[1,0,0],[0,cos(theta),-sin(theta)],[0,sin(theta), cos(theta)]])
    return matrix

def rot_y(theta):
    matrix = np.array([[cos(theta), 0, sin(theta)],[0,1,0],[-sin(theta),0,cos(theta)]])
    return matrix

def rot_z(theta):
    matrix = np.array([[cos(theta),-sin(theta),0],[sin(theta),cos(theta) ,0],[0,0,1]])
    return matrix



def getRmatrix(rpy = []):
	rollmatrix = rot_x(rpy[0])
	pitchmatrix = rot_y(rpy[1])
	yawmatrix = rot_z(rpy[2])
	rotationmatrix = np.matmul(yawmatrix,pitchmatrix,rollmatrix)
	print(rotationmatrix)
	return rotationmatrix
	
def getHomogenous(joint,jointvalue):
	d = joint.co_ordinates
	if joint.jointType == "revolute":
		[r,p,y] = joint.orientation
		r = getRmatrix([r,p,y])
		axis = (joint.axis).index(1)
		if axis == 0:
			jointmatrix = rot_x(jointvalue)
		elif axis == 1:
			jointmatrix = rot_y(jointvalue)
		elif axis == 2:
			jointmatrix = rot_z(jointvalue)
		else:
			jointmatrix = np.identity(3,dtype = float)
			print("Incorrect index found using Identity matrix as default")
		rmatrix = np.dot(jointmatrix,r)
		if np.shape(rmatrix) != (3,3):
			print("Error in Rotation matrix")
	
	elif joint.jointType == "prismatic":
		rmatrix = np.identity(3,dtype = float)
		axis = (joint.axis).index(1)
		d[axis] += jointvalue
	
	elif joint.jointType == "fixed":
		rmatrix = np.identity(3,dtype = float)
		
	hmatrix = np.zeros([4,4],dtype = float)
		
	for i in range(0,3):
		for j in range(0,3):
			hmatrix[i][j] = rmatrix[i][j]
		hmatrix[3][i] = 0
		hmatrix[i][3] = d[i]
	hmatrix[3][3] = 1
	return hmatrix
	
def settlerange(error_value,matrix = []):
	for i in range(0,len(matrix)):
		for j in range(0,len(matrix[0])):
			if matrix[i][j] <= error_value:
				matrix[i][j] = 0 
	return matrix
	
	
