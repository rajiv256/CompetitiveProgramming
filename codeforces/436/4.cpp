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
	int n ; sci(n) ; 
	int a[n+1] ; int cnt[n+1] ; clr(cnt) ; 
	
	forn(i,1,n+1){
		sci(a[i]) ; 
		cnt[a[i]]++ ; 
	}
	vector<int> need ; 
	forn(i,1,n+1){
		if(cnt[i]==0){
			need.pb(i) ; 
		}
	}
	
	int j = 0 ; 
	vb seen(n+1,false) ; int ans = 0 ; 

	for(int i = 1 ; i <= n ; i++){

		if (cnt[a[i]] > 1){
			if (a[i] > need[j]){
				cnt[a[i]]-- ; 
				a[i] = need[j] ; 
				j++ ; 
				ans++ ; 
				continue ; 
			}
			if (a[i] < need[j]){
				if (seen[a[i]]){
					cnt[a[i]]-- ; 
					a[i] = need[j] ; 
					j++ ; 
					ans++ ; 
					continue ; 
				}
				else{
					seen[a[i]] = true ; 
					continue ; 
				}
			}
		}
	}
	cout << ans << el ; 
	for(int i = 1 ; i <= n ; i++){
		cout << a[i] << sp ; 
	}
	cout  << el ; 
	



}