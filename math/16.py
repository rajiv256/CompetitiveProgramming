def sod(n):
    sum = 0
    while (n!=0):
        sum += n%10
        n /= 10
    return sum
for i in range(1,1001):
    print sod(2**i)
