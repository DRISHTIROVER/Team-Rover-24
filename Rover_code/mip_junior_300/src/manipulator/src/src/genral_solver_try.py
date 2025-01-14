import kinematic_lib as kb
import numpy as np
import math as m

rpy1 = [-1.5708,0,0]
rpy2 =[0,0,0]
rpy3 = [2.1511,-0.011486,1.5783]
rpy4 = [-3.1416,1.4872,0.027469]
#v = [[0.1],[0],[0]]
v = [[0.40889],[0.163407],[0.0075812]]
o2 = [[0],[0],[0.1]]
o3 = [[0],[0.2],[0]]
o4 = [[0.087723],[1.06],[0.13381]]
o5 = [[0.90889],[0.063407],[0.0075812]]


def Transform(v =[],o2 =[],rpy =[]):
	R = kb.getRmatrix(rpy)
	rt = np.linalg.inv(R)
	v21 = np.array(o2) + np.dot(rt,v)
	return v21


v = Transform(v,o5,rpy4)
v = Transform(v,o4,rpy3)
v = Transform(v,o3,rpy2)
v = Transform(v,o2,rpy1)

print(v)


