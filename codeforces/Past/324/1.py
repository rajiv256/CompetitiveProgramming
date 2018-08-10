s = raw_input() 
s1 = s.split() 
n = int(s1[0])
t = int (s1[1])

i = 0
hnum = 0 
while (i < n):
	hnum = hnum*10 
	hnum += 1 
	i += 1 

hnum *= 9 ; 
lnum = 10**(n-1) 
diff = hnum - lnum + 1 
if (hnum/t == lnum/t):
	print -1
else :
	print (hnum - hnum%t) 
