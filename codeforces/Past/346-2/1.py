s = raw_input()
s1 = s.split(" ")
n = int(s1[0])
a = int(s1[1]) 
b = int(s1[2])
a -= 1 
print ((a+b)%n)+1