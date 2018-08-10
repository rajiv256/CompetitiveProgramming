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
 #define abs(x) ((x<=0)?(-x):(x))
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

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n ; cin >> n ;
    int a[n+2] ;
    map<int,int> m ;
    FORN(i,1,n+1){
        cin >> a[i] ;
        m[a[i]] = i ;
    }
    int premax[n+2] , sufmax[n+2] ;
    int ans[n+2] ;
    premax[0] = -1 ; sufmax[n+1] = -1 ;
    for(int i = 1 ; i <= n ; i++){
        premax[i] = max(a[i],premax[i-1]) ;
    }
    for(int i = n ; i >= 1 ; i--){
        sufmax[i] = max(a[i],sufmax[i+1]) ;

    }

    for(int pos = 1 ; pos <= n ; pos++){
        int X = premax[pos-1] ;
        int Z = sufmax[pos+1] ;
        int Y = a[pos] ;
        int cnt = 0 ; int until = 0 ;
        for(int i = pos+1 ; i <= n ; i++){
            if (a[i]>X && a[i]<Y && until < a[i]){
                cnt++ ;
                until = a[i] ;
            }
            if (a[i]>Y) break ;
        }
        if (Y > X) cnt-- ;
        ans[pos] = cnt ;
    }
    int maxi = a[1] ; int idx = 1 ;
    for(int i = 2 ; i <= n ; i++){
        if (ans[idx] < ans[i]){
            idx = i ;
            maxi = a[idx] ;
        }
        else if (ans[idx]==ans[i]){
            if (maxi > a[i]){
                idx = i ;
                maxi = a[idx] ;
            }
        }
    }
    cout << maxi << el ;
 }
