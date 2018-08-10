t = input()
j = 0 

def isAnag(s1,s2):
	count = 0 
	if (len(s1)!=len(s2)):
		return 0 
	else: 
		count = 0 
		for i in range(len(s1)):
			count += int(s1[i]-s2[i])
		if (count == 0):
			return 1 
		else:
			return 0 

def findMatch(s1 , s2):
	l1 = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
	l2 = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
	
	for i in range(len(s1)):
		for j in range(len(s2)):
					

while ( j < t ) : 
	s1 = raw_input()
	s2 = raw_input()
	
	s = raw_input()
	q = s.split(" ")
	
	de  = int(q[0])
	ins = int(q[1])
	rep = int(q[2])
	
	if (isAnag(s1,s2)) : 
		print "0"
		break  
	else : 
		match = findMatch(s1 , s2) 
		
	
	
	
	
	
	
	
	j += 1
