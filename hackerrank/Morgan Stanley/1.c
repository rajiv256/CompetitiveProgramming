#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int res = -1 ;
int n ; 

void solve(int* arr , int i ){
    
    if ( i == n-1){
        
        int temp = 0 ; 
        int j ; 
        //for ( j = 0 ; j < n ; j++){
        //  printf("%d ",arr[j]) ; 
        //}
        //printf("\n");
        for ( j = 0; j < n/2 ; j++){
            temp += abs(arr[j] - arr[n-j-1]) ; 
        }
        if ( res < temp){
            res = temp ;
        }
        //printf("%d\n",temp) ; 
        return ; 
    }
    if ( i == 0 ){
        solve (arr , i+1 ) ; 
    }
    int tem = arr[i] ; 
    if (arr[i-1]%2 == 0 && arr[i+1]%2 == 0){
        arr[i] = (arr[i-1]+arr[i+1])/2  ;
        solve (arr , i+1) ; 
    }
    arr[i] = tem ; 
    solve (arr , i+1) ; 
    return ;

} 

int abs(int a){
    if (a>0)
        return a ; 
    return -a ; 
}




int main() {

    int t ; 
    scanf("%d",&t) ; 
    
    while (t--){
        scanf("%d",&n); 
        int *arr = (int*)malloc(sizeof(int)*n);
         
        int j ; 
        for ( j = 0 ; j< n ; j++){
            scanf("%d",&arr[j]) ; 
        }
        res = 0 ; 
        solve (arr , 0) ;  
        printf("%d\n",res) ; 
        
        res = 0 ; 
         
    }
}
