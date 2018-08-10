s = raw_input()
t = int(s)
i = 0 

def ways(n):
	tw = 0 
	if ( n == 1):
		return 1
	
	for i in range(1,n+1):
		
		if ( i == 1):
			tw += ways(n-1)
			tw += 2
			continue
		if ( i == n):
			tw += ways(n-1)
			tw += 2
			continue
		else :
			tw += ways(i-1)
			tw += ways(n-i)
			tw += 1
	return tw



while (i < t ):
	
	n =int(raw_input())
	wa = 2**(n-1)
	
	wj = ways(n)
	
	print (wj-wa)%1000000007
	
	
	
	
	
	
	i+= 1
