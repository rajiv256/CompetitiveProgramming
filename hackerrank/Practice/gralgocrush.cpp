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

int main(){
	int n , m ; cin >> n >> m ; 
    vector<lld> ba (n,0) ; int a , b , k ;  
    while (m--){
    	cin >> a >> b >> k ; a-- ; b-- ;
    	ba[a] += k ; 
    	if (b < n-1){
    		ba[b+1] -= k ; 
    	}
    }
    lld ans = ba[0] ; 
    for (int i = 1 ; i < n ; i++){
    	ba[i] += ba[i-1] ;
    	ans = max(ans,ba[i]) ;  
    }
    cout << ans << el ;
    return 0 ; 

}