import math 

t = input()

i = 0
while (i < t):
	n = input()
	p1 = 5*n*n + 4 
	p2 = 5*n*n - 4 
	sqp1 = math.sqrt(p1)
	sqp2 = math.sqrt(p2) 

	if (sqp1 == int(sqp1)):
		print "YES"
		i += 1
		continue
	if (sqp2 == int(sqp2)):
		print "YES"
		i += 1 
		continue
	print "NO"
	i += 1