s = input()
n = int(s)
s1 = raw_input()
l1 = s1.split(" ")
l = []
for i in l1 :
	l.append(int(i))

d = { }
def getCount (l , a ) :
	count = 0 
	for i in l :
		if (a == i ) :
			count+=1 
	return count
	
for i in l :
	d[i] = getCount(l,i) 


beauty = -1
for i in d.values() :
	if (beauty < i ) :
		beauty = i 

def getRange (l , a ):
	k = 0 
	m = 0 
	for i in range(len(l)):
		if (l[i] ==a ):
			k = i
			break
	for i in range(len(l)):
		if (l[len(l)-i-1] == a ):
			m = i	
			break
	return m - k 
def getTuple (l, a ) :
	k = 0 
	m = 0 
	for i in range(len(l)):
		if (l[i] ==a ):
			k = i
			break
	for i in range(len(l)):
		if (l[len(l)-i-1] == a ):
			m = len(l)-i-1
			break	
	return (k+1,m+1)

	
list = [] 
mini = 1000000

for i in d.keys() :
	if (d[i] == beauty) :
		t = getTuple(l,i) 
		ra = getRange (l,i)
		if (ra < mini):
			
			if (len(list) ==0):
				list.append(t)
			elif (list[0][1] - list[0][0] > t[1]-t[0]):
				list[0] = t
				mini = t[1] - t[0] 
				continue 
		elif (ra == mini) : 
			list.append(t)
			
print list[0][0], list[0][1]
