t = input()
it = 0

while (it < t):
    n = input()
    l = []
    s = raw_input() 
    s1 = s.split(" ")
    for i in range(n):
        l.append(int(s1[i]))
    st = 0
    en = n-1 
    while (st < n):
        if (l[st] != 0):
            break
        st += 1 
    while (en >= 0):
        if (l[en] != 0):
            break 
        en -= 1 
    sum = 0 
    ht = min(l[st],l[en])
    for i in range(st+1,en):
        sum += max(0,ht-l[i])
    print sum 
    it += 1
    