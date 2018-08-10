n = int(raw_input())
l = [] 
s = raw_input() 
s1 = s.split(" ")

for i in range(n) :
	l.append(int(s1[i]))
s = [] 
for i in range(n) :
	s.append(l[i])

l.sort()



d_min = { }
d_min[l[0]] = abs(l[0] - l[1]) 
d_min[l[len(l)-1]] = abs(l[len(l)-1] - l[len(l) -2]) 
for i in range(1 , len(l)-1) :
	d_min[l[i]] = min(abs(l[i] - l[i-1]) , abs(l[i]-l[i+1])) 

d_max = { }
d_max[l[0]] = abs(l[len(l)-1] - l[0])
d_max[l[len(l)-1]] = d_max[l[0]]

for i in range(1 , len(l)- 1 ) :
	d_max[l[i]] = max (abs(l[i]-l[0]),abs(l[i]-l[len(l)-1]))

for i in range(len(s)):
	print d_min[s[i]], d_max[s[i]] 
