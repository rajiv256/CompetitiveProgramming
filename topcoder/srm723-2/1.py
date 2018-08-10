s = raw_input()
if ((s[0:7]!='buffalo') | (s[-7:]!='buffalo')):
    print "Not good"
    exit(0)
sp = s.split("buffalo")
print sp
print sp
for k in sp :
    if (k != ' ') :
        print "Not good"
        exit(0)
print "Good"
