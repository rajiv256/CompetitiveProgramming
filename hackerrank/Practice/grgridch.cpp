#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std ;
typedef vector<int> vi ; 
typedef vector<pair<int,int> > vp ; 
typedef vector<pair<int,pair<int,int> > > vpp ; 
typedef vector<bool> vb ; 

#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> > 
#define INF 1000000

int main() {
	int t ; cin >> t ; 
	while (t--){
		int n ; cin >> n ; 
		vector<char> vc(n,'~') ; 
		vector<vector<char> > a(n,vc) ; 
		forn(i,n){
			forn(j,n){
				cin >> a[i][j] ; 
			}
		}
		forn(i,n){
			sort(a[i].begin(),a[i].end()) ; 
		}
		/*forn(i,n){
			forn(j,n){
				cout << a[i][j] << " " ; 
			}
			cout << endl ; 
		}*/
		int flag = 0 ; 
		forn(i,n){
			forn(j,n-1){
				if (a[j+1][i] >= a[j][i])
					continue ; 
				else {
					cout << "NO\n" ; 
					flag = 1 ; 
					break ; 
				}
			}	
			if (flag == 1)
				break ; 
		}
		if (flag == 0){
			cout << "YES\n" ; 
		}
	}
	return 0 ; 
}