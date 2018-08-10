import math
n = input()

s = raw_input()
s1 = s.split(" ")
num = 1 
l = [] 
d = {}

def power(a , b , MOD):
	a%= MOD
	if (b == 0):
		return 1 ; 
	if (b%2==0):
		return power(a*a,b/2,MOD)%MOD ; 
	else :
		return a*power(a*a, b/2, MOD) %MOD ; 




for i in range(len(s1)):
	a = int(s1[i])
	l.append(a)
	if (a in d.keys()):
		d[a] += 1 
	else : 
		d[a] = 1 


ps = list(set(l))	
ans = 1 
#print ps
prod = 1 
for u in d.keys():
	prod *= d[u]+1
	
#print prod

for i in range(len(ps)) : 
	k = ps[i]
	temp = prod/(d[k]+1)
	
	#print temp
	t1 = (d[k]*(d[k]+1))/2 
	#print "t1",t1

	t2 = (t1*temp)%1000000007
	#print "t2",t2
	MOD = 1000000007
	aaa = power(k,t2,MOD)
	#print "aaa",aaa 
	ans = ans*aaa  
	#print "ans",ans
	
print ans%1000000007	 

