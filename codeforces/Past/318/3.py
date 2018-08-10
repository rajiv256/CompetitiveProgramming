n = input()
s = raw_input()
s1= s.split(" ")
l = [] 
for i in range(n):
	l.append(int(s1[i])) 







for i in range(n):
	
	while (l[i]%2 == 0):
		l[i] /= 2 
	while (l[i]%3 == 0):
		l[i]/= 3
	
	
c = l[0]
flag = 0 
 
for i in range(1,n):
	if (c != l[i]):
		print "No"
		flag = 1
		break 
if (flag == 0 ):
	print "Yes"
	
	


