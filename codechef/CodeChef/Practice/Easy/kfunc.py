t = input()

def fill(number):
	ll = []
	while (number != 0):
		ll.append(number%10)
		number /= 10
	
	return ll ; 


tc = 0 

while (tc < t):
	
	s = raw_input()
	s1 = s.split(" ")
	a = int(s1[0])
	d = int(s1[1])
	l = int(s1[2])
	r = int(s1[3])

	lem = a+(l-1)*d 
	rem = a+(r-1)*d 

	num = fill(lem)
	while (sum(num) >= 10):
		#print sum(num)
		num = fill(sum(num))

	result = sum(num) 
	#print lem , rem
	aar = fill (lem)
	ddr = fill(d)
	for i in range(len(ddr),len(aar)):
		ddr.append(0)
	#print result 
	#print aar,ddr
	iter = lem + d 
	while (iter <= rem):
		extra = 0 
		for i in range(len(aar)):
			#result -= aar[i]
			#result += (aar[i]+ddr[i]+extra)%10
			#print i,aar[i],ddr[i],extra
			temp = aar[i]
			aar[i] = (aar[i]+ddr[i]+extra)%10
			extra  = (temp+ddr[i]+extra)/10
			#print aar 
			##print aar,ddr
		if (extra != 0):
			aar.append(extra)
			ddr.append(0)
		
		num = aar
		summ = sum(num)
		while (summ >= 10):
			num = fill(summ)
			summ = sum(num)
		result += summ
		
		iter += d 
	print result 
	tc+=1 