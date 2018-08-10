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
#define lld long long int 

int abs(int a){
	if (a >= 0)
		return a ; 
	return -a ; 
}
int main() {
	int n ; cin >> n ; 
	vi v ; v.resize(n) ; 
	forn(i,n) {
		cin >> v[i] ; 
	}
	sort(v.begin(),v.end()) ; 
	int p , q ; cin >> p >> q ; 
	int diff = 0 ; int maxi = -1 ; int mid = 0 ; 
	int ans = -1 ; 
	forn(i,n-1){	
		mid= (v[i]+v[i+1])/2 ; 
		if (mid >= p && mid <= q){
			if (maxi < min(abs(mid-v[i]),abs(v[i+1]-mid))){
				maxi = min(abs(mid-v[i]),abs(v[i+1]-mid)) ; 
				ans = mid ; 
			}
			
		}
		if (mid < p ){
			if (p <= v[i+1]){
				if (maxi < v[i+1]-p){
					maxi = v[i+1]-p ; 
					ans = p ; 
 				}  
			}
			else{
				continue ; 
			}
		}
		if (mid > q){
			if (q >= v[i]){
				if (maxi < q -v[i]){
					maxi = q-v[i] ; 
					ans = q ; 
				}
			}
		}

	} 
	if (p <= v[0]){
		if (maxi <= v[0]-p){
			maxi = v[0]- p ; 
			ans = p ; 
		}
	}
	if (q > v[n-1]){
		if (maxi < q-v[n-1]){
			maxi = q - v[n-1] ; 
			ans = q ; 
		}
	}

	cout << ans << el ; 
	return 0 ; 


}