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
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 
	int n , k ; 
	cin >> n >> k ; 
	int a[n] ; 
	forn(i,0,n){
		cin >> a[i] ; 
	}
	int maxi = a[0] ; 
	int mini = a[0] ; 
	forn(i,1,n){
		maxi = max(maxi,a[i]) ; 
		mini = min(mini,a[i]) ; 
	}
	if (k == 1){
		cout << mini << el ; 
	}
	else if (k == 2){
		
			int mtfd[n] ;int mtbd[n] ; 
			clr(mtfd) ; clr(mtbd) ; 
			mtfd[0] = a[0] ; 
			mtbd[n-1] = a[n-1] ; 
			for(int i = 1 ; i < n ; i++){
				mtfd[i] = min(mtfd[i-1],a[i]) ; 
			}		
			for(int i = n-2 ; i>=0 ; i--){
				mtbd[i] = min(mtbd[i+1],a[i]) ; 
			}
			int ans = mtfd[0] ; 
			ans = max(ans,max(mtfd[0],mtbd[1])) ; 
			ans = max(ans,max(mtfd[n-2],mtbd[n-1])) ;

			for(int i = 1 ; i <=n-2 ; i++){
				ans = max(ans,max(mtfd[i],mtbd[i+1])) ; 
				ans = max(ans,max(mtfd[i-1],mtbd[i])) ; 
			}
			cout << ans << el ;
	}
	else if (k > 2){	
		cout << maxi << el ; 
	}

}