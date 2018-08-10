#!/usr/local/bin/python3

def cal_shortest_path(n,city_map):
	short_path = [[10000 for y in range(n+1)] for x in range(n+1)]
	for i in range(1, n+1 ):
		short_path[i][i] = 0
	for path in city_map:
		short_path[path[0]][path[1]] = path[2]
		short_path[path[1]][path[0]] = path[2]
	for k in range(1, n+1 ):
		for i in range(1, n+1 ):
			for j in range(1, n+1 ):
				if short_path[i][j] > short_path[i][k] + short_path[k][j]:
					short_path[i][j] = short_path[i][k]+short_path[k][j]
	for i in range(n+1):
		for j in range(n+1):
			if short_path[i][j] == 10000:
				short_path[i][j] = 0
	return short_path

def avg_short_path(n,short_path):
	return [sum(x)/(n-1) for x in short_path]

def dump_short_path(short_path):
	for i in range(1,n+1):
		print(" ".join([str(short_path[i][j]) for j in range(1, n+1)]))

large_num = 10000000

def codejamon_go(n, m, p, city_map):
	short_path = cal_shortest_path(n,city_map)
	avg_path   = avg_short_path(n,short_path)
	time_start = avg_path[1]
	time_other = sum(avg_path[2:])/(n-1)
	p_start = 1
	p_other = 0
	time = 0.0
	for idx in range(p):
		if idx > large_num:
			time += (p_start * time_start + (n-1) * p_other * time_other)*(p-large_num)
			return time
		time += p_start * time_start + (n-1) * p_other * time_other
		p_start_nxt = p_other
		p_other_nxt = p_start/(n-1) + p_other*(n-2)/(n-1)
		p_start = p_start_nxt
		p_other = p_other_nxt
	return time


# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Code Jam problems.
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
	n, m, p = [int(s) for s in input().split(" ")]
	city_map = []
	for j in range(1, m + 1):
		path = [int(s) for s in input().split(" ")]
		city_map.append(path)
	print("Case #{}: {}".format(i, codejamon_go(n, m, p, city_map)))
	# check out .format's specification for more formatting options