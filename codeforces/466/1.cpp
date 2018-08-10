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
 #define FORN(i,x,y) for(int i=x;i<y;i++)
 #define MAXN 100005
 #define INF 10000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;
 bool cmp(PII& p1, PII& p2){
     return (p1.xx < p2.xx)?true:(p1.xx==p2.xx)?(p1.yy>p2.yy):false ;
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n , d ; cin >> n >> d ;
    int a[n] ;
    FORN(i,0,n){
        cin >> a[i] ;
    }
    sort(a,a+n) ;
    if (n == 1){
        cout << "0" << el ;
        return 0 ;
    }
    VPII v ;
    int l = 0 ; int r = n-1 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            if (abs(a[i]-a[j])<=d){
                v.pb(mp(i,j)) ;
            }
        }
    }
    sort(all(v),cmp) ;
    cout << n-(v[0].yy-v[0].xx+1) << el ;
    return 0 ; 
 }
