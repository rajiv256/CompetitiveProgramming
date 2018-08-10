#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std ;
typedef vector<int> vi ; 
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ; 
typedef vector<pair<int,pair<int,int> > > vpp ; 
typedef vector<bool> vb ;
typedef set<int> si ; 
typedef map<int,int> mii ; 
typedef map<int,vector<int> > miv ; 
typedef unsigned long long ull ; 


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp " " 
#define el "\n"
#define ll long long int 

int main() {
	int n , k ; cin >> n ; 
	cin >> k ; 
	vi v(n,0) ;
	forn(i,n){
		cin >> v[i] ; 
	}
	sort(v.begin(), v.end()) ; 

	int ans = 1E9 + 1 ;
	forn(i,n-k+1){
		ans = min(ans,v[i+k-1]-v[i]) ; 
	} 
	cout << ans << el ; 
	return 0 ; 

}