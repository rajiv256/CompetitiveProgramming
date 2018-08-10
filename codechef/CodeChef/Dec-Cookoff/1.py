T = input()

def dp(a, W,dup) : 
	for i in range(len(a)+1):
		for w in range(W+1):
			dup[i].append(0)
	for i in range(len(a)+1):
		for w in range(W+1):
			if (i == 0 ):
				dup[i][W] = 0 
				continue 
			elif (W == 0):
				dup[i][W] = 0
				continue 
			elif (a[i-1] <= w) : 
				dup[i][w] = max (a[i-1]+dup[i-1][w-a[i-1]], dup[i-1][w])
			else : 
				dup[i][w] = dup[i-1][w] 
	return dup[len(a)][W] ; 


i = 0
L = []

while (i < T) :
	s = raw_input()
	s1 = s.split(" ")
	n1 = int(s1[0])
	n2 = int(s1[1])
	m = int(s1[2])
	mini = min(n1,n2)
	l = [] 
	for i in range(len(a)+1) : 
		L.append([]) 
	dup1 = L 
	for j in range(1,m+1):
		l.append(j)
	res = dp(l,mini,dup1)
	
	print n1+n2-2*res 
	i+= 1