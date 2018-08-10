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

/*lld solve(vp& hcuts , vp& vcuts, int hindex , int vindex , int nhcuts , int nvcuts,int maxHcuts,int maxVcuts){
	//cout << hindex << sp << vindex << sp << sp << hcuts.size() << sp << vcuts.size() << el ;
    if (hindex >= hcuts.size() && vindex >= vcuts.size()){
		
		return -1 ; 
	}
	if (hindex < hcuts.size() && vindex == vcuts.size()){
		
		return (solve(hcuts,vcuts,hindex+1,vindex,nhcuts+1,maxVcuts,maxHcuts,maxVcuts) 
		+hcuts[hindex].first * (nvcuts+1)) ; 
	}
	if (hindex == hcuts.size() && vindex < vcuts.size()){
		return (solve(hcuts,vcuts,hindex,vindex+1,maxHcuts,nvcuts+1,maxHcuts,maxVcuts)
		 + vcuts[vindex].first*(nhcuts+1)) ; 
	}
    
	
    
    
    lld a1 = solve(hcuts,vcuts,hindex+1,vindex,nhcuts+1,nvcuts,maxHcuts,maxVcuts) ;
    lld a2 = solve(hcuts,vcuts,hindex,vindex+1,nhcuts,nvcuts+1,maxHcuts,maxVcuts) ; 
    //return a1 ; 
    return (min(hcuts[hindex].first * (nvcuts+1) + a1 , vcuts[vindex].first * (nhcuts+1) + a2)) ; 
	 
}
*/



int main() {
	int t ; cin >> t ; 
	while (t--){
		int m , n ; cin >> m >> n ; 
		vi x ; vi y ;  x.resize(m-1) ; y.resize(n-1) ; 
		vp hcuts,vcuts ; hcuts.resize(m-1) ; vcuts.resize(n-1) ;  
	
		forn(i,m-1){
			cin >> x[i] ; 
			hcuts[i] = make_pair(x[i],i) ;  
		}
		forn(i , n-1){
			cin >> y[i] ; 
			vcuts[i] = make_pair(y[i],i) ; 
		}
		sort(vcuts.begin() , vcuts.end(),std::greater<pair<int,int> >()) ; 
		sort(hcuts.begin() , hcuts.end(),std::greater<pair<int,int> >()) ; 

		/*forn(i,hcuts.size()){
			cout << "< "<<hcuts[i].first << "," << hcuts[i].second << " >" ; 
		}
		cout << el << el; 
		forn(i,vcuts.size()){
			cout << "< "<<vcuts[i].first << "," << vcuts[i].second << " >" ; 
		}
*/
		int segs = 1 , nhcuts = 0 , nvcuts = 0 ; 

		lld ans = solve(hcuts,vcuts,0,0,0,0,m-1,n-1) ; 
		cout << ans%(1000000007) << el ; 



	}
	return 0 ; 
}