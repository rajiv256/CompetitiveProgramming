#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getPattern(char* s ) {
	int count = 0 ,i ; 
	for ( i = 0 ; i < strlen(s) ; ){
		if (s[i] != '.'){
			i++;
			continue ; 	
		}
		else {
			if (s[i+1] == '.'){
				count++ ; 
			}
			i++ ; 
			continue;
		}
	}
	
	return count ; 
}


int main () {
	int n , m ; 
	scanf("%d%d",&n,&m);
	char* s = (char*)malloc(sizeof(char)*(n+1)) ; 
	scanf("%s",s);
	int count = 0  ; 
	char* temp = (char*)malloc(sizeof(char)*10);
	count = getPattern(s) ;
	
	int a[m] ; 
	int i ; int index ; char c ; 
	for ( i = 0 ; i < m ; i++){
		scanf("%d",&index);
		scanf("%s",temp) ; 
		c = temp[0] ; 
		index -= 1 ; 
		if ((s[index] != '.' && c != '.') ||(s[index] == '.' && c == '.')){
			s[index] = c ; 
			a[i] = count ; 
			continue ; 
		}
		if (s[index] == '.' && c != '.' ) {
			s[index] = c ;
			if (index+1 <= n-1 ) {
				 
				if (s[index+1] == '.'){
					count-=1 ;  
				}
			}
			if ( index-1 >=0 ) {
				if (s[index-1] == '.') {
					count -= 1 ; 
				}
			}	
			a[i] = count ; 
		}
		if (s[index] != '.' && c == '.' ) {
			s[index] = c ;
			if (index+1 <= n-1 ) {
				if (s[index+1] == '.'){
					count+=1 ;  
				}
			}
			if ( index-1 >=0 ) {
				if (s[index-1] == '.') {
					count += 1 ; 
				}
			}	
			a[i] = count ; 
		}		
	}
	for ( i = 0 ; i < m ; i++){
		printf("%d\n",a[i]); 
	}
	return 0 ; 
	
}
		
	
