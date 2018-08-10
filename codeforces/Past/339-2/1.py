import math
s = raw_input()
s1 = s.split(" ")
l = int(s1[0])
r = int(s1[1])
k = int(s1[2])

def powe(a,b):
    if (b == 0):
        return 1 ; 
    if (b == 1):
        return a ; 
    if (b&1):
        t = powe(a,b/2)
        return a*t*t ; 
    else:
        t = powe(a,b/2) 
        return t*t ; 

st = int(math.log(l)/math.log(k))
if (k**st != l):
    st += 1 
fl = 0 
init = int(k**st) 
while (init <= r):
    fl = 1
    print init, 
    init *= k 
if (fl == 0):
    print "-1"
