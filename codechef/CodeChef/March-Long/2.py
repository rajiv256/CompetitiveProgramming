t = input()
it = 0 
while(it < t):
    
    s = raw_input()
    s1 = s.split(" ")
    n = int(s1[0])
    k = int(s1[1])
    a = []
    b = []
    s = raw_input()
    s1 = s.split(" ")
    for i in range(n):
        a.append(int(s1[i]))
    s = raw_input()
    s1 = s.split(" ")
    for i in range(n):
        b.append(int(s1[i]))
    for i in range(n):
        if (b[i] < 0):
            b[i] = -b[i] 
            a[i] = -a[i] 
    mv = b[0]
    ind = 0
    maxi = 0
    for i in range(n):
        maxi += a[i]*b[i] 
    for i in range(n):
        mv = max(mv,b[i])
    maxi += k*mv
    print (maxi) 