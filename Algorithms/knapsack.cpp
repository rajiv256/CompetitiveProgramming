#include <bits/stdc++.h> 
using namespace std ; 

#define ll long long 
#define el endl 
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100003 
#define INF 10000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()

int cost[103] ; 
int fun[103] ; 
int L[103][503] ;







int main(){
	
while (true){
	int n , W ; 
	sci(W) ; sci(n) ; 
	if (W==0 && n==0){
		break ; 
	}
	memset(L,0,sizeof(L)) ; 
	memset(cost,0,sizeof(cost)) ; 
	clr(fun) ; 
	for(int i = 1 ; i <= n ; i++){
		sci(cost[i]) ; 
		sci(fun[i]) ; 

	}

	int maxC = 0 ;  int maxF = 0 ;

	for (int i = 0; i <= n; i++)
   {
       for (int w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               L[i][w] = 0;
           else if (cost[i] <= w)
                 L[i][w] = max(fun[i] + L[i-1][w-cost[i]],  L[i-1][w]);
           else
                 L[i][w] = L[i-1][w];
       }
   }

	
		int ans = 0 ; 
		for(int w = 0 ; w <= W ; w++){
			if (L[n][w] == L[n][W]){
				ans = w ; 
				break ;  
			}
		}
	
	
	printf("%d %d\n",ans,L[n][W]) ; 


}

}
	
