import math 
n = input()

lx = [] 
ly = [] 
it = 0 
while (it < n ):	
	s = raw_input()
	s1 = s.split(" ")
	a = int(s1[0])
	b = int(s1[1])
	if (a == 0):
        ly.append(b)
    else :
        lx.append(a)
     
	it += 1 
minx = 10000000000
maxx = -10000000000
miny = 10000000000
maxy = -10000000000
for i in range(len(lx)):
    minx = min(minx,lx[i])
for i in range(len(lx)):
    maxx = max(maxx,lx[i])
for i in range(len(ly)):
    miny = min(miny,ly[i])
for i in range(len(ly)):
    maxy = min(maxy,ly[i])


fx = []
fy = []
fx.append(minx) 
fx.append(maxx)
fy.append(miny)
fy.append(maxy)

maxi = 0.00000000000 

for i in range(2):	
	for j in range(2) : 
		maxi = max(maxi,math.sqrt(fx[i]**2+fy[j]**2))
maxi = max(maxi,fx[1]-fx[0])
maxi = max(maxi,fy[1]-fy[0])

print '%.12f'  %maxi 