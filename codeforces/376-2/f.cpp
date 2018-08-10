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

int main(){
	unsigned int n ; cin >> n ;
	unsigned int a[n] ; 
	forn(i,0,n){
		cin >> a[i] ; 
	}
	sort(a,a+n) ; 
	unsigned int maxi = 0 ; 
	forn(i,0,n){
		unsigned int ret = 0  ; 
		unsigned int maxDiv = 1 ; 
		if (a[i] != 0)
			maxDiv = a[n-1]/a[i] + 1 ; 
		//cout << maxDiv << el ; 
		for(unsigned int j = 1 ; j <= maxDiv ; j++){
			unsigned int* it1 = lower_bound(a,a+n,a[i]*j) ; 
			unsigned int* it2 = lower_bound(a,a+n,a[i]*(j+1)); 
			//it2-- ;
			unsigned int num ;  
			if (it1 == a+n){
				num = 0 ; 
			}
		    else 
		    	num = (unsigned int)(it2-it1)+1 ; 
			//cout << num << sp << a[i] << sp << j << el ; 
			ret += num*(a[i]*j) ; 
		}
		
		//cout << maxi << el ; 
	}
	cout << maxi << el ;

}