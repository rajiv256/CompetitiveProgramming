s = raw_input()
count = 0 
i = 0 
while (i < len(s)):
	if (s[i] != 'S'):
		count += 1 
	i += 1 
	if (s[i] != 'O'):
		count += 1 
	i += 1 
	if (s[i] != 'S'):
		count += 1 
	i += 1
print count  