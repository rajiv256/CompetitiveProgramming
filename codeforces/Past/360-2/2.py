n = input()

l = [] 

def fill(l,diff,nd,idx,nod):
	if (nd==0):
		return ; 
	x = 10**(nd-1)
	if (diff < x):
		return fill(l,diff,nd-1,idx+1,nod) ; 
	if (diff == x):
		while (nd >= 0):
			l[idx] = 9 
			l[nod-idx-1] = 9
			idx += 1
			nd-= 1

		return ; 
	if (diff > x) :
		



nd = 0 
while ((10**nd)-1  < n):
	nd += 1

if (10**nd-1 == n):
	s = "" 
	for i in range(2*nd):
		s += "9"
	print s 
else :
	diff = n-(10**(nd-1) -1)
	nod = 2*nd 

	for i in range(nod):
		l.append(0) 
	l[0] = 1
	l[nod-1] = 1 
	fill (l,diff,nd,0,nod)
	ans = 0
	for i in range(len(l)):
		ans += l[i] 
		ans *= 10 
	print ans/10