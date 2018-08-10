s = raw_input()
s1 = s.split(" ")
n = int(s1[0]) 
k = int(s1[1])
l = [] 
s = raw_input()
s1 = s.split(" ")

for i in range(n) : 
	l.append(int(s1[i]))

def check (l , i , k ) :
	first = i
	second = -1 
	third  = -1  
	for j in range(len(l)):
		if ( j != first ):
			if (l[j] == k*l[i] ):
				second = j 
				break 
	for v in range(len(l)):
		if ( v != second):
			if ( v != first) :
				if (l[v] == k* l[first]*k) :
					third = v
					break	 
	print first , second , third
	if (first != -1 & second != -1 & third != -1):
		l[first] = -1
		l[second] = -1
		l[third] = -1
		
	return (first,second,third)


t = [] 

def notIn (t , p ) :
	for k in t :
		if (p == k ) :
			return False
	return True 

def count ( p ) :
	c = 0
	for k in l :
		if (p == k ):
			c +=1 
	return c

res = 0 
d = []
for k in l :	
	d.append(k)

for i  in range(len(l)) :
	tup = check (l , i , k )
	if (tup[1] != -1 & tup[2] != -1) :
		 l[tup[0]] = -1
		 l[tup[1]] = -1
		 l[tup[2]] = -1
		 c1 = 1+count( l[i])
		 c2 = 1+count(l[i]*k)
		 c3 = 1+count ( l[i]*k*k)
		 print c1 , c2 , c3
		 if (notIn(t , (c1,c2,c3))):	
		 	t.append((c1,c2,c3))
		 	res += c1 * c2 * c3 
	for j in range(len(l)):
		l[i] = d[i]
print res
