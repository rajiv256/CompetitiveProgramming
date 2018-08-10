#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int equals (char* s1 , char* s2, int len ) {
	int i ; 
	if (strlen(s1) != strlen(s2)){	
		return 0 ; 
	}
	for ( i = 0 ; i < len ; i++){
		if (s1[i] != s2[i]) {
			return 0 ; 
		}
	}
	return 1 ;
}

int rec (char* s1 , char* s2 , int len ) {
	
	if (equals(s1,s2,len)==1) { 
		return 1 ; 
	}
	
	if (len%2 != 0 ){
		return 0 ;  	
	}
	int s = len/2 ; 
	printf("%d\n",s);
	if ((rec(s1,s2,len/2) && rec(s1+len/2, s2+len/2,len/2))||(rec(s1,s2+len/2,len/2) && rec ( s1+len/2 , s2,len/2 )))
		return 1 ; 
	return 0 ; 
}

int main () {
	int i ; 
	char *s1 , *s2 ; 
	s1  = (char*) malloc (sizeof(char)) ; 
	s2  = (char*) malloc (sizeof(char)) ; 
	scanf("%s",s1);
	scanf("%s",s2);
	if (rec (s1, s2,strlen(s1))==1){
		printf("YES\n") ; 
		return 0 ; 
	}
	printf("NO\n") ; 
	return 0 ; 
}
