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

 bool mc[52] , mr[52] ;
 vector<int> rows[52] ;
 vector<int> cols[52] ;
 int a[52][52] ;
 bool equalss(VI& v1, VI&v2){
     if (v1.size()!=v2.size()) return false ;
     for(int i = 0 ; i < v1.size() ; i++){
         if (v1[i] != v2[i]){
             return false ;
         }
     }
     return true ;
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    memset(mc,false,sizeof mc) ;
    memset(mr,false,sizeof mr) ;
    int n , m ; cin >> n >> m  ;
    char c ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m  ; j++){
            cin >> c ;
            if (c=='#') a[i][j] = 1 ;
            else a[i][j] = 0 ;
        }
    }
    for(int  i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if (a[i][j] == 1) rows[i].pb(j) ;
        }
    }
    for(int  j = 0 ; j < m ; j++){
        for(int i = 0 ; i < n ; i++){
            if (a[i][j] == 1) cols[j].pb(i) ;
        }
    }
    bool b = true ;

    for(int i = 0 ; i < n ; i++){
        if (!mr[i]){
            VI icols ;
            if (rows[i].size() > 0){
                icols = vector<int>(all(rows[i])) ;
            }
            for(int col = 0 ; icols.size() != 0 && col < icols.size()-1 ; col++){
                if (!equalss(cols[icols[col]], cols[icols[col+1]])){
                    cout << "No" << el ;
                    return 0 ;
                }

            }
            VI irows ;
            if (icols.size()>0){
                irows = vector<int>(all(cols[icols[0]])) ;
            }
            for(int row = 0 ; irows.size()!=0 && row < irows.size()-1 ; row++){
                if (!equalss(rows[irows[row]],rows[irows[row+1]])){
                    cout << "No" << el ;
                    return 0 ;
                }
            }
            for(auto it : irows){
                if (mr[it]) { cout << "No" << el ; return 0 ; }
                mr[it] = true ;
            }
            for(auto it : icols){
                if (mc[it]) { cout << "No" << el ; return 0 ; }
                mc[it] = true ;
            }
        }
    }

    cout << "Yes" << el ;
    return 0 ;

 }
