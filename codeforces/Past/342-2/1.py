n = input()
a = input()
b = input()
c = input() 
ans = 0 

if (a <= b-c):
	ans = (n-a)/a
	print ans+1
else :
	if (a < b):	
		ans = (n-a)/(b-c)
		print ans+1 
	else :
		ans = (n-b)/(b-c)
		print ans+1
	