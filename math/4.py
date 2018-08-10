def ispal(n):
    l = []
    while (n!=0):
        l.append(n%10)
        n /= 10
    for i in range(len(l)/2) :
        if (l[i]!=l[len(l)-i-1]) :
            return False
    return True


maxi = max([i*j for i in range(100,1000) for j in range(100,1000) if ispal(i*j)])
print maxi
