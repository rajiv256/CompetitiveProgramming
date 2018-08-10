f1 = open("f1",'r')
f2 = open("f2",'r')

l = f1.readlines() 

lsub = f2.readlines() 

y1n2 = '' 
y2n1 = ''

for sl in l : 
	flag = False 
	for slsub in lsub : 
		if (sl == slsub):
			flag = True
			break 
	if (flag == False):
		y1n2 += sl + "\n" 

for slsub in lsub : 
	flag = False 
	for sl in l : 
		if (sl == slsub):
			flag = True
			break 
	if (flag == False):
		y2n1 += slsub + "\n" 

outy1n2 = open("y1n2","w+")
outy2n1 = open("y2n1","w+")

outy1n2.write(y1n2)
outy2n1.write(y2n1)