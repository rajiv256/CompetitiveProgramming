/* Resilience is the greatest of all virtues */
 /* Code by rajiv */
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
 #define MAXN 100005
 #define INF (int)1E10+1
 #define MOD (int)1E9+7
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	 cin.tie(nullptr) ;
     string s ; cin >> s ;
     int n = s.size() ;
     int acnt[n+1] ;
     int qcnt[n+1] ;

     memset(acnt,0,sizeof(acnt)) ;
     memset(qcnt,0,sizeof(qcnt)) ;

     for(int i = s.size()-1 ; i >= 0 ; i--){
         qcnt[i] = qcnt[i+1] ;
         acnt[i] = acnt[i+1] ;
         if (s[i]=='Q'){
             qcnt[i] = qcnt[i+1]+1 ;
         }
         if (s[i] == 'A'){
             acnt[i] = acnt[i+1]+1 ;
         }
     }
     ll ans = 0 ;
     for(int i = 0 ; i < s.size() ; i++){
         for(int j = i+1 ; j < s.size() ; j++){
             if (s[i]=='Q' && s[j]=='A'){
                 ans += qcnt[j+1] ;
             }
         }
     }
     cout << ans <<el ;



 }
