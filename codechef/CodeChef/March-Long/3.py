t = input()
it = 0
while(it < t):
    s = raw_input()
    s1 = ""
    if (len(s)%2 == 0):
        if (s[0:len(s)/2] == s[len(s)/2:]):
            print ("YES")
            continue 
    fl = 0
    for i in range(len(s)):  
        s1 = s[0:i]+s[i+1:]
        if (s1[0:len(s1)/2] == s1[len(s1)/2:]):
            print ("YES")
            fl = 1
            break 
    if (fl == 1):
        continue 
    else:
        print ("NO")
    
    it += 1