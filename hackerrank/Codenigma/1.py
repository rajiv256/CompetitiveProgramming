import math 
t = input()
it = 0
while(it < t):
    k = input()
    angle = 360.0
    angle /= k
    angle/= 2 
    x = math.sin(math.radians(angle))
    x = math.ceil(x*(10**8))/10**8 
    ans = 1+1/x
    ans = math.ceil(ans*(10**8))/10**8
    print ans 
    it+= 1