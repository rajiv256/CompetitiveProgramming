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

 ll compute(string s){
     ll ch[s.size()+1] ;
     memset(ch,0,sizeof ch) ;
     if (s[s.size()-1]=='h') ch[s.size()-1] = 1 ;
     for(int i = s.size()-2 ; i >= 0 ; i--){
         ch[i] = ch[i+1]+(s[i]=='h') ;
     }
     ll cnt = 0 ;
     for(int i = 0 ; i < s.size() ; i++){
         if (s[i] == 's'){
             cnt += ch[i] ;
         }
     }
     return cnt ;
 }
 pair<ll,ll> divide(string s){
     ll ns = 0 , nh = 0 ;
     for(auto it : s){
         if (it == 's') ns++ ;
         else nh++ ;
     }
     return mp(ns,nh) ;
 }
 bool cmp(const pair<ll,ll>& p1, const pair<ll,ll>& p2){
     return (p2.xx*p1.yy < p1.xx*p2.yy) ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    vector<pair<ll,ll> > v ;
    int n ; cin >> n ;
    ll ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        string s ; cin >> s ;
        ans += compute(s) ;
        v.pb(divide(s)) ;
    }


    sort(all(v),cmp) ;
    ll fh[v.size()+1] ;
    fh[v.size()] = 0 ;
    for(int i = v.size()-1 ; i >= 0 ; i--){
        fh[i] = fh[i+1] + v[i].yy ;
    }
    for(int i = 0 ; i < v.size()-1 ; i++){
        ans += v[i].xx*fh[i+1] ;
    }
    cout << ans << el ;

 }
