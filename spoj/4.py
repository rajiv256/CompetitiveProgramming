t = input()

def get2(n,l1,l2,lens):
	#print n
	t1 = n/(10**(lens-1))
	t2 = n % 10 
	#print t1,t2 
	if (t1 == t2) :
		l1.append(t1)
		l2.insert(0,t2) 
		n = n % (10**(lens-1))
		n = n / 10 
		return n ; 
	if (t1 > t2):
		t2 = t1 
		l1.append(t1)
		l2.insert(0,t1)
		#print l1,l2	
		n = n % (10**(lens-1))
		n = n / 10 
		return n ;
	if (t1 < t2):
		n = n + 10 - t2 
		#print n 
		return (get2(n,l1,l2,lens)) ; 


def get2()





res = 0
j = 0
ll = [] 
for i in range(t):
	sa = raw_input()
	ll.append(sa)
while (j < t):
	#print j,t
	s = ll[j]
	n = int(s)
	lens = len(s)
	l1 = []
	l2 = [] 
	n += 1 
	while (lens != 0):
		if (lens == 1):
			#print n
			l2.insert(0,n)
			break
		#print n,"@@" 
		n = get2(n,l1,l2,lens)
		lens -= 2 
	l = []
	l += l1 
	l += l2 
	k = len(l)
	for i in range(len(l)):
		res *= 10 
		res += l[k-i-1]
	print res
	res = 0  
	j+=1