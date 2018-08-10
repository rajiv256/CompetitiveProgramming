t = input()

def pr(s):
    if (len(s) == 3):
        print "%c%c%c" %(s[1],s[3],s[2])
        return ; 
    nest = 0 
    for i in range(len(s)):
        if (nest == 0):
            if ((s[i] == '*') | (s[i] == '+') | (s[i] == '-') | (s[i] == '^')):
                pr(s[1:i])
                pr(s[i+1:])
                print "%c" %s[i] 
                return ; 
        else :
            if (s[i] == '(') :
                nest += 1 
            elif (s[i] == ')'):
                nest -= 1 
    return ; 


it = 0
while (it < t):
    s = raw_input()
    pr(s) 
    it += 1 