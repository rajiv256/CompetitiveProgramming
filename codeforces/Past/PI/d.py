s = raw_input()
s1 = s.split(" ")
n = int(s1[0])
k = int(s1[1])
a = int(s1[2])
shots = input()
l = [ ]
s = raw_input()
s1 = s.split(" ")

for i in range(shots) :
    l.append(int(s1[i]))

slots = [(1,n)]
i = 0 

def getCount(l) :
    if (l < a) : 
        return 0 
    elif (l == a ):
        return 1
    else:
        return 1 + getCount(l-a-1)






def fits(slots) :
    count = 0 
    for t in slots :
        count += getCount(t[1] - t[0] + 1)
    if (count >= k ):
        return True
    return False





def check(slots, i ) :
    for j in range(len(slots)):
        if ((l[i] >= slots[j][0]) & (l[i] <= slots[j][1])):
            t = slots[j] 
            slots.remove(slots[j])
            
            slots.append((t[0], l[i]-1))
            slots.append((l[i]+1,t[1]))
            break
    return fits(slots)





flag = 0 

for i in range(len(l)):
    if (check(slots, i ) == False) :
        flag = 1
        print i+1
        break
if (flag == 0 ): 
    print "-1"


