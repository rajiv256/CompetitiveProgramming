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
	int k , r; cin >> k >> r ; 
	int ans = -1 ; 
	for(int n = 1 ; n <= 10 ; n++){
		if ((n*k) %10 == 0  || (n*k-r)%10 == 0){
			ans = n ; 
			break ; 
		}
	}
	cout << ans << el ; 
}