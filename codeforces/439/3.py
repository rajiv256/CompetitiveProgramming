
fact = [1 for i in range(0,5003)]
for i in range(1,5003) :
	fact[i] = i*fact[i-1] 

comb = []
for i in range(5003):
	comb.append([])

for i in range(5003):
	print i
	for j in range(5003):


		comb[i].append(1)


def power(a,x) :
	if x == 0 :
		return 1 
	temp = power(a,x/2)
	temp *= temp 
	temp %= 998244353
	if x%2==0 :
		return temp
	else :
		return (a*temp)%998244353 

def ncr(n,r) :
	if (n < r) :
		return 0
	if (n == 0) | (r==0) :
		return 1 
	den = fact[n-r]*fact[r] 
	return fact[n]/den 

for i in range(5003):
	print i 
	for j in range(5003):
		
		comb[i][j] = ncr(i,j)



def each(x,y) : 
	m = min(x,y)
	M = max(x,y)
	ret = 0
	for i in range(0,m+1) : 
		
		ret += comb[M][i]*comb[m][i]*fact[i] 
	

	#sprint ret 
	return ret 


s = raw_input()
splits = s.split(" ") 
a = int(splits[0])
b = int(splits[1]) 
c = int(splits[2]) 

ans = each(a,b)*each(b,c)*each(c,a)


ans %= 998244353 

print ans