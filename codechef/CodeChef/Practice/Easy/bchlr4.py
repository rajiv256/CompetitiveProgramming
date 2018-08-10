

def dp(v,L,n,k) : 
	L[n] = v[n] 
	i = n  
	
	while (i >= 1 )  : 
		j = i - 1
		while (j >= i-k & j >= 1):
			if (L[j] > v[j]*L[i]):
				L[j] = v[j]*L[i] 
			j -= 1
		i -= 1 

	print L[1]
	return ; 
s = raw_input() 
s1 = s.split(" ")
n = int(s1[0]) 
k = int(s1[1])
s = raw_input()
s1 = s.split(" ")
v = [] 
v.append(0)
for i in range(n):
	v.append(int(s1[i]))

L = [] 
L.append(0)
for i in range(n) :
	L.append(10**20)
dp(v,L,n,k)
 