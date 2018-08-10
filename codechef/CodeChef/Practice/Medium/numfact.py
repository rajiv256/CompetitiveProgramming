import math
t = input()

def sieve():
	l = [0 for k in range(1000001)]
	i = 2 
	while (i <= math.sqrt(1000001)) : 
		if (l[i] == 0):
			j = 2 
			while (i*j <= 1000000):
				l[i*j] = 1 
				j += 1
		i += 1

	return l ; 

def factorise(num):
	while (num%2 == 0):
		final[2] += 1
		num /= 2
	i = 3
	while ((num > 1) & (i <= num)):
		if (ll[i] == 0):
			while (num %i == 0):
				final[i] += 1
				num = num/i 
		i += 2 


ll = sieve()
final = {}

it = 0 
while (it < t):
		
	n = input()
	a = [] 
	s = raw_input()
	s1 = s.split(" ")
	num = 1
	final = {}
	for i in range(n):
		num *= int(s1[i])
	
	for i in range(int(math.sqrt(num)+1)):
		final[i] = 0 
	factorise(num)
	result = 1
	keys = final.keys()
	for i in range(len(final)):
		result *= (final[keys[i]]+1)

	print result 

	
	it += 1
