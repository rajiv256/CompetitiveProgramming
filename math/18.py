f = open('input','r')
s = ''
ss = f.readlines()
l = [[] for k in range(len(ss))]
for i in range(len(ss)):
    ss[i] = ss[i][:-1]
    l[i] = ss[i].split(' ')
    for j in range(len(l[i])):
        l[i][j] = int(l[i][j])

def solve(row,idx):
    
    if (row>=len(ss)):
        return 0 ;
    if (idx >=len(l[row])):
        return 0 ;
    a1 = solve(row+1,idx)
    a2 = solve(row+1,idx+1)
    return max(a1,a2)+l[row][idx] ;

summ = solve(0,0)
print summ
