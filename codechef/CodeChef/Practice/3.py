s = raw_input()
s1 = s.split(" ")
n = int(s1[0])
k = int(s1[1]) 

l = [] 
l.append(0)
s = raw_input()
s1 = s.split(" ")
for a in range(n):
	l.append(int(s1[a]))

def isum(l,i,k):
	res = 0 
	for j in range(1,k+1):
		res += (j**2)*l[i+j-1]
	return res ; 

for q in range(1,n-k+2):
	print isum(l,q,k),
