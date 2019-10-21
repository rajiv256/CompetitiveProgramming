/*
	Resilience is the greatest of all virtues.
	Code by rajiv
*/
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
#define inf 1000000000
#define mod 1000000007
#define last_set_bit(x) log2((x)&(-x))
#define add(x,y) (x)=((x)+(y))%MOD
#define PI 3.141592653589793

typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

int main(){
	int n , t ; cin >> n >> t; 
	int s[n] , d[n] ; 
	forn(i,0,n){
		cin >> s[i] >> d[i] ; 
	}
	int mini = inf ; int ans = -1 ; 
	for(int i = 0 ; i < n ; i++){
		if (t >= s[i]){
			int p = ceil((double)(t-s[i])/d[i]) ;

			// cout << p << sp << s[i] + p*d[i] << el ;  
			if (mini > s[i] + p*d[i]){
				mini = s[i] + p*d[i] ; 
				ans = i+1 ; 
			}
		}
		if (t < s[i]){
			int p = 0 ; 
			//cout << s[i] << el ; 
			if (mini > s[i]){
				mini = s[i]  ; 
				ans = i+1 ; 
			}
		}
	}
	cout << ans << el ; 
	return 0 ; 


}
































//}
