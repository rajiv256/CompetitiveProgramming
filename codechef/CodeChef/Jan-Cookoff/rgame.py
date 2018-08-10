T = input()
it = 0 


while (it < T):	
	
	n = input()
	A = [] 
	s = raw_input()
	s1 = s.split(" ")

	for i in range(n+1):
		A.append(int(s1[i]))

	ans = 0 
	t1 = 0 
	t2 = 0 

	l = []
	for i in range(n+1):
		l.append([])
		for j in range(n+1):
			l[i].append(0)

	for i in range(n+1):
		for j in range(n+1):
			if (i < j):
				if (i == 0):
					l[i][j] = 2**max(0,n-j+i) 
				elif (i == 1):
					l[i][j] = 2**max(0,n-j+i-1)
				else :
					l[i][j] = l[1][1+j-i]
	for i in range(n+1):	
		for j in range(i+1,n+1):	
			if (i < j):
				if (i == 0):	
					if (j == i+1):
						ans += l[i][j]*A[i]*A[j]*2 
					else:
						ans += l[i][j]*A[i]*A[j]*2 
				else:
					if (j == i+1):
						ans += l[i][j]*A[i]*A[j]*2
					else:
						ans += (t2)*A[i]*A[j]*2
				
				
	ans = ans % 1000000007

	print ans 

	it += 1 