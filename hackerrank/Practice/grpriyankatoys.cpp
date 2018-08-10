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
	int n ; cin >> n ; 
	vi v; v.resize(n) ; 
	forn(i,n){
		cin >> v[i] ; 
	}
	sort(v.begin(),v.end()) ; 
	int w = v[0] ; int cnt = 1 ; 
	for(int i = 1 ; i < n ; i++){
		if (v[i] <= w+4){
			continue ; 
		}
		else{
			w = v[i] ; 
			cnt ++ ; 
		}
	}
	cout << cnt << el ; 
}