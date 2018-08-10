import math
s = raw_input()
s1 = s.split(" ")
ax = Float(s1[0])
ay = FLoat(s1[1])
bx = Float(s1[2])
by = FLoat(s1[3])
rx = Float(s1[4])
ry = Float(s1[5])

n = input()
l = []
for i in range(n):
	s = raw_input()
	s1 = s.split(" ")
	l.append((Float(s1[0]),Float(s1[1]))


da = [(d,i) for i in range(n) d=math.sqrt((ax-l[i][0])**2+(ay-l[i][1])**2)]
db = [(d,i) for i in range(n) d=math.sqrt((ax-l[i][0])**2+(ay-l[i][1])**2)]
r =  [(d,i) for i in range(n) d=math.sqrt((ax-l[i][0])**2+(ay-l[i][1])**2)]

Float dist = 0 
for i in range(n):
	dist += 2*r[i] 
if (da[0][1] != db[0][1]):
		dist -= r[da[0][1]][0] 
		dist -= r[db[0][1]][0]  
		dist += da[0][0] ; 
		dist += db[0][1] ; 
	
else:
	if (da[0][0]+db[1][0] > da[1][0]+db[0][0]):
		dist -= r[da[1][1]][0]
		dist -= r[db[0][1]][0]
		dist += da[1][1]+db[0][0] 
	
	elif (da[0][0]+db[1][0] < da[1][0]+db[0][0]){
		dist -= r[db[0][1]][0]
		dist -= r[da[1][1]][0] 
		dist += da[0][0]+db[1][0]
	
	else:
		dist -= max(r[db[0][1]][0]+r[da[1][1]][0],r[da[1][1]][0]+r[db[0][1]][0] )
		dist += da[0][0]+db[1][0]
print dist 
	
