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

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

int main(){

	int t; sci(t) ; int kase  = 1 ; 
	while (t--){
		int E ; sci(E) ; int n  ;sci(n) ; 
		int a[n] ; forn(i,0,n) sci(a[i]) ; 

		
		sort(a,a+n) ; 
		
		int pre[n] ; pre[0] = a[0] ; 
		forn(i,1,n) 
			pre[i] = a[i] + pre[i-1] ; 

		int fd = 0 ; 
		int bd = n-1 ; 
		int maxHonor = 0 ; 
		
		int idx = (lower_bound(pre,pre+n,E)-(pre)) - 1; 
		if (idx < fd){
			printf("Case #%d: 0\n", kase++ );
			continue ; 
		}

		E -= pre[idx] ; 

		fd = idx+1 ; 
		maxHonor = idx+1 ; 
		//cout << E  << sp << maxHonor << el ; 
		int rem = bd-fd+1 ; 
		if (rem <= 1){
			printf("Case #%d: %d\n", kase++,maxHonor );
			continue ; 
		}
		for(int sz= 1 ; sz < rem ; sz++){
			int e = E ; 
			int honor = maxHonor ; 
			e += pre[bd] - pre[bd-sz] ; 
			honor -= sz  ; 
			if (honor < 0){
				continue ; 
			}
			//cout << sz << sp << e << sp ; 
			for(int i = fd ; i <= bd-sz ; i++){
				if (e > pre[i]-pre[fd-1]){
					honor++ ; 
				}
			}
			//cout << honor << el ;
			maxHonor = max(maxHonor,honor) ; 

		}

		printf("Case #%d: %d\n",kase++,maxHonor);
		////cout << "-----------------------------" << el ;


	}

	return 0 ; 


}