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



#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp " " 
#define el "\n"



int main() {
	int n ; cin >> n ; 
    int a , b ; sii m ; 
	int i = 1 ; 
	while (n--){
		cin >> a >> b ; 
		m.insert(make_pair(a+b,i)) ;  
		i += 1 ; 

	}

	for(sii :: iterator it = m.begin() ; it!= m.end() ; it++ ){
		cout << (*it).second << sp ; 
 	}
 	cout << el ; 
	return 0 ; 

}