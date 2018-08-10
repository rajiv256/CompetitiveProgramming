n = input()
s = raw_input()
s1 = s.split(" ")
l = []
prod = 1 
for i in range(len(s1)):
    prod *= int(s1[i])
print prod 