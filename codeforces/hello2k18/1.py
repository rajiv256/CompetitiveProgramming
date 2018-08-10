n = input()
m = input()
n = int(n)
m = int(m) 
def po(x,y):
    if (y==0):
        return 1
    t = po(x,y/2)
    t = t*t
    if (y%2==1) :
        return x*t ;
    return t ;
print(m%(po(2,n)))
