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
	int n , k ; cin >> n >> k ; 
	vi s ;  int a ; 
	while (n--){
		cin >> a ; 
		s.push_back(a) ; 
	}
	int sum = 0 ; int cnt ;  
	for (vi :: iterator it = s.begin() ; it != s.end() ; it++ ){
		sum += (*it) ;
		cnt ++ ;  
		if (sum > k){
			sum -= (*it) ; 
			cnt -= 1 ; 
			cout << cnt << el ; 
			break ; 
		}
		else if (sum == k){
			cout << cnt << el ; 
			break ;
		}
	}
	return 0 ; 
}
