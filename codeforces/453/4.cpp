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
    int  n ; cin >> n ;
    if (n == 1){
        cout << "1" << el
        << "0 1" << el
        << "0" << el
        <<  "1" << el ;
    }

    else{
        VI va(1000,0) ;
        VI vb(1000,0) ;
        VI temp(1000,0)  ;
        va[0] = 0 ; va[1] = 1 ;
        vb[0] = 1 ;
        int step = 1 ;
        while (step < n){
            for(int i = 0 ; i < temp.size() ; i++){
                temp[i] = va[i]  ;
            }
            for(int i = va.size()-1 ; i-1 >= 0 ; i--){
                va[i] = va[i-1] ;
            }
            va[0] = 0 ;
            for(int i = 0 ; i < vb.size() ; i++){
                va[i] += vb[i] ;
                if (va[i]==2 || va[i] == -2){
                    va[i] = 0 ;
                }
            }
            for(int i = 0 ; i < vb.size() ; i++){
                vb[i]  = temp[i] ;
            }
            step++ ;
        }
        int sva = va.size()-1  ; int svb = vb.size()-1 ;
        while (va[sva]==0) sva-- ;
        while (vb[svb]==0) svb-- ;
        cout << sva << el ;
        for(int i = 0 ; i <= sva ; i++){
            cout << va[i] << sp ;
        }
        cout << el << svb << el ;
        for(int i = 0 ; i <= svb ; i++){
            cout << vb[i] << sp ;
        }
        cout << el ;
    }
    return 0 ;
}
