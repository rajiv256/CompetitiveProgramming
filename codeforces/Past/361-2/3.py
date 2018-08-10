m = input() 

st = 1 
en = 10**16

def solve(n):
	res = 0
	for k in range(2,int(n**(1.0/3))+2) :
		res += int(n/(k**3))
	return res ; 


def possible(st,en) : 
	while (st < en) : 
		mid = (st+en)/2 
		temp = solve(mid)
		#print st,en,mid,temp,m
		if (temp == m):
			temp1 = possible(st,mid-1)
			if (temp1 != -1):
				return temp1 ; 
			return mid ; 
			 
		if (temp < m):
			st = mid+1
		if (temp > m):
			en = mid-1

	if (st == en):
		if (solve(st)==m):
			return st ; 
		return -1 ; 
	return -1 ; 




x = possible(1,10**16)
print x 