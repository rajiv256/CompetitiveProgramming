t = input()

def solve(l,idx,n):
	if (len(l) == 0):
		return 0 ; 
	if (idx == len(l)):
		res = l[0] 
		for i in range(1,len(l)):
			res = res^l[i] 
		return res ; 
	lhs = solve(l,idx+1,n)
	temp = l[idx]
	#print l , "before"
	l.remove(l[idx])
	rhs = solve(l,idx,n)
	l.insert(idx,temp)
	#print l ,"after"
	return (lhs+rhs) ; 






it = 0
while (it < t):
	n = input()
	s = raw_input()
	s1 = s.split(" ")
	l = [] 
	for i in range(n):
		l.append(int(s1[i]))
	count = solve(l,0,n) 
	print count %  1000000007 

	it += 1 