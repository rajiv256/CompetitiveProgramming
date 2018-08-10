#include<stdio.h>
#include<stdlib.h>
//typedef struct Corner corner ; 
typedef struct Corner {
	int x ; 
	int y ; 
}  corner;


corner* getCorners (int l , int b ) {
	corner* c = (corner*)malloc(sizeof(corner)*3) ; 
	c[0].x = l ;
	c[0] .y = 0 ; 
	c[1].x = 0 ; 
	c[1].y = b ; 
	c[2].x = l ;
	c[2].y = b ; 
	
	return c ; 
}

int check (corner c , int bl, int bb, int l2, int b2) {
	//printf("%d %d %d %d\n",c.x+l2,c.y+b2,bl,bb);
	if (c.x +l2 <= bl && c.y + b2 <= bb)
		return 1 ; 
	return 0 ;
}
	
	




int main( ) {
	int bl ,bb ; 
	int l1,b1, l2, b2 ; 
	scanf("%d%d%d%d%d%d",&bl,&bb,&l1,&b1,&l2,&b2) ;
	
	
	corner zero ; 
	zero.x = 0 ; 
	zero.y = 0 ; 
	if (check(zero,bl,bb,l1,b1)  ){
		
		
		corner* pos1 = (corner*)malloc(sizeof(corner)*3) ;
		
		pos1 =  getCorners(l1,b1) ;
		
		int i = 0 ; 
		for (i = 0 ; i < 3 ; i++) {	
			if (check(pos1[i] ,bl, bb, l2, b2) == 1 ){
				
				printf("YES\n"); 
				return 0; 
			}
			if (check(pos1[i] ,bl, bb, b2 ,l2)== 1) {
				
				printf("YES\n"); 
				return 0; 
			}
		}
	}
		
		
	 if (check(zero,bl,bb,b1,l1) == 1 ){	 
		
		corner* pos2 = (corner*)malloc(sizeof(corner)*3) ; 
		
		pos2 =  getCorners(b1,l1) ; 
		int i = 0 ; 
		for (i = 0 ; i < 3 ; i++) {	
		
			if (check(pos2[i] ,bl, bb, l2, b2)==1 ){
				printf("YES\n"); 
				return 0; 
			}
			if (check(pos2[i] ,bl, bb, b2 ,l2)== 1) {
				printf("YES\n"); 
				return 0; 
			}
		}
	}	
	
	printf("NO\n");
	return  0; 
}


