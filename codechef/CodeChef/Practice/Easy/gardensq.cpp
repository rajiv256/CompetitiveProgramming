#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <algorithm>

using namespace std ;

typedef vector<int> vi ; 
typedef vector<char> vc ; 

#define vvc vector<vector<char> > 
#define vvi vector<vector<int> > 
#define forn(i,n) for (int i = 0 ; i < n ; i++)

bool check(vvc& gard,int sti , int sty , int off,int n,int m){
	char c = gard[sti][sty] ; 
	if (sti+off < n && sty+off < m)
	if ((c == gard[sti][sty+off]) && (c == gard[sti+off][sty]) && (c == gard[sti+off][sty+off]))
		return true ; 
	return false ; 
}






int main() {
	int t ; cin >> t ; 

	while (t--){
		int n , m ; cin >> n >> m ; 
		vc v(m,'@') ; 
		vvc gard(n,v) ; 
		forn(i,n){
			string s ; cin >> s ; 
			forn(j,m){
				gard[i][j] = s[j] ; 
			}
		}

		int cnt = 0 ; 
		int mini = min(m,n) ; 
		forn(i,n){
			forn(j,m){
				//cout << "Gone!!\n"<< i << " " << j << endl  ;
				for (int k = 1 ; k <= mini-1 ; k++){
					//cout << k << " strt"<< endl ; 
					if (check(gard,i,j,k,n,m)){
						cnt++ ; 
					}
					//cout << k << " end" << endl ; 
				}
			}
		}
		cout << cnt << endl ; 

	}
	return 0 ; 
}
