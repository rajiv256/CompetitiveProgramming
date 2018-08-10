#include <bits/stdc++.h>

using namespace std ;



#define forn(i,n) for(int i = 0; i < n ; i++)
#define INF 10000000000LL

#define el "\n"
#define MXN 100009
#define sci(x) scanf("%d",&x)
#define mp make_pair
#define ll long long


ll pre[100009] ; 
int s[100009] ; 

bool valid(int idx, int n){
	if (idx >= 0 && idx <= n+1){
		return true ; 
	}
	return false ; 
}


ll solve(int fp , int sp , int n){
	
	//cout << fp << " " << sp << el;

	if (!valid(fp,n) || !valid(sp,n)){
		return 0 ; 
	}
	while (valid(fp,n)){
		if (s[fp]==1)
			fp++ ;
		else
			break ;  
	} 
	fp -= 1 ; 
	if (!valid(fp,n)) 
		return 0 ; 

	sp = fp+1 ; 
	while (valid(sp,n)){
		if (s[sp]==0)
			sp++ ; 
		else{
			break ; 
		}
	}
	//cout << sp << el ; 

	if (!valid(sp,n))
		 return 0 ; 
	
	ll ret = 2*(INF)+10 ;
	
	for(int i = fp ; i < sp ; i++){
		ret = min(ret,pre[sp]-pre[i+1]+pre[i]-pre[fp]) ; 
	} 
	ll temp = solve(sp,sp,n) ; 
	return (ret+temp) ; 
}




int main(){
	int t ; cin >> t ; 
	
	while (t--){
		int n ;  cin >> n ; 
		s[0] = 1 ; 
		forn(i,MXN){
			s[i] = 1 ; 
		}
		forn(i,n){
			char c ; cin >> c ; 
			s[i+1] = c-'0' ; 
		}
		
		memset(pre,0,sizeof(pre)) ; 

		forn(i,n){
			 scanf("%lld",&pre[i+1]) ; 
		}
		// forn(i,n+2){
		// 	cout << s[i] << " " ;  
		// }
		// //cout << "came" << el ; 
		pre[0] = -INF ; pre[n+1] = INF ; 
		
		ll ans = solve(0,0,n) ;
		cout << ans << el ;
	}
}