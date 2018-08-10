#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mi ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pi pair<int,int>
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el "\n"
#define ll long long
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x)
#define MXN 1000003
#define gc getchar_unlocked

int main(){
	
	int t ; sci(t) ;
	
	while(t--){
		int ans = 0 ; 
		int n ; sci(n) ; 
		int a[n] ; int b[n] ; 
		int x[n] ; 
		forn(i,n){
			sci(a[i]) ; 
			
		}
		forn(i,n){
			sci(b[i]) ; 
		}
		x[0] = a[0] ; 
		for(int i = 1 ; i < n ; i++){
			x[i] = a[i]-a[i-1] ; 
		}
		forn(i,n){
			if (b[i] <= x[i]){
				ans++ ; 
			}
		}
		cout << ans << el ; 
	}
	return 0 ; 
}



























