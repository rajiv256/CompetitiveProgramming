s = raw_input()
s2 = s.split()
n = int(s2[0])
q = int(s2[1])

st = raw_input()

def res(string , k , l, r ) :
	li = []
	for j in range(l,r+1):
		li.append(st[j])
	li.sort()
	lis = list(string)
	
	if ( k== 1):	
		for i in range(l,r+1) : 
			lis[i] = li[i-l]
		string = ''.join(lis)
		return string
	if ( k== 0):	
		for i in range(l,r+1):
			lis[i] = li[len(li)-i+l - 1]
		string = ''.join(lis)
		return string

for i in range(q) : 
	s = raw_input()
	s2 = s.split()
	l = int(s2[0])
	r = int(s2[1])
	k = int(s2[2])
	st = res(st , k , l-1 , r-1)

print st

