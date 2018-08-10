times = []
scores = []
wrongs = []
hs = 0 
hu = 0 
s = raw_input()
s1 = s.split(" ")
for i in range(5):
	s1[i] = (int(s1[i]))
	times.append(s1[i])
s = raw_input()
s1 = s.split(" ")
for i in range(5):
	s1[i] = (int(s1[i]))
	wrongs.append(s1[i])
for i in range(5):
	scores.append(500.0*(i+1))
s = raw_input()
s1 = s.split(" ")	
hs = int(s1[0])
hu = int(s1[1])

score = 0 
for i in range(5) : 
	score += max(0.3*(float)(scores[i]), scores[i] -scores[i]*times[i]/250 - 50.0*wrongs[i])
score += hs*100 - hu*50 

print int(score)
