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

int main() {
	int t ; cin >> t ; 
	while (t--){
		int n , k ; cin >> n>> k ; 
		vi v1 , v2 ; v1.resize(n) ; v2.resize(n) ; 
		forn(i,n){
			cin >> v1[i] ; 
		}
		forn(i,n){
			cin >> v2[i] ; 
		}
		sort(v1.begin(),v1.end()) ;
		sort(v2.begin(),v2.end(),std:: greater<int> ()) ; 
		int flag = 0 ; 
		forn(i,n){
			if (v1[i]+v2[i] < k){
				cout << "NO" << el ;
				flag = 1 ; 
				break ;  
			}
		}

		if (flag == 0){
			cout << "YES\n" ; 
		}

	} 
}