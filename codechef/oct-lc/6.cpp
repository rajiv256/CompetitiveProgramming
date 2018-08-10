/* 
        Code written by rajiv. 
        God speed!
*/
#include <bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define sclf(x) scanf("%lf",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100005
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define hashp 999983 
 
typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 
typedef vector<vector<ll> > vvl ; typedef vector<ll> vl ; 
 
 
int n , q , sz ; 
 
int pp(int i){
	return ((i+sz)%sz) ; 
}
 
int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 
 
	int t ; cin >> t ; 
	while (t--){
		cin >> n >> q ; 
 
		vector<vector<ll> > v(n,vector<ll>()) ; 
		forn(i,0,n){
			int m ; cin >> m ; 
			forn(j,0,m){
				int x ; cin >> x ; 
				v[i].pb(x) ; 
			}
		}
 
		vector<int> ins(n,0) ; 
		vector<int> outs(n,0) ; 
		vector<ll> inter(n,(ll) 0) ; 
		int v1 , v2 ; ll w ; 
		forn(i,0,n){
			cin >> v1 >> v2 >> w ; v1-- ; v2-- ; 
			outs[i] = v1 ; 
			ins[(i+1)%n] = v2 ; 
			inter[i] = w ; 
		}
 
		vector<vector<ll> > dfinfwd(n,vector<ll>()) ; 
		vector<vector<ll> > dfinbwd(n,vector<ll>()) ;
		vector<vector<ll> > dfoutfwd(n,vector<ll>());
		vector<vector<ll> > dfoutbwd(n,vector<ll>()); 
		forn(i,0,n){
			forn(j,0,v[i].size()){
				dfinfwd[i].pb(0) ; 
			}
			sz = v[i].size() ; 
			int j = ins[i]+1 ; 
			while (pp(j) != ins[i]){
				dfinfwd[i][pp(j)] = dfinfwd[i][pp(j-1)] + v[i][pp(j-1)] ; 
				j++ ; 
			}
			// for(int j = ins[i]+1 ; pp(j) != ins[i] ; j++){
			// 	dfinfwd[i][pp(j)] = dfinfwd[i][pp(pp(j)-1)] + v[i][pp(pp(j)-1)] ; 
			// }
		} 
 
		forn(i,0,n){
			forn(j,0,v[i].size()){
				dfinbwd[i].pb(0) ; 
			}
			sz = v[i].size() ; 
			int j = ins[i]-1 ; 
			while (pp(j) != ins[i]){
				//cout << j%sz << sp << ins[i] << el ; 
				dfinbwd[i][pp(j)] = dfinbwd[i][pp(j+1)] + v[i][pp(j)] ; 
				j-- ;   
			}
			// for(int j = ins[i]-1 ; pp(j)!=ins[i] ; j--){
			// 	dfinbwd[i][pp(j)] = dfinbwd[i][pp(pp(j)+1)] + v[i][pp(pp(j))] ; 
			// }
		}
 		 
		forn(i,0,n){
			forn(j,0,v[i].size()){
				dfoutfwd[i].pb(0) ; 
			}
			sz = v[i].size() ; 
			int j= outs[i]+1 ; 
			while (pp(j) != outs[i]){
				dfoutfwd[i][pp(j)] = dfoutfwd[i][pp(j-1)] + v[i][pp(j-1)] ; 
				j++ ; 
			}
			// for(int j = outs[i]+1 ; pp(j) != outs[i] ; j++){
			// 	dfoutfwd[i][pp(j)] = dfoutfwd[i][pp(pp(j)-1)] + v[i][pp(pp(j)-1)] ; 
			// }
		} 
		
		forn(i,0,n){
			forn(j,0,v[i].size()){
				dfoutbwd[i].pb(0) ; 
			}
			sz = v[i].size() ; 
			int j = outs[i]-1 ; 
			
			while (pp(j) != outs[i]){ 
				dfoutbwd[i][pp(j)] = dfoutbwd[i][pp(j+1)] + v[i][pp(j)] ; 
				j-- ; 
			}
			// for(int j = outs[i]-1 ; pp(j)!= outs[i] ; j--){
			// 	dfoutbwd[i][pp(j)] = dfoutbwd[i][pp(pp(j)+1)] + v[i][pp(pp(j))] ; 
			// }
		}
 
		vector<vector<ll> > dfin(n,vector<ll>()) ; 
		vector<vector<ll> > dfout(n,vector<ll>()) ;
		forn(i,0,n){
			forn(j,0,v[i].size()){
				dfin[i].pb(0) ; 
			}
			forn(j,0,v[i].size()){
				dfin[i][j] = min(dfinfwd[i][j],dfinbwd[i][j]) ; 
			}
		}
		forn(i,0,n){
			forn(j,0,v[i].size()){
				dfout[i].pb(0) ; 
			}
			forn(j,0,v[i].size()){
				dfout[i][j] = min(dfoutfwd[i][j],dfoutbwd[i][j]) ; 
			}
		}
 
 
		vector<ll> cdfwd(n,0) ; 
		vector<ll> cdbwd(n,0) ; 
		
		cdfwd[1] = inter[0] ; 
		for(int i = 2 ; i < n ; i++){
			cdfwd[i] = cdfwd[i-1] + dfin[i-1][outs[i-1]] + inter[i-1] ; 
		}
		cdfwd[0] = cdfwd[n-1] + dfin[n-1][outs[n-1]] + inter[n-1] ; 
 
		cdbwd[n-1] = inter[n-1] ;                 // distance to each cycle till its out. 
		for(int i = n-2 ; i >= 0 ; i--){
			cdbwd[i] = cdbwd[i+1] + dfout[i+1][ins[i+1]] + inter[i] ; 
		}
 
 
 
		while (q--){
			int v1, c1, v2, c2 ; cin >> v1 >> c1 >> v2 >> c2 ; v1-- ; v2-- ; c1-- ; c2-- ; 
			
			int M = c1 , m=c2 , V=v1 , u=v2 ;
			if (c2 > c1){
				M = c2 ; m = c1 ; V = v2 , u = v1 ; 
			} 
 
			ll fwd = 0 ; 
			if (m == 0){
				fwd += cdfwd[M] ; 
				fwd += dfout[m][u] ;
				fwd += dfin[M][V] ; 
			}
			else{
				fwd += cdfwd[M] ; 
				fwd -= cdfwd[m] + dfin[m][outs[m]] ; 
				fwd += dfout[m][u]; 
				fwd += dfin[M][V] ; 
			}
 
			ll bwd = 0 ; 
			if(m == 0){
				bwd += cdbwd[M] ; 
				bwd += dfin[m][u] ;
				bwd += dfout[M][V] ;  
			}
			else{
				bwd += cdfwd[m]+dfin[m][u] ; 
				bwd += dfout[0][ins[0]] ; 
				bwd += cdbwd[M]  ; 
				bwd += dfout[M][V] ; 
			}
 			
 			//cout << fwd << sp << bwd << el ; 
			
			ll ans = min(abs(fwd),abs(bwd)); 
			cout << ans << el ; 
 
 
		}
 
 
	}
}
 