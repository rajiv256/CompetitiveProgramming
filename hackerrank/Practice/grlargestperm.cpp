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
	int n , k ; cin >> n >> k ; 	
	vi v  ; v.resize(n) ; 
	mii m ; int a ; 
	forn(i,n){
		cin >> a;
		v[i] = a ; 
		m[a] = i ; 
	}
	int nswap = 0 ; int curnum = n ;  
	while (nswap < k && curnum > 0){
		 //cout << curnum << el ; 
		if (m[curnum] != n-curnum){
			//cout << curnum << el ; 
			int temp1 = m[curnum] ; 
			int temp2 = v[n-curnum] ; 
			m[curnum] = n-curnum ; 
			m[v[n-curnum]] = temp1 ; 
			int temp3 = v[n-curnum] ; 
            v[n-curnum] = curnum ; 
            v[temp1] = temp3 ;  
            nswap += 1 ;
			curnum -= 1 ;  

		}
		else {
			curnum -= 1 ; 
		}
	}
	mii mf ; 
	for(mii::iterator it = m.begin() ; it != m.end() ; it++){
		mf[(*it).second] = (*it).first ;
	}
	for (mii :: iterator it = mf.begin() ; it != mf.end() ; it++){
		cout << (*it).second << sp ; 
	}
	cout << el ; 
	return 0 ; 

}