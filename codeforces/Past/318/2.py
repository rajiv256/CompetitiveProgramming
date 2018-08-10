s = raw_input() 
s1 = s.split(" ")
n = int(s1[0])
m = int(s1[1])

l = [] 
for i in range(n) : 
	l.append([]) 

for i in range(n) :
	for j in range(m):
		l[i].append(0)

recog = [] 
for i in range(n):
	recog.append(0)

for i in range(m):
	s = raw_input() 
	s1= s.split(" ")
	p = int(s1[0])
	q = int(s1[1])
	l[p-1][q-1] = 1 
	l[q-1][p-1] = 1 
	recog[p-1] += 1
	recog[q-1] += 1 

rec = 1000000
print l 
print recog




						
print rec 
