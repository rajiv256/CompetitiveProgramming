import math 
t = input()

it = 0 
while (it < t): 
	n = input()
	flag = 0
	sqt = int(math.sqrt(n))
	
	for m in range(1,sqt):
		nn = n - m**2 
		if (nn <= 0):
			continue
		
		bb = math.sqrt(nn)
		if (bb == int(bb)) : 
			if ((2*m*bb <= n-1) & (2*m*bb >= 1)):
				print "YES"
				flag = 1 
				break
			elif ((abs(nn-m**2) <= n-1) & (abs(nn-m**2) >= 1)):
				print "YES"
				flag = 1 
				break
			else :
				continue 
	if (flag == 0):
		print "NO"


	it += 1