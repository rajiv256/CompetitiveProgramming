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

int val(int x){
	if (x == 0){
		return 0 ; 
	}
	if (x < 4){
		return -1 ; 
	}
	if (x == 4){
		return 1 ; 
	}
	if (x > 4){
		if (x %4 == 0){
			return x/4 ; 
		}
		if (x%4 == 1){
			int sub = val(x-9) ; 
			if (sub == -1){
				return -1 ; 
			}
			else{
				return (1+sub) ; 
			}
		}
		if (x%4 == 2){
			int sub = val(x-6) ;
			if (sub == -1){
				return -1 ; 
			} 
			else{
				return 1+sub ; 
			}
		} 
		if (x%4 == 3){
			int sub = val(x-9) ;  
			if (sub == -1){
				return -1 ; 
			}
			else{
				return 1+sub ; 
			}
		}
	}
	return 0 ; 
}



int main(){
	cin.tie(0) ;
	ios_base::sync_with_stdio(false) ; 

	int q ; cin >> q ; 
	while (q--){
		int n ; cin >> n ; 
		int ans = val(n) ; 
		cout << ans << el ; 
	}
}