from math import sqrt
for i in range(1,1000):
    for j in range(1,1000):
        if (sqrt(i**2+j**2) == int(sqrt(i**2+j**2))):
            c = sqrt(i**2+j**2)
            if (i+j+c==1000):
                print i*j*c
                print i , j , c
