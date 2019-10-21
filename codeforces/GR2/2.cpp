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
#define inf 10000000010
#define mod 1000000007
#define last_set_bit(x) log2((x)&(-x))
#define add(x,y) (x)=((x)+(y))%MOD
#define PI 3.141592653589793

typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;


bool check(VI& v, int h){
    int curr = 0 ;
    int idx = 0 ;
    int sz = v.size() ;
    if (sz&1) sz-- ;
    while (idx < sz-1){
        curr += max(v[idx], v[idx+1]) ;
        if (curr > h) return false ;
        idx += 2 ;
    }
    if (v.size()%2 == 1){
        curr += v[v.size()-1] ;
        if (curr > h) return false;
    }


    return true ;

}


int main(){
    int n , h ; cin >> n >> h ;
    int a[n] ; forn(i,0,n) cin >> a[i] ;
    if (n == 1){
        cout << "1" << el ;
        return 0 ;
    }
    VI v ; int mx = 1 ;
    for(int i = 0 ; i < n ; i++){
        v.pb(a[i]) ;
        sort(all(v)) ;
        reverse(all(v)) ; 
        mx = (check(v, h)?i+1:mx) ;
    }
    cout << mx << el ;
    return 0 ;


}
































//}
