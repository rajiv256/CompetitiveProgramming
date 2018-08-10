import math 
t = input()

def dist(t1,t2):
	return (t1[0]-t2[0])**2 + (t1[1]-t2[1])**2 ; 

def iss(a,b,c) :
	return ((b[0]-a[0])*(c[1]-a[1]) > (c[0]-a[0])*(b[1]-a[1])) ; 
	

while (t != 0):

	maxdist = 0.0 
	
	n = input()
	if (n == 4):
		l = [] 
		while (n != 0):
			s = raw_input()
			s1 = s.split(" ")
			ll = [] 
			ll.append(int(s1[0]))
			ll.append(int(s1[1]))
			l.append(ll)
			n -= 1 
		# 0 1     2 3 
		d1 = iss(l[0],l[2],l[3])
		d2 = iss(l[1],l[2],l[3])
		d3 = iss(l[2],l[0],l[1])
		d4 = iss(l[3],l[0],l[1])
		if ((d1 == d2) | (d3 == d4)):
			temp1 = dist(l[0],l[1])
			temp2 = dist(l[2],l[3])
			maxdist = max(maxdist,max(temp1,temp2))
		# 0 1     2 3 
		d1 = iss(l[0],l[2],l[3])
		d2 = iss(l[1],l[2],l[3])
		d3 = iss(l[2],l[0],l[1])
		d4 = iss(l[3],l[0],l[1])
		if ((d1 == d2) | (d3 == d4)):
			temp1 = dist(l[0],l[1])
			temp2 = dist(l[2],l[3])
			maxdist = max(maxdist,max(temp1,temp2))
		
		# 0 3    1 2 
		d1 = iss(l[0],l[1],l[2])
		d2 = iss(l[3],l[1],l[2])
		d3 = iss(l[1],l[0],l[3])
		d4 = iss(l[2],l[0],l[3])
		if ((d1 == d2) | (d3 == d4)) : 
			temp1 = dist(l[0],l[3])
			temp2 = dist(l[1],l[2])
			maxdist = max(maxdist,max(temp1,temp2))
		
		print math.sqrt(maxdist)		
		t-=1
		continue		
		 


	l = []
	while (n!= 0):
		s = raw_input()
		s1 = s.split(" ")
		ll = []
		ll.append(int(s1[0]))
		ll.append(int(s1[1]))
		for j in range(len(l)):
			temp = dist(ll,l[j])
			if (maxdist < temp):	
				maxdist = temp 
		n -= 1 
		l.append(ll)
	print math.sqrt(maxdist) 
	t-= 1
		