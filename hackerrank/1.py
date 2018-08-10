tt = input()
t = int(tt)
it = 0
while(it < t):
    s = input()
    #print (s)
    l = [] 
    curr = s[0] 
    fl = 0 
    if (curr == '1'):
        fl = 1 
        l.append(1)
    else :
        l.append(0) 
    i = 1
    cnt = 1
    cn = []
    while(i < len(s)-1):
        #print (i)
        if (fl ==1):
            if (s[i]=='1'):
                i += 1
                cnt += 1 
                continue
            else :
                l.append(0)
                i += 1
                fl = 0 
                cn.append(cnt)
                cnt = 1 
                continue
        if (fl == 0):
            if (s[i]=='0'):
                i += 1
                cnt += 1 
                continue 
            else :
                l.append(1) 
                i += 1 
                fl = 1
                cn.append(cnt)
                cnt = 1
                continue 
    if (fl == 0):   
        if (s[i]=='0'):
            cnt += 1
            cn.append(cnt)
        else:
            cn.append(cnt)
            cn.append(1)
            l.append(1)
    if (fl == 1):
        if (s[i]=='1'):
            cnt += 1 
            cn.append(cnt)
        else :
            cn.append(cnt)
            cn.append(1)
            l.append(0)
                   
    sum = 0 
    for i in cn :
        sum += i-1
    #print(sum) 
    sz = len(l) 
    sum += int((sz*(sz+1))/2)
    print (sum)
    it+= 1        