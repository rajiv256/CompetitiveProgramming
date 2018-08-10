import numpy as np
import networkx as nx
import math
from decimal import *
import random

fo = open('result.txt','w')


# good
# with open('test.txt') as f:
# 	t = int(f.readline().strip())
# 	for i in range(t):
# 		N, M, P = [int(_) for _ in f.readline().strip().split()]
# 		G=nx.Graph()
# 		for _ in range(M):
# 			u,v,d = [int(_) for _ in f.readline().strip().split()]
# 			G.add_edge(u-1,v-1,weight=d)
# 		dd = nx.floyd_warshall(G)

# 		# ff = np.zeros((P, N))
# 		ff = [[0 for x in range(N)] for y in range(P)] 
# 		for pi in range(P):
# 			if pi==0:
# 				for x in range(N):
# 					ff[pi][x] = dd[x][0]
# 				# if N==2:
# 				# 	ff[0, 0] = dd[1][0]
# 			else:
# 				for x in range(N):
# 					s = 0
# 					for y in range(N):
# 						if x != y and ff[pi-1][y] > 0:
# 							s += ff[pi-1][y] + int(dd[x][y])
# 					ff[pi][x] = s #
# 					# ff[pi,x] = (s/(N-1.0))
# 		# r = Decimal(sum(ff[P-1])) / Decimal((N-1)**P)
# 		# r = int(sum(ff[P-1]))*10000000//int(((N-1)**P))
# 		# r = int(sum(ff[P-1]))#*10000000/int(((N-1)**P))
# 		# r = r/float(10000000)
# 		r = math.exp(math.log(sum(ff[P-1])) - P*math.log(N-1))
		
# 		# if P==1:
# 		# 	r = np.sum(ff[P-1,:])/(N-1)
# 		# else:
# 		# 	r = np.sum(ff[P-1,:])/(N)
# 		fo.write("Case #{}: {}\n".format(i+1, r))
# fo.close()


# direct expected value
with open('test.txt') as f:
	t = int(f.readline().strip())
	for i in range(t):
		print i
		N, M, P = [int(_) for _ in f.readline().strip().split()]
		G=nx.Graph()
		for _ in range(M):
			u,v,d = [int(_) for _ in f.readline().strip().split()]
			G.add_edge(u-1,v-1,weight=d)
		dd = nx.floyd_warshall(G)

		prob = [[0. for x in range(N)] for y in range(P+1)]
		prob[0][0] = 1.

		for pi in range(1,P+1):
				for x in range(N):
					s = 0.
					c = 0.
					for y in range(N):
						if x != y and prob[pi-1][y] > 0:
							c += 1.	
					for y in range(N):
						if x != y and prob[pi-1][y] > 0:
							s += prob[pi-1][y]/(N-1)
					prob[pi][x] = s#/c if s>0 else 0.
				# assert abs(sum(prob[pi])-1.)<0.00001

		# for pi in range(1,P+1):
		# 		for x in range(N):
		# 			s = 0.
		# 			c = 0.
		# 			for y in range(N):
		# 				if x != y and prob[pi-1][y] > 0:
		# 					c += 1.
		# 			for y in range(N):
		# 				if x != y and prob[pi-1][y] > 0:
		# 					s += prob[pi-1][y]/c
		# 			prob[pi][x] = s#/c if s>0 else 0.
		# 		s = sum(prob[pi])
		# 		for x in range(N):
		# 			prob[pi][x] = prob[pi][x]/s

		# if i==2:
		# 	print [sum(prob[_]) for _ in range(P+1)]
		# 	raise

		s = 0.
		for pi in range(1,P+1):
			for u in range(N):
				ev = 0.
				for v in range(N):
					if u!=v:
						ev += dd[u][v]
				ev = ev/(N-1)
				s += prob[pi-1][u]*ev
			# if sp<0.0001:
			# 	print "true"
		r = s
		fo.write("Case #{}: {}\n".format(i+1, r))
fo.close()
