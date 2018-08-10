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
	int T  ; cin >> T ; 
	while (T--){
		ll a , b , c , d ; cin >> a >> b >> c >> d ; 
		ll ans = 0 ; 
		if (b<a || d<c){
			cout << ans << el; 
			continue ; 
		}
		if (d < a){
			cout << ans << el ; 
			continue ; 
		}
		if (c > b){
			ans = (b-a+1)*(d-c+1) ; 
			cout << ans << el ; 
			continue ; 
		}
		if (c >= a && d>=b){
			ans = (c-a)*(d-c+1) + ((b-c+1)*(2*d-b-c))/2 ; 
			cout << ans << el ; 
			continue ; 
		}
		if (c >=a && d<=b){
			ans = (c-a)*(d-c+1)+((d-c)*(d-c+1))/2 ; 
			cout << ans << el ; 
			continue ; 
		}
		if (c<=a && d<=b){
			ans = ((d-a)*(d-a+1))/2 ; 
			cout << ans << el ;
			continue ; 
		}
		if (c<=a && d>=b){
			ans = ((b-a+1)*(2*d-a-b))/2 ;  
			cout << ans << el ;
			continue ; 
		}
	}
}