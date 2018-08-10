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
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()

int main(){
	int n , k ; cin >> n >> k ;
	int a[n] ; int b[n] ;  
	int ans = 0 ; 
	forn(i,0,n){
		cin >> a[i] ; 
		b[i] = a[i] ;  
	}
	for(int i = 0 ; i < n ; ){
		int x = a[i] , y = a[i+1], z = a[i+2] ; 
		if (i == n-1){
			i++ ; 
			break ; 
		}
		if (i == n-2){
			if (a[i]+a[i+1]>=k) 
				break ; 
			else{
				int temp = a[i] ; 
				b[i] = k-a[i+1] ; 
				ans += b[i]-a[i] ; 
				break ;
			}
				
		}
		if (a[i]+a[i+1] >=k){
			i++ ; continue ;
		}
		int diff1 = max(0,k-(x+y)) ; 
		int diff2 = max(0,k-(y+z)) ; 
		ans += max(diff1,diff2) ; 
		if (diff1 < diff2){
			b[i+1] = diff1+a[i+1] ; 
			b[i+2] = a[i+2]+diff2-diff1 ; 
			i += 2 ; 
		}
		if (diff1 > diff2){
			b[i] = a[i]+diff1-diff2 ; 
			b[i+1] = diff2+a[i+1] ;
			i+= 2 ;  
		}
		if (diff1==diff2){
			b[i+1] = a[i+1]+diff1 ;
			i += 2 ;  
		}
	}
	cout << ans << el ; 
	forn(i,0,n){
		cout << b[i] << sp ; 
	}

	
	return 0 ; 
}