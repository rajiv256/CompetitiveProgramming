t = input()

while(t > 0):
	n = input() 
	s = raw_input()
	s1 = s.split(" ")
	l = [] 
	for i in range(n):
		l.append(int(s1[i])) 
	print l
	c = [] 
	st = 0
	ind = 0 
	s = "/*+-"
	while (ind < n-1):
		for j in range(4):
			c.append(s[(st+j)%4])
			ind += 1
			if (ind >= n-1):
				break ;  
		st = (st+1)%4 
	

	l1 = []
	rem = [] 
	ind = 0
	for i in range(n-1):
		if (c[i] == '/'): 
			l1.append(l[i]/l[i+1])
			ind += 2
			rem.append(i)
		else:
			l1.append(l[ind])
			ind += 1
			
	print l1
	for i in range(len(rem)) :
		c.remove('/')
	print c
	l2 = []
	ind = 0 
	rem = [] 
	for i in range(len(c)):
		if (c[i] == '*'):
			l2.append(l1[i]*l1[i+1])
			ind += 2
			rem.append(i)
		else : 
			l2.append(l1[ind])
			ind += 1
	for i in range(len(rem)):
		c.remove('*')
	ans = 0 
	ans = l2[0]
	print c
	print l2
	for i in range(len(c)):
		if (c[i] == '+'):
			ans += l2[i+1]
		if (c[i] == '-'):
			ans -= l2[i+1]
	print ans 
	t -= 1 