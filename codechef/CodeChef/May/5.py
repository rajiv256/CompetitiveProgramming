fact = []
fact.append(1)
for i in range(1,100003):
    fact.append(i*fact[i-1])

def ncr(n,r):
    return ((fact[n])/(fact[n-r]*fact[r])) ;

l = [False for i in range(0,100004)]
def sieve():
    for i in range(4,100004) :
        l[i] = True
    for i in range(3,100004):
        j = 2
        while (i*j < 100004):
            l[i*j] = True
            j += 1
        i += 2
t = input()
kase = 0
sieve()

while (kase < t):
    s = raw_input()
    s1 = s.split(" ")
    n = int(s1[0])
    m = int(s1[1])
    primes = []
    for i in range(2,n+1):
        if (l[i] == False):
            primes.append(i)
    nprimes = len(primes)
    d = {}
    for i in range(nprimes):
        d[primes[i]] = n/primes[i] -1




    kase += 1