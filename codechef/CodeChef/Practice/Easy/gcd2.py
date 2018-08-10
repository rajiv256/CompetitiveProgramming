t = input()
 

def gcd(a,b) :
 	if (b == 0):
 		return a ;
 	else : 
 		return gcd(b,a%b) ; 

i = 0 
while (i < t ):
 	s = raw_input()
 	s1 = s.split(" ")
 	a = int(s1[0])
 	b = int(s1[1])
 	print gcd(b,a) 
 	i += 1 