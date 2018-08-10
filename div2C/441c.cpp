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
    int n , m , k ; cin >> n >> m >> k ;
    VPII v ;
    int r = 1 ; int c = 1 ;int inc = 1 ;
    while (r <= n){

        while (c >0 && c <= m){
            v.pb(mp(r,c)) ;
            c += inc ;
        }
        if (inc == 1){
            c = m;
        }
        else{
            c = 1 ;
        }
        inc = -inc ;
        r++ ;
    }
    // for(int i= 0 ; i < v.size() ; i++){
    //     cout << v[i].xx << sp << v[i].yy << sp ;
    // }
    // cout << el ;
    vector<VPII > blocks ;
    for(int i = 0 ; i < v.size()/2 ; i++){
        VPII temp ;
        temp.pb(v[2*i]) ; temp.pb(v[2*i+1]) ;
        blocks.pb(temp) ;
    }
    if (v.size()%2 == 1){
        blocks[blocks.size()-1].pb(v[v.size()-1]) ;
    }
    VPII last;
    for(int i = 0 ; i < k-1 ; i++){
        cout << blocks[i].size() << sp ;
        for(int j = 0 ; j < blocks[i].size() ; j++){
            cout << blocks[i][j].xx << sp << blocks[i][j].yy << sp ;
        }
        cout << el ;
    }
    for(int i = k-1 ; i < blocks.size() ; i++){
        last.insert(last.end(),all(blocks[i])) ;
    }
    cout << last.size() << sp ;
    for(int i = 0 ; i < last.size() ; i++){
        cout << last[i].xx << sp << last[i].yy << sp ;
    }
    cout << el ;

    return 0 ;

 }
