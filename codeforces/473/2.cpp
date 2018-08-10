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
    int n , m , k ; cin >> n >> k >> m ;
    int a[n+1] ;
    string b[n+1] ;
    map<string,int> sti ;
    for(int i = 1 ; i <= n ; i++){
        cin >> b[i] ;
        sti[b[i]] = i ;
    }
    for(int i = 1; i <= n ; i++){
        cin >> a[i] ;
    }
    int li[n+1] ;
    int ls[n+1] ;
    for(int i = 1 ; i <= k ; i++){
        li[i] = -1 ;
        ls[i] = -1 ;
    }
    map<int,int> ma ;
    for(int i = 1 ; i <= k ; i++){
        int len ; cin >> len ; int idx ;
        for(int j = 0 ; j < len ; j++){
            cin >> idx ;
            ma[idx] = i ;
            if (li[i] == -1){
                li[i] = idx ;
                ls[i] = a[idx] ;
            }
            else{
                if (a[idx] < ls[i]){
                    ls[i] = a[idx] ;
                    li[i] = idx ;
                }
            }
        }
    }
    ll sum = 0 ;
    for(int i = 0 ; i < m ; i++){
        string s;  cin >> s ;
        int idx = sti[s] ;
        sum += ls[ma[idx]] ;
    }
    cout << sum << el ;

 }
