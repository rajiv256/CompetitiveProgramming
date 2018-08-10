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

	int n ; cin >> n ; 

	int ab[n] ; 
	int ba[n] ; 
	 
	for(int i = 0 ; i < n ; i++){
		cout << "? 0 " << i << el ; 
		cout.flush() ;  
		cin >> ab[i] ; 	
	}
	for(int i = 0 ; i < n ; i++){
		cout << "? " << i << " 0"<<  el ; 
		cout.flush() ;  
		cin >> ba[i] ; 	
	}
	
	vi act(n,0) ; int ans = 0 ;  vi p(n,0)  ;
	int b[n] ; int t[n] ; 
	
	for(int b0 = 0 ; b0 < n ; b0++){
		memset(t,0,sizeof(t)) ; 
		
		int fl = 0 ; 
		
		for(int i = 0 ; i < n ; i++){
			p[i] = b0^ba[i] ; 
			if (p[i]<n && t[p[i]]==0){
				t[p[i]] = 1 ; 
			}
			else{
				fl = 1 ;
				continue ;  
			}
		}

		for(int i = 0 ; i < n ; i++){
			if (p[i]>=n){
				continue ;
			}
			b[p[i]] = i ;  
		}
		for(int i = 0 ; i < n ; i++){
			
			if ((p[0]^b[i])!=ab[i]){
				fl = 1 ; 
				break ; 
			}
		}
		
		if (fl==0){
			ans++ ; 
			act = p ;   
		}
	}
	cout << "!" << el ; 
	cout << ans << el ; 
	forn(i,0,n){
		cout << act[i] << sp ; 
		cout.flush() ; 
	}
	cout << el ; 
	cout.flush() ; 


}