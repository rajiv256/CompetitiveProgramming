from math import sqrt as sqrt
def sod(n):
    sum = 1
    for i in range(2,int(sqrt(n))):
        if (n%i == 0) :
            sum += i ;
            sum += n/i ;
    sq = int(sqrt(n))
    if (n%sq==0):
        sum += sq
    return sum
l = [0 for i in range(10000)]
ans = []
for i in range(1,10000) :
    l[i] = sod(i) ;
    if (l[i] < i):
        if (l[l[i]]==i):
            ans.append(i)
            ans.append(l[i])
from sets import Set
ans = Set(ans)
print ans
x = sum(ans)
print x
