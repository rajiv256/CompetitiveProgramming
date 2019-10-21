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
#define MAXN 100005
#define inf 10000000010
#define mod 1000000007
#define last_set_bit(x) log2((x)&(-x))
#define add(x,y) (x)=((x)+(y))%MOD
#define PI 3.141592653589793

typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;


int main(){
    int n ; cin >> n ; 
    ll s[n+1] ; 
    forn(i,0,n) cin >> s[i] ; 

    sort(s, s+n) ; 
    auto it = unique(s, s+n) ; 
    n = it - s ; 
    int q ; cin >> q ; 
    while (q--){
        ll l , r ; cin >> l >> r ;
        ll ans = 0 ;  
        int idx = 1 ; 
        ll left = s[0] + l ;  ll right = s[0] + r ;
        ans += right - left + 1 ; 
        ll curr = s[0] + r -l + 1  ;  
        while (idx < n){

            int tmp = idx ; 
            idx = upper_bound(s, s+n, curr) - s ;

            if (idx > n) break ; 
            
            if (curr <= s[idx-1]+r-l){
                ans += s[idx-1] + r -l - curr + 1 ; 
                curr = s[idx-1] + r -l + 1 ; 
            } 
            else{
                if (idx == n) break ; 
                ans += r-l+1 ; 
                curr = s[idx] + r - l + 1 ;
            }

        }
        cout << ans << " " ; 
        
    }
    return 0 ; 

}































//}
