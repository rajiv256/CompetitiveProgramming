//http://www.spoj.com/problems/NAJPF/

/*
        Code written by rajiv.
        God speed!
*/
/* I solemnly swear that I am upto no good. */
 #include <iostream>
 #include <cstring>
 #include <vector>
 #include <map>
 #include <set>
 #include <stack>
 #include <queue>
 #include <deque>
 #include <sstream>
 #include <iomanip>
 #include <cassert>
 #include <sys/time.h>
 #include <algorithm>
 #include <bitset>
 #include <cmath>
 #include <functional>
 #include <cmath>
using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define sclf(x) scanf("%lf",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100005
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define PI 3.141592653589793

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ;




//////// KMP Module ////////////////////////////

string base, pat ;
int F[1000005] ;
vi ans ;
void build_failure_funtion(){
	F[0] = 0 ; F[1] = 0 ;

	for(int i = 2 ; i <= pat.size() ; i++){
		char newch = pat[i-1] ;
		int j = F[i-1] ;
		for(; ; ){
			char toCompareWith = pat[j] ;
			if (toCompareWith == newch){
				F[i] = j+1 ;
				break ;
			}
			else{
				if (j == 0){ F[i] = 0 ; break ; }
				else{
					j = F[j] ;
				}
			}
		}
	}
}

// Returns the starting indices of all the matches into the vector `ans`
// bst := Base string starting point
// pst := pattern string starting point
void KMP(int bst, int pst ){

	int bsti = bst ;
	int psti = pst ;
	int mLen = 0   ;

	while (bsti<base.size() && psti<pat.size() && base[bsti]==pat[psti]){
		bsti++ ; psti++ ; mLen++ ;
	}

	if (psti==pat.size()){
		ans.pb(bst-pst) ;
		KMP(bst+1,0);
		return ;
	}

	if (bsti==base.size()) return ;

	// We know mLen is the length of the pattern matched till now.
	if (psti > 0){
		KMP(bsti,F[psti]) ;
		return ;
	}
	else{
		KMP(bsti+1,0) ;
		return ;
	}
}

////////////////////////// END OF KMP MODULE  //////////////////////////

int main(){
	int t; sci(t) ;
	while (t--){
		cin >> base >> pat ;
		ans.clear() ;

		build_failure_funtion() ;
		int i = 0 ; int j = 0 ;

		KMP(0,0) ;
		if (ans.size()==0){
			cout << "Not Found\n\n" <<el;
			continue ;
		}
		cout << ans.size() << el;
		forn(i,0,ans.size()){
			cout << ans[i]+1 << sp ;
		}
		cout << el << el ;
	}


}
