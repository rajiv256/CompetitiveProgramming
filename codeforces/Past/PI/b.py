n = int(raw_input())
cap = 0 
ins  = 0 
inn = []
out = [] 
def notIn( l  , a ) : 
	for k in l :
		if ( k==a ) :
			return False
	return True

for i in range(n) :
	s = raw_input()
	s1 = s.split(" ")
	
	if (s1[0] == '+') :
		if (notIn(out,int(s1[1]))) :
			ins +=1 
			if ( ins > cap ):
				cap += 1 
			inn.append(int(s1[1]))
		else:
			ins += 1
			inn.append(int(s1[1]))
			
			
	if (s1[0] == '-'):
		if (ins == 0):	
			if (notIn(inn , int(s1[1]))):
				cap += 1
				out.append(int(s1[1]))
		else :
			if (notIn (inn, int(s1[1]))):
				cap += 1 
				ins  -= 1
				out.append(int(s1[1]))
				
			else:
				out.append(int(s1[1]))
				ins -= 1 
				
	
print max (cap , ins) 
