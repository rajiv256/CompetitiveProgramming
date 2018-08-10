t = input()

def tanna(n,p,q):
	if (p == 0):
		return (0,q) ; 
	if (n == 1):
		if (q < 0):
			q = -q 
			p = -p
		return (p,q) ; 
	if (n % 2 == 0):
		a1 = tanna(n/2,p,q)
		resn = 2*a1[0]*a1[1]
		resd = a1[1]**2 - a1[0]**2
		if (resd < 0):
			resd = -resd 
			resn = -resn 
		return (resn,resd) ; 
	if (n % 2 == 1):
		a1 = tanna(n/2,p,q)
		a2 = tanna((n/2)+1,p,q)
		resn = (a1[0]*a2[1]+a2[0]*a1[1])
		resd = a1[1]*a2[1] - a1[0]*a2[0]
		if (resd < 0):
			resd = -resd 
			resn = -resn
		return (resn,resd) ; 



it = 0 
while (it < t):
	s = raw_input()
	s1 = s.split(" ")
	n = int(s1[2])
	p = int(s1[0])
	q = int(s1[1])
	if (p == 0):
		print "0\n" 
		it += 1 
		continue
	l = []
	l.append(0)
	for i in range(n):
		l.append(0)
	
	l[1] = (p,q)  
	ans = tanna(n,p,q)
	a = ans[0]
	b = ans[1]
	#print a , b 
	#if (a < 0):
	#	a += 1000000007
	rem = a 

	x = 1
	t9p7 = 1000000007
	ans = 0 
	while (x >= 1 ):
		#print b, x , b*x%1000000007
		if ((t9p7*x+rem) % b == 0) :
			ans = (t9p7*x+rem)/b 
			break 
		x += 1

	print ans
	 
	it += 1 