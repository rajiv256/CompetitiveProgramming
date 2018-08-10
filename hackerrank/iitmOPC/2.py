n = int (raw_input())
s = raw_input()
s1 = s.split(" ")
l = []
lr = []
lb = []

for i in range(len(s1)):
    str = s1[i] 
    if (str[len(str)-1] == 'B'):
        ss = "" 
        for i in range(len(str)-1):
            ss += str[i]
        lb.append(int(ss))
    else:
        ss = "" 
        for i in range(len(str)-1):
            ss += str[i]
        lr.append(int(ss))
lr.sort()
lb.sort()
#print lr , lb 
num = min(len(lr),len(lb))
sum = 0 
it = 0 
while(it < num):
    sum += lr[len(lr)-1-it]
    sum += lb[len(lb)-1-it]
    it += 1
#print (sum)
sum -= 2*num 
print (sum) 
   