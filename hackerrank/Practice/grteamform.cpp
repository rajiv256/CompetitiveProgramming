#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std ;
#include <bits/stdc++.h> 
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
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()



int main(){
	int t ; cin >> t ; 
	while (t--){
		int n ; cin >> n ; 
		if (n == 0){
            cout << "0\n" << el ; 
        }
        vi v ; v.resize(n) ; 
		forn(i,n){
			cin >> v[i] ; 
		}
		map<int,priority_queue<int,vi,greater<int> > > val ; 
		sort(all(v)) ; 
		for (int i = 1 ; i < n ; i++){
			int temp = v[i] ; 
			int now = 0 ; 
			auto it = val.find(temp-1) ; 
			if (it != val.end()){
				if ((*it).second.size()){
					now = (*it).second.top() ; 
					(*it).second.pop() ; 
				}
			} 
			now++ ; 
			val[temp].push(now) ; 
		}

		int ans = INT_MAX ; 
		for (auto x : val ){
			if ((*x).size()){
				ans = min(ans,(*x).second.top()) ; 
			}
		}
		if (ans >= INT_MAX){
			ans = 0 ; 
		}
		cout << ans << el ; 




	}






}