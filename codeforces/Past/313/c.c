#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int valid (int** board, int fx , int fy,int h, int w) {
	if (fx <= h-1 && fy >= 0) {
		if (board[fx][fy] == 0 )
			return 1 ; 
	}
	return 0 ;
}



long int noOfWays (int** board ,int h, int w ,int fromx,int fromy ,int tox,int toy ,long int** L){
	if (fromx+1 == tox && fromy== toy){  
		return 1 ;
	}
	if ( (fromx== tox && fromy-1 == toy)) {
		return 1 ; 
	}
	if (L[fromx][fromy] == 0 && valid (board,fromx,fromy,h,w) == 1) {
		if ((valid (board,fromx+1,fromy,h,w) == 1) &&( valid (board,fromx,fromy-1,h,w)==1)  ){
			//printf("right+down\n");
			if (L[fromx+1][fromy] == 0 ){
				L[fromx+1][fromy] = noOfWays(board,h,w,fromx+1,fromy,tox,toy,L) ;
				L[fromx+1][fromy]%= 1000000007 ; 
			}
			if (L[fromx][fromy-1] == 0 ){
				L[fromx][fromy-1] = noOfWays(board,h,w,fromx,fromy-1,tox,toy,L) ; 	
				L[fromx][fromy-1]%= 1000000007 ; 
			}

			L[fromx][fromy] =  L[fromx+1][fromy] + L[fromx][fromy-1] ; 
			L[fromx][fromy] %= 1000000007 ; 
			//printf("%d   %d %d\n",L[fromx][fromy],fromx,fromy) ; 
		}
		if ((valid (board,fromx+1,fromy,h,w) == 0) && (valid (board,fromx,fromy-1,h,w)==1) ){
				//printf("down\n") ;
				if (L[fromx][fromy-1] == 0){
					L[fromx][fromy-1] =   noOfWays(board,h,w,fromx,fromy-1,tox,toy,L) ;
					L[fromx][fromy-1]%= 1000000007 ; 
			}

				L[fromx][fromy] = L[fromx][fromy-1] ; 
				
				L[fromx][fromy] %= 1000000007 ; 
				//printf("%d   %d %d\n",L[fromx][fromy],fromx,fromy) ; 
		}
		if ((valid (board,fromx+1,fromy,h,w) == 1 )&& (valid (board,fromx,fromy-1,h,w)==0 )){
				//printf("right\n");
				if (L[fromx+1][fromy] == 0 ){
					L[fromx+1][fromy] = noOfWays(board,h,w,fromx+1,fromy,tox,toy,L) ; 
					L[fromx+1][fromy]%= 1000000007 ; 
			}

				L[fromx][fromy] = L[fromx+1][fromy] ;
				L[fromx][fromy] %= 1000000007 ; 
				//printf("%d   %d %d\n",L[fromx][fromy],fromx,fromy) ;  
		}
		return L[fromx][fromy]  ;
	}
	return 0 ;
		
			
}
	

int main() {
	int h,w,n, i , j ; 
	scanf("%d%d%d",&h,&w,&n) ; 
	int** board = (int**)malloc(sizeof(int*)*h) ;
	for ( i = 0 ; i < h ; i++) {
		board[i] = (int*)malloc(sizeof(int)*w) ; 
	}
	long int** L = (long int**)malloc(sizeof(long int*)*h) ;
	for ( i = 0 ; i < h ; i++) {
		L[i] = (long int*)malloc(sizeof(long int)*w) ; 
	}
	for (i = 0 ; i < h ; i++ ){
		for ( j = 0 ; j < w ; j++ ){
			L[i][j] = 0 ; 
		}
	}
	
	 
	for (i = 0 ; i < h ; i++ ){
		for ( j = 0 ; j < w ; j++ ){
			board[i][j] = 0 ; 
		}
	}
	for ( i = 0 ; i < n ; i++ ){
		int x,y ; 
		scanf( "%d%d",&x,&y ) ; 
		board[x-1][y-1] = 1 ; 
	}
		
	long int result = noOfWays (board,h,w,0,w-1,h-1,0,L) ; 
	printf("%ld\n",result) ; 
	return 0 ; 
}
