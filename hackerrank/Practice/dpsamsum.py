
s = raw_input()
n = len(s)
num = int(s)
x = int(s[0])
sum = x
prev = x
for i in range(1,n):
    x = prev*10 + int(s[i])*(i+1)
    sum += x%1000000007
    prev = x%1000000007
print sum%1000000007