import math
n = input()
a = []
s = raw_input()
s1 = s.split(" ")
for i in range(len(s1)):
	a.append(int(s1[i])) 
l = []

fact = []
fact.append(1)  
for i in range(1,1000004) : 
	fact.append(fact[len(fact)-1]*i)

	
for i in range(len(a)):
	l.append(fact[a[i]]) 

primes = [True for i in range(2,fact[1000004])]

def sieve():
	for i in range(fact[1000003]):
		j = 2
		if (primes[i] == True):
			while (i*j < fact[1000003]):
				primes[i*j]= False 
				j += 1


print "came" 

def factLen(n):	
	ans = 0 
	while (n%2==0):
		ans += 1 
		n /= 2 
	for i in range(3,int(math.sqrt(n))+1):
		if (primes[i] == True):
			while (n%i == 0):
				ans += 1 
				n /= i 
	return ans ; 

res = [] 
for i in range(len(l)):
	res.append(factLen(l[i])) 

sum = 0 
for i in range(n):
	for j in range(i,n):
		subsum = 0 
		for k in range(i,j+1):
			subsum += res[k]
		if (subsum %2 == 0):
			sum += subsum 
print sum 
