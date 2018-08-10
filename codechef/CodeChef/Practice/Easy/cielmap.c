#include <stdio.h>
#include <math.h>

#define ccw(i,j,k) ((pt[j][0] - pt[i][0])*(pt[k][1]-pt[i][1]) > (pt[k][0]-pt[i][0])*(pt[j][1]-pt[i][1]))




int main() {
	int t ; int pt[1001][2] ; int i , j ; double d ; double c[6] ; 
	scanf("%d",&t);
	while (t--){
		double max = 0.0 ; 
		int sz = 0 ; 
		int n ; scanf("%d",&n) ; 
		if (n == 4){

			if (ccw(0,1,2) == ccw(0,1,3) || ccw(2,3,0) == ccw(2,3,1)){
				c[0] = (pt[0][0]-pt[1][0])*(pt[0][0]-pt[1][0]) + (pt[1][1]-pt[0][1])*(pt[1][1]-pt[0][1]) ; 
			}
			else{
				c[0] = 0 ; 
			}
			if(ccw(0,2,1) == ccw(0,2,3) || ccw(1,3,0) == ccw(1,3,2))
				c[1]=(pt[0][0] - pt[2][0])*(pt[0][0] - pt[2][0]) + (pt[0][1] - pt[2][1])*(pt[0][1] - pt[2][1]);
			else
				c[1]=0;
			if(ccw(0,3,1) == ccw(0,3,2) || ccw(1,2,0) == ccw(1,2,3))
				c[2]=(pt[0][0] - pt[3][0])*(pt[0][0] - pt[3][0]) + (pt[0][1] - pt[3][1])*(pt[0][1] - pt[3][1]);
			else
				c[2]=0;
			if(ccw(1,2,0) == ccw(1,2,3) || ccw(0,3,1) == ccw(0,3,2))
				c[3]=(pt[1][0] - pt[2][0])*(pt[1][0] - pt[2][0]) + (pt[1][1] - pt[2][1])*(pt[1][1] - pt[2][1]);
			else
				c[3]=0;
			if(ccw(1,3,0) == ccw(1,3,2) || ccw(0,2,1) == ccw(0,2,3))
				c[4]=(pt[1][0] - pt[3][0])*(pt[1][0] - pt[3][0]) + (pt[1][1] - pt[3][1])*(pt[1][1] - pt[3][1]);
			else
				c[4]=0;
			if(ccw(2,3,0) == ccw(2,3,1) || ccw(0,1,2) == ccw(0,1,3))
				c[5]=(pt[2][0] - pt[3][0])*(pt[2][0] - pt[3][0]) + (pt[2][1] - pt[3][1])*(pt[2][1] - pt[3][1]);
			else
				c[5]=0;
 
			max=0;
			for(i=0;i<6;i++)
			{
				if(c[i]>max)	
					max=c[i];
			}
 
			
			printf("%lf\n",sqrt(max));
		}
	
 
		else {

			for (i = 0 ; i < n ; i++){
				scanf("%d",&pt[i][0]) ; 
				scanf("%d",&pt[i][1]);
			}
			for (i = 0 ; i < n ; i++){
				for (j = i+1 ; j < n ; j++){
					d = ((pt[i][0]-pt[j][0])*(pt[i][0]-pt[j][0])) + ((pt[i][1]-pt[j][1])*(pt[i][1]-pt[j][1])) ; 
					if (max < d )
						max = d ; 
				}
			}
			printf("%lf\n",sqrt(max)) ; 

		}




	}
}