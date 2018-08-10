#include <stdio.h>
#include <stdlib.h>

enum color {
	black,blue,red,green,yellow,orange 
} ;

enum side {
	front, back, left,right,top,bottom 
} ; 
	


int main (int argc , char* argv ) {
	 int t, i  ; 
	 enum color arr[6]  ; 
	 char s[64] , *p ; 
	 scanf("%d",&t) ; 
	 int num = 0 ; 
	while ( t-- ) {
	 	for (i = 0 ; i < 6 ; i++ ) {
	 		scanf("%s",s) ; 
	 		if (s[0] == 'b' && s[2] == 'a') {
	 			arr[num] = black ; 
	 		}
	 		if ( s[0] == 'b' && s[2] == 'u' ) {
	 			arr[num] = blue ; 
	 		}
	 		if ( s[0] == 'r') {
	 			arr[num] = red ; 
	 		}
	 		if (s[0] == 'g') {
	 			arr[num] = green ; 
	 		}
	 		if (s[0] == 'y') {
	 			arr[num] = yellow ; 
	 		}
	 		if ( s[0] == 'o' ) {
	 			arr[num] = orange ; 
	 		}
	 		num++ ; 
	 	}
	 	
	 	num = 0 ; 
	 	
	 	if (arr[front] == arr[top] && arr[top] == arr[right] ) 
	 		num = 1 ; 
	 	else if (arr[front] == arr[top] && arr[top] == arr[left] ) 
	 		num = 1 ; 
		else if (arr[front] == arr[bottom] && arr[bottom] == arr[right] ) 
	 		num = 1 ;
	  	else if (arr[front] == arr[bottom] && arr[bottom] == arr[left] ) 
	 		num = 1 ; 
	 	else if (arr[back] == arr[top] && arr[top] == arr[right] ) 
	 		num = 1 ; 
	 	else if (arr[back] == arr[top] && arr[top] == arr[left] ) 
	 		num = 1 ; 
		else if (arr[back] == arr[bottom] && arr[bottom] == arr[right] ) 
	 		num = 1 ; 
		else if (arr[back] == arr[bottom] && arr[bottom] == arr[left] ) 
	 		num = 1 ; 
	 	
	 	printf("%s\n", num? "YES"	: "NO" ) ; 
	 }
	 return 0 ; 
} 		 
