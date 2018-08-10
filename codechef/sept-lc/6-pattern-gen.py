NL = 27
inp = [[i] for i in range(1,NL+1)]


def dfs(s) :
	if (s == NL-1) :
		return [NL]
	ret = inp[s]
	
	lis = dfs(s+1)
	inp[s+1] = lis 
	# print lis ; 
	for k in lis : 
		if k in ret : 
			ret.remove(k)
		else : 
			ret.append(k)
	return ret  

def rev(s) :
	str = "" 
	l = len(s)-1 
	while (l >= 0):
		str += s[l:l+1]
		l -=1 
	return str 

lev = NL-1
num = NL

lpre = ["" for i in range(NL)]

for i in range(1,64) : 
		s = "" 
		inp[0] = dfs(0)

		for j in range(NL): 
			if (num in inp[j]):
				lpre[j] = lpre[j]+"1"
			else :
				lpre[j] = lpre[j] + "0"
i = NL-1 
for k in lpre :
	print  k,i
	i -= 1  