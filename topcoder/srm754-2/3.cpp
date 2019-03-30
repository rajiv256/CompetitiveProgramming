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

#define xx first
#define yy second
#define ll long long
#define ld long double
#define el (char)0x0A
#define sp " "
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define clr(x) memset((x),0,sizeof(x))
#define uint unsigned int
#define CASET  int t;cin>>t;while(t--)
#define forn(i,x,y) for(int i=x;i<y;i++)
#define maxn 100005
#define inf 10000000010
#define mod 1000000007
#define last_set_bit(x) log2((x)&(-x))
#define add(x,y) (x)=((x)+(y))%MOD
#define PI 3.141592653589793
#define append push_back

typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

class MoreSquares {
	public:

	bool check(PII p3, PII p4, vector<PII >& v){
		int cnt = 0 ;
		if (!binary_search(all(v), p3)) cnt++ ;
		if (!binary_search(all(v), p4)) cnt++ ;
		return (cnt == 1) ;
	}

	int countLocations(int N, int SX, int SY, vector <int> Xprefix, vector <int> Yprefix) {
		set<PII > s ;
		VI x, y ;
		for(int i = 0 ; i < Xprefix.size() ; i++){
			x.append(Xprefix[i]) ;
			y.append(Yprefix[i]) ;
		}
		for(int i = Xprefix.size() ; i < N ; i++){
			x.append((x[x.size()-1] * 47 + 42) % SX );
			y.append((y[y.size()-1] * 47 + 42) % SY) ;
		}
		for(int i = 0 ; i < N ; i++){

			s.insert(mp(x[i],y[i])) ;
		}
		VPII v = VPII(all(s)) ;
		sort(all(v)) ;

		set<PII> ans ;
		for(int i = 0 ; i < v.size() ; i++){
			for(int j = i+1 ; j < v.size() ; j++){
				PII p1 = v[i] ;
				PII p2 = v[j] ;

				int dcos = abs(p2.yy - p1.yy) ;
				int dsin = abs(p1.xx - p2.xx) ;
				int sign = ((p1.xx-p2.xx>=0)?1:-1) * ((p2.yy-p1.yy>=0)?1:-1) ;
				dcos  = sign*dcos ;

				PII p3 = mp(p1.xx + dcos, p1.yy + dsin) ;
				PII p4 = mp(p2.xx + dcos, p2.yy + dsin) ;

				if (check(p3, p4, v) && !(p1 == p3 || p1==p4 || p2==p3 || p2==p4)){
					if (binary_search(all(v),p3)) ans.insert(p4) ;
					else ans.insert(p3) ;
				}
				p3    = mp(p1.xx - dcos, p1.yy - dsin) ;
				p4    = mp(p2.xx - dcos, p2.yy - dsin) ;

				if (check(p3, p4, v) && !(p1 == p3 || p1==p4 || p2==p3 || p2==p4)){
					if (binary_search(all(v),p3)) ans.insert(p4) ;
					else ans.insert(p3) ;
				}
			}
		}
		return ans.size() ;


	}
};

// Powered by PopsEdit
