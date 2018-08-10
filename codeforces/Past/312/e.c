#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc (const void* a , const void* b ) {
    return (*(char*)a - *(char*)b); 
}

char* res (char* s , int l , int r , int k ){
    char li[r-l+1] ; 
    int i ; 
    for ( i = l ; i <= r; i++) {
         li[i-l] = s[i] ; 
    }
    qsort(li , r-l+1 , sizeof(char), cmpfunc) ;
    if ( k == 1 ){
        for ( i = l ; i <= r ; i++) {
            s[i] = li[i-l] ; 
        }
        return s ; 
    }
    if ( k == 0 ){
        for ( i = l ; i <= r ; i++) {
            s[i] = li[r-i] ; 
        }
        return s ; 
    }
}   

int main () {
    int n, i, j,q ;
    scanf("%d%d",&n,&q) ;
    char* s = (char*) malloc(sizeof(char)*n) ; 
    scanf("%s",s);
    for ( i =0  ; i < q ; i++) {
        int l ,r , k ;
        scanf("%d%d%d",&l,&r,&k) ;
        s = res (s , l-1 , r-1 , k) ; 
    }
    printf("%s\n",s);
}
