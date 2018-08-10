#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getIndex (char c , char* s ) {
	int i ; 
	for ( i = 0 ; i < strlen(s) ; i++) {
		if (s[i] == c ) 
			return i ; 
	}
}

char getLeast (char* s1 , char* s , int flag ) {
	int i ; 
	if (flag == 3 ) {
		return s1[0] ; 
	}
	if (flag == 2) {
		for ( i = 0 ; i < strlen(s) ; i++){
			if ( s[i] == 'C') {
				return s1[i] ; 
			}
		}
	}	
	if (flag == 1 ) {
		for ( i = 0 ; i < strlen(s) ; i++){
			if (s[i] == 'V'){
				return s1[i] ; 
			}
		}
	}

}



int check ( char* l , int j , int i , char* s , int flag ) {
	char* s1 = "abcdefghijklmnopqrstuvwxyz" ;
	if (flag == 1 ) {
		if (s[getIndex(l[j],s1)] == 'C' ){
			if (s[getIndex(l[i],s1)] == 'C')
				return 1 ; 
			return 0 ;
		}
		else
			return 0 ; 
	}
	if (flag == 2 ) {
		if (s[getIndex(l[j],s1)] == 'C' ){
			if (s[getIndex(l[i],s1)] == 'V')
				return 1 ; 
			return 0 ;
		}
		else
			return 0 ; 
	}
	if (flag == 3 ) {
		if (s[getIndex(l[j],s1)] == 'V' ){
			if (s[getIndex(l[i],s1)] == 'C')
				return 1 ; 
			return 0 ;
		}
		else
			return 0 ; 
	}
	if (flag == 4 ) {
		if (s[getIndex(l[j],s1)] == 'V' ){
			if (s[getIndex(l[i],s1)] == 'V')
				return 1 ; 
			return 0 ;
		}
		else
			return 0 ; 
	}
}



char* getNext(char* l , int** a , int n , char* s ) {
	int i , j   ; int avail ; 
	char* s1 = "abcdefghijklmnopqrstuvwxyz" ; 
	for ( i = n-1 ; i >= 0 ; i++) {
		int flag = 3 ;  avail = 2 ; 
		for ( j = 0 ; j < n ; j++ ) {
			if (a[j][i] == 0 )	
				continue ; 
			else {
				if (a[j][i] == 1 || a[j][i] == 3) {
						if ((check (l , j , i, s1 , 1) == 1) || (check (l, j, i, s1 , 3)==1) ){
							avail -= 1 ; 
							flag = 2 ; 
						}	 
				}
				if (a[j][i] == 2 || a[j][i] == 4) {
						if ((check (l , j , i, s1, 2) == 1) || (check (l, j, i,s1, 4)==1) ){
							avail -= 1 ; 
							flag = 1 ; 
						}	 
				}
			}
			
		}
		if (avail == 0 ){
			continue ; 
		}
		else {
			
			l[j] = getLeast (s1 , s, flag ) ;	
			return l ; 
		}
	}
	
	return "-1\n" ; 

} 



int main () {
	char* s = (char*)malloc(sizeof(char)*26) ; 
	scanf( "%s",s );	
	int m, n , i ; 
	scanf("%d%d",&n ,&m) ; 
	int** a = (int**) malloc(sizeof(int*)*n) ;
	for ( i = 0 ; i < n ; i++){
		a[i] = (int*) malloc(sizeof(int)*n) ; 
	} 
	for ( i = 0 ; i < m ; i ++) {
		int i , j ; 
		char c1 , c2; 
		scanf("%d%c%d%c",&i , &c1 , &j , &c2) ; 
		if ( c1 == 'C' && c2 == 'C')
			a[i-1][j-1] =  1 ; 
		if ( c1 == 'C' && c2 == 'V')
			a[i-1][j-1] =  2 ; 
		if ( c1 == 'V' && c2 == 'C')
			a[i-1][j-1] =  3 ; 
		if ( c1 == 'V' && c2 == 'V')
			a[i-1][j-1] =  4 ; 
	}
	char* l = (char*) malloc (sizeof(char)*n) ; 
	scanf("%s",l);		
	printf("came\n"); 
	printf("%s\n",getNext (l , a ,n, s )) ;  
}

