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
		a[0] = (1LL)<<61 ; 
		a[n+1] = 0 ; 
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i] ; 
		}
		vll I ; I.pb(0) ; I.pb(1) ;
		ll maxval = a[1] ; 
		for(int i = 2 ; i <= n ; i++){
			if (maxval < a[i]){
				maxval = a[i] ; 
			}
			else{
				maxval = a[i] ; 
				I.pb(i) ; 
			}
		} 
		I.pb(n+1) ; 
		
 
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

					if (a[idx] > lisi[ci-1]){
						if (ci==lisi.size()){
							lisi.pb(idx) ; 
							lisv.pb(a[idx]) ; 
						}
						else{
							lisi.insert(lisi.begin()+ci+1,idx) ; 
							lisv.insert(lisv.begin()+ci+1,a[idx]) ;
						}
					}

				}

				////////////////////////////////////////////////////////////////////////////

 
 
				if (binary_search(all(I),idx)){
					//cout << "here" << el ;
					int ci = lb(all(I),idx)-I.begin() ; 
 
					int ai = I[ci] ;   // here ai = idx ; 
					
					if (I[ci+1]-I[ci]==1){
 
						if (a[ai-1] < a[ai]){
							I.erase(I.begin()+ci) ; 
						}
					}
					else{
						
						if (a[ai-1]<a[ai]){
							if (a[ai]<a[ai+1]){
								I.erase(I.begin()+ci); 
							}
							else{
								I[ci] = I[ci]+1 ; 
							}
						}
						else{
							if (a[ai] >= a[ai+1]){
								I.insert(I.begin()+ci+1,ai+1) ; 
							}
						}
					}
					
					 
				}
				else{
					int ci = (ub(all(I),idx)-I.begin()) - 1 ; 
					int ai = idx ; 
					if (ai+1 == I[ci+1]){
						// do nothing.
					}
					else if (a[ai]>=a[ai+1]){
						I.insert(I.begin()+ci+1,ai+1) ; 
					}
 
				}
			}
			if (ch == '?'){
				cin >> idx >> L >> R ; 
				if (binary_search(all(I),idx)){
					int ci = lb(all(I),idx)-I.begin() ; 
					ll ans = 0 ; 
					for(int i = ci ; i < I.size()-1 ; i++){
						if (L > R){
							break ; 
						}
						ll* Llb = lb(a+I[i],a+I[i+1],L) ; 
						if (Llb == a+I[i+1]){
							continue ; 
						}
						else{
							ll* Rlb = lb(a+I[i],a+I[i+1],R) ; 
							if (Rlb == a+I[i+1]){
								L = a[I[i+1]-1]+1 ; 
								ans += Rlb-Llb ; 
							}
							else{
								ans += (Rlb-Llb)+1 ; 
								break ;
							}
						}
					}
					cout << ans << el ; 
 
				}
				else{
					ll ans = 0 ; 
					int ci = ub(all(I),idx)-I.begin()-1  ; 
					
					int ai = lb(a+I[ci],a+I[ci+1],a[idx])-a ; 
 
					ll* Llb = lb(a+ai,a+I[ci+1],L) ;
					int fl = 1 ; 
					if (Llb != a+I[ci+1]){
						ll* Rlb = lb(a+ai,a+I[ci+1],R) ; 
						if (Rlb == a+I[ci+1]){
							ans += (Rlb-Llb) ; 
							L = a[I[ci+1]-1]+1 ; 
						}
						else{
							ans += (Rlb-Llb)+1 ; 
							fl = 0 ; 
							cout << ans << el ; 
						}
 
					}
					if (fl==1 && L<=R){
						for(int i = ci+1 ; i < I.size()-1 ; i++){
							if (L > R){
								break ; 
							}
							ll* Llb1 = lb(a+I[i],a+I[i+1],L) ; 
							if (Llb1 != a+I[i+1]){
								ll* Rlb1 = lb(a+I[i],a+I[i+1],R) ; 
								if (Rlb1 == a+I[i+1]){
									L = a[I[i+1]-1]+1 ; 
									ans += Rlb1-Llb1 ; 
								}
								else{
									ans += (Rlb1-Llb1)+1 ; 
									break ;
								}
							}
						}
						cout << ans << el ; 
					}
				}
 
			}
 
		}
 
 
	}
}  