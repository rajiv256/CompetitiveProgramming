s = raw_input()
s1 = s.split(" ")

a = int(s1[0])
b = int(s1[1])
N = int(s1[2])


t = []
t.append(a)
t.append(b)
for i in range(2,N):
	t.append(0)
for i in range(2,N):
	t[i] = t[i-1]**2 + t[i-2]

print t[N-1]
