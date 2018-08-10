s1 = raw_input() 
s2 = raw_input()
def checkEq (s1 , s2 ) :
	 if (s1 == s2 ) :	 
	 	return True
	 if (len(s1) != len(s2)) : 
	 	return False 
	 if (len(s1) == 1 )   :
	 	if (s1 == s2 ) :
	 		return True 
	 	else : 
	 		return False
	 		
	 if ( len(s1)%2 != 0 ) :
	 	if (s1 == s2 ):
	 		return True 
	 	else :
	 		return False 
	 elif (s1 != s2 ) : 
	 	len1 = len(s1) 
	 	len2 = len(s2)
	 	return (checkEq(s1[:len1/2] , s2[:len2/2 ] ) & checkEq(s1[len1/2:len1] , s2[len2/2 : len2])) | (checkEq (s1[:len1/2] , s2[len2/2 : len2] ) & checkEq(s1[len1/2:len1] , s2[ : len2/2]))
	 
if (checkEq (s1 , s2 ) == True ) :
	print "YES"
else : 
	print "NO"		
