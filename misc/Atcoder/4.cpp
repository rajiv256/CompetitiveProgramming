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
 #include <climits>

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
 const int N = 100050 ;

string comp(string s1, string s2){
    if (s1.size() > s2.size()) return s1 ;
    else if (s1.size()<s2.size()) return s2 ;
    else {
        for(int i = 0 ; i < s1.size() ; i++){
            if (s1[i] > s2[i]) return s1 ;
            else if (s1[i] < s2[i]) return s2 ;
        }
        return s1 ;
    }

}

int main(){
     map<int, int> m ;
     m[1] = 2; m[2] = 5 ; m[3] = 5 ; m[4] = 4 ; m[5] = 5 ; m[6] = 6 ; m[7] = 3 ; m[8] = 7 ; m[9] = 6 ;
     ll N , M ; cin >> N >> M ;
     int a[M] ;
     for(int i = 0 ; i < M ; i++){
         cin >> a[i] ;
     }
     string L[N+1] ;
     L[0] = "";
     for(int i = 0 ; i <= N ; i++){
         L[i] = "" ;
     }

     for(int i = 0 ; i <= N ; i++){
         for(int j = 0 ; j < M ; j++){
             if (i != 0 && L[i] == "") continue ;
             if (i+m[a[j]] <= N){
                 L[i+m[a[j]]] = comp(L[i+m[a[j]]], L[i]+(char)('0'+a[j])) ;
                 // cout << i << sp << j << sp << i+m[a[j]] <<  sp << L[i+m[a[j]]] << el ;
            }
         }
     }
     cout << L[N] << el ;
}
