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
#define lb lower_bound
#define ub upper_bound
 
typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 
typedef vector<ll> vll ;
 
#define vli vector<ll>::iterator 
 
 
void printv(vll& v){
	for(int i = 0 ;i < v.size() ; i++){
		cout << v[i] << sp ; 
	}
	cout << el ; 
}
 
 
 
 
 
int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 
 
	int t; cin >> t ; 
	while (t--){
		int n , q ; cin >> n >> q ; 
		ll a[n+2]; 
		memset(a,0,sizeof(a)) ; 
		a[0] = (1LL)<<61 ; 
		a[n+1] = 0 ; 
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i] ; 
		}
		vll I ; I.pb(0) ; I.pb(1) ;
		vll E ; E.pb(0) ; 
		ll maxval = a[1] ; 
		vll lisi ; vll lisv ; lisi.pb(0) ; lisv.pb(0) ; 
		lisi.pb(1) ; lisv.pb(a[1]) ; 


		for(int i = 2 ; i <= n ; i++){
			if (maxval < a[i]){
				maxval = a[i] ; 
				lisi.pb(i) ; 
				lisv.pb(a[i]) ; 
			}
			else{
				I.pb(i) ;
				E.pb(i-1) ;  
			}
		} 
		I.pb(n+1) ; 
		E.pb(n+1) ; 

		
 
		while (q--){
			char ch ; ll L ,R , idx , X ; 
			cin >> ch ; 
			if (ch=='+'){

				cin >> idx >> X ; 
				ll oldval = a[idx] ; 
				a[idx] += X ; 

 				////////////////////// LIS UPDATE /////////////////////////////////////////
				if (binary_search(all(lisi),idx)){
					int ci = lb(all(lisi),idx)-lisi.begin() ; 
					
				
					int ubi = ub(all(lisv),a[idx])-lisv.begin() ;
					ubi -= 1; 
					lisv[ci] = a[idx] ; 

					if (ci+1 == ubi){
						lisi.erase(lisi.begin()+ci+1) ; 
						lisv.erase(lisv.begin()+ci+1) ; 
					}
					if (ci+1 < ubi){
						lisi.erase(lisi.begin()+ci+1,lisi.begin()+ubi) ; 
						lisv.erase(lisv.begin()+ci+1,lisv.begin()+ubi) ; 
					}
		
					

				} 
				else{
					int ci = ub(all(lisi),idx)-lisi.begin() ;

					if (a[idx] > lisv[ci-1]){
						if (ci==lisi.size()){
							lisi.pb(idx) ; 
							lisv.pb(a[idx]) ; 
						}
						else{
							lisi.insert(lisi.begin()+ci,idx) ; 
							lisv.insert(lisv.begin()+ci,a[idx]) ;
							int ubi = ub(lisv.begin()+ci+1,lisv.end(),a[idx])-lisv.begin() ; 
							ubi -=  1; 
							if (ci+1 == ubi){
								lisi.erase(lisi.begin()+ci+1) ; 
								lisv.erase(lisv.begin()+ci+1) ; 
							}
							if (ci+1 < ubi){
								lisi.erase(lisi.begin()+ci+1,lisi.begin()+ubi) ; 
								lisv.erase(lisv.begin()+ci+1,lisv.begin()+ubi) ; 
							}
							

						}

					}
					


				}

				////////////////////////////////////////////////////////////////////////////

 
				if (binary_search(all(I),idx)){        // start element of a sublist is updated. 
	
					int ci = lb(all(I),idx)-I.begin() ; 
 
					int ai = I[ci] ;   // here ai = idx ; 
					
					if (I[ci+1]-I[ci]==1){    //if the sublist has only one element. 
 
						if (a[ai-1] < a[ai]){
							I.erase(I.begin()+ci) ; 
							E.erase(E.begin()+ci) ;
						}
					}
					else{
						
						if (a[ai-1]<a[ai]){
							if (a[ai]<a[ai+1]){
								I.erase(I.begin()+ci); 
								E.erase(E.begin()+ci-1); 
							}
							else{
								I[ci] = I[ci]+1 ; 
								E[ci-1] = ai ;       // correct
							}
						}
						else{
							if (a[ai] >= a[ai+1]){
								I.insert(I.begin()+ci+1,ai+1) ; 
								E.insert(E.begin()+ci,ai) ; 
							}
						}
					}
					
					 
				}
				else{
					int ci = (ub(all(I),idx)-I.begin()) - 1 ; 
					int ai = idx ; 
					if (ai+1 == I[ci+1]){  // If the index is the end of a sublist. 
						// do nothing.
					} 
					else if (a[ai]>=a[ai+1]){    // 
						I.insert(I.begin()+ci+1,ai+1) ; 
						E.insert(E.begin()+ci,ai) ; 
					}
 
				}
			}
			if (ch == '?'){
				cin >> idx >> L >> R ; 
				ll ans = 0 ; 

				int ci = lb(all(lisi),idx)-lisi.begin() ; 
				int ai ; 
				if (ci == lisi.size()){
					ai = n+1 ; 
				}
				else{
					ai = lisi[ci] ; 
				} 

				for(int i = idx ; i < ai ; i++){
					if (L > R) break ;
					if (a[i]>=L){
						L = a[i]+1 ;
						ans++ ;  
					}
				}
				if (ci == lisi.size() || L>R){
					cout << ans << el ; 
					continue ; 
				}
				vli lbL = lb(lisv.begin()+ci,lisv.end(),L) ;
				if (lbL != lisv.end()){
					vli lbR = lb(lisv.begin()+ci,lisv.end(),R) ; 

					if (lbR==lisv.end()){
						ans += lbR-lbL ; 
					}
					else{
						ans += (lbR-lbL)+1 ; 
					}
				}
				//printv(lisi) ; 
				//printv(lisv) ; 
				cout << ans << el ; 	
 
			}
 
		}
	}
} 