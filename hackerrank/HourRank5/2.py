t = input()
a = []
s = raw_input(" ")
s1 = s.split(" ")
a.append(0)
for i in range(len(s1)):
	a.append(int(s1[i]))

def result(N):
	if (N == 1):
		return 29*a[1]
	ans = 0 
	t1 = result(N-1) 
	ans += 4*t1 
	ans += a[N] 
	ans += 4*a[N] 
	
