fi = 10**999
en = 10**1000 - 1
F1 = 1
F2 = 1

F = 0
idx = 2
while (F<fi):
    temp = F2
    F = F1+temp
    F1 = F2
    F2 = F
    idx += 1
print idx
print F 
