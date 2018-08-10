s = raw_input()
s1 = s.split(" ")
n = int(s1[0])
m = int(s1[1])

l = []
for i in range(n):
	l.append([]) 
print l 
for i in range(n):
	s = raw_input()
	for j in range(m) :
		l[i].append(s[j])
count = 4
print l  
s = ""
s = s+l[0][0]
print s 
def checkPal(s):
	for j in range(len(s)/2):
		if (s[j] != s[len(s)-j-1]) :
			return False 
	return True 


def dfs (s ,i , j ):
	print i , j 
	if (i == n-1 & j  == m-1):
		if (checkPal(s)):
			count+=1 
		s = ""
		return count 
	if (i+1 > n-1 | j+1 > m-1):
		s = ""
		return 0 
	if (i+1 <= n-1 & j <= m-1):
		k = dfs(s+l[i+1][j],i+1,j)
	elif (i+1 <= n-1 & j > m-1):
		k = 0 
	if (i <= n-1 & j+1 <= m-1):
		l = dfs(s+l[i][j+1],i,j+1)
	elif(i > n-1 & j+1 <= m-1) :
		l = 0 
    return (k+l)

print dfs(s , 0 , 0 )
		
