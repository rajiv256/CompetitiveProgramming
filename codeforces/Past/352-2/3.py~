import math
s =raw_input()
s1 = s.split(" ")
ax,ay,bx,by,rx,ry = int(s1[0]),int(s1[1]),int(s1[2]),int(s1[3]),int(s1[4]),int(s1[5])
nb = input()


def dist(a,b,x):
	return (math.sqrt((x[0]-a)**2+(x[1]-b)**2)) ; 


bottles = []
for i in range(nb):
	s = raw_input()
	s1 = s.split(" ")
	bottles.append((int(s1[0]),int(s1[1])))


dista = [dist(ax,ay,x) for x in bottles]
distb = [dist(bx,by,x) for x in bottles]
distr = [dist(rx,ry,x) for x in bottles]

diff1 = [(distr[i]-dista[i],i) for i in range(nb)]
diff2 = [(distr[i]-distb[i],i) for i in range(nb)]

diff1.sort()
diff1.reverse()
diff2.sort()
diff2.reverse()

ar = dist(ax,ay,(rx,ry))
br = dist(bx,by,(rx,ry))

total = 0 
for i in range(nb):
	total += distr[i]
total *= 2

if (nb==1):
	total -= max(diff1[0][0],diff2[0][0])
	print total 
else:
	ans = 0 
	if (diff1[0][1]!=diff2[0][1]):
		ans = 	diff1[0][0]+diff2[0][0]
	else:
		if ((len(diff2)>1)&(len(diff1)>1)):	
			ans = max(diff1[1][0]+diff2[0][0],diff1[0][0]+diff2[1][0])
	ret = total -ans
	ans = 0 
	ret = min(ret,total-diff1[0][0])
	ret = min(ret,total-diff2[0][0])


	print ret 











