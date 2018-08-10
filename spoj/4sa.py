t = input()

def get_num(l):
	res = 0 
	for j in range(len(l)):
		res *= 10 
		res += l[len(l)-j-1]
	return res ; 

def get_nearest_palindrome(n,fh,sh,frev,l):
	rev = get_num(frev) 
	fn = get_num(fh) 
	if (rev > get_num(sh)):
		if (len(l)%2 == 0):
			num = fn*(10**(len(sh))) + rev 
			return num ; 

		else :
			num = (fn*10 + l[len(l)/2] )*(10**len(sh)) + rev 
			return num ;
	else :
		if (len(l)%2 == 0):
			if (fh[len(fh)-1] == 9) : 
				fn = get_num(fh)
				fn += 1
				fl = []
				while (fn != 0):
					fl.append(fn%10)
					fn /= 10
				rev1 = get_num(fl)
				fl.reverse()
				main1 = get_num(fl)
				num = main1*(10**(len(fl))) + rev1 
				return num ; 
			else :
				fh[len(fh)-1] += 1
				frev[0] += 1 
				num = get_num(fh)*(10**(len(fh))) + get_num(frev) 
				return num ;



		else :
			if (l[len(l)/2] == 9):
				fhh = []
				fn = fn+1
				du = fn
				j = 0 
				while (du!=0):
					fhh.append(du%10)
					du /= 10
				fhh.reverse()

				num = (fn*10 )*(10**len(fhh)) + get_num(fhh) 
				return num ; 
			else : 
				num = (fn*10 + l[len(l)/2] + 1 )*(10**len(sh)) + rev 
				return num ;



i = 0 
while ( i < t ) :
	
	s = raw_input()
	n = int(s) 
	lens = len(s)
	n += 1
	dup = n  
	l = [] 
	for j in range(lens):
		l.append(dup%10)
		dup /= 10
	frev = []
	l.reverse()
	if (lens %2 == 0):
		fh = l[0:len(l)/2] 
		sh = l[len(l)/2:]
		for j in range(len(fh)):
			frev.append(fh[len(fh)-j-1])
	else:
		fh = l[0:len(l)/2 ]
		sh = l[len(l)/2+1:]
		for j in range(len(fh)):
			frev.append(fh[len(fh)-j-1])

	#print n ,fh,sh,frev,l
	print get_nearest_palindrome(n,fh,sh,frev,l)



	i += 1 
