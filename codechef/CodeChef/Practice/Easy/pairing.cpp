#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int>  vi ; 
typedef vector<pair<int,int> > vp ;
typedef vector<bool> vb ; 

#define forn(i,n) for(int i = 0 ; i < n ; i++)
#define lld long long int 

int main() {
	int t ; cin >> t ; 
	while (t--){
		int n , m  ; cin >> n >> m ; 
		vp v ; v.resize(m) ; int i = 0 ; int a , b ; 
		while (i < m ){

			cin >> a >> b ; 
			pair<int,int> p = make_pair(a,b) ; 
			v[i] = p ;   
			i++ ; 
		}
		vi res ; 
		vb pre(n,false) ; 
		//cout << endl ; 
		for (int i = m-1 ; i>=0 ; i--){
			//cout << v[i].first << " $$ " << v[i].second << endl ; 
			if (pre[v[i].first] == false && pre[v[i].second] == false){
				res.push_back(i) ; 
				pre[v[i].first] = true ; 
				pre[v[i].second] = true ; 
			}
		}
		for (int i = res.size()-1 ; i >= 0 ; i--){
			cout << res[i] << " " ; 
		}
		cout << endl ; 
	}
	return 0 ; 
}

