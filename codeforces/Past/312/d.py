s = raw_input() 
s1 = s.split() 
n = int(s1[0])
q = int(s1[1]) 
exits = [k for k in range(pow(2,n-1),pow(2,n))]
flag = 1

def remOret ( exits , lev , n, l , r , truth ) :
    if (truth == 1) :
        i = 0
        anc = 0 
        po = n - lev
        while (i < len(exits)):
            anc = exits[i]/(2**po)
            if ((anc-l)*(anc-r)<=0):
                i+=1
                continue
            else :
                exits.remove(exits[i])
                continue
        if (len(exits) == 0):
            return 0
        else:
            return 1
    else:
        
        j = 0
        anc =0
        po = n - lev
        while (j <len(exits)):            
            anc = exits[j]/(2**po)
            if ((anc-r)*(anc-l)<=0):
                exits.remove(exits[j])
                continue
            else:
                j+=1
                continue
        if (len(exits)==0):
            return 0
        return 1
	
for i in range(q) :	
	s = raw_input()
	s2 = s.split() 
	lev = int(s2[0])
	l = int(s2[1])
	r = int(s2[2])
	truth = int(s2[3]) 
	if (remOret(exits , lev,n, l , r , truth ) == 0):
		print "Game cheated!"
		flag = 0 
		break  
if (flag == 1) :
	if (len(exits) == 1):
		print exits[0]
	elif (len(exits) > 1) : 
		print "Data not sufficient!"	
