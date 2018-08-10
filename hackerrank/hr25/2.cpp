/*
 		Resilience is the greatest of all virtues.
 		Code by rajiv
 */
 #include <iostream>
 #include <cstring>
 #include <vector>
#include <cstdio>
#include <stdio.h>
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
#include <string.h>

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

 ll dp[MAXN][26] ;
 ll fact[MAXN] ;
 ll po(ll a , int x){
     if (x == 0) return 1 ;
     ll temp = po(a,x/2) ;
     temp = (temp*temp)%MOD ;
     if (x&1) return (a*temp)%MOD ;
     return temp ;
 }



 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    string s ; cin >> s ;
    clr(dp) ;
    fact[0] = 1;
    FORN(i,1,MAXN) fact[i] = fact[i-1]*i %MOD ;
    dp[0][s[0]-'a'] = 1 ;
    FORN(i,1,s.size()){
        for(int j = 0 ; j < 26 ; j++){
            dp[i][j] = dp[i-1][j] ;
        }
        dp[i][s[i]-'a']++ ;
    }
    int q ; cin >> q ;
    while (q--){
        int l, r ; cin >> l >> r ;  r--; l-- ;
        VI even ; VI odd ;
        for(int j = 0 ; j < 26 ; j++){
            int val = dp[r][j] - ((l==0)?0:dp[l-1][j]) ;
            if (val == 0) continue  ;
            if (val&1){
                odd.pb(val) ;
            }
            else{
                even.pb(val) ;
            }
        }
        sort(all(odd)) ;
        sort(all(even)) ;
        ll sum = 0 ;
        FORN(i,0,even.size()){
            sum += even[i] ;
        }
        FORN(i,0,odd.size()){
            sum += odd[i]-1 ;
        }
        sum /= 2 ;
        ll ans = fact[sum] ;

        for(auto it : even){
            ans = (ans*po(fact[it/2],MOD-2)) %MOD ;
        }
        FORN(i,0,odd.size()){
            ans = ans*(po(fact[(odd[i]-1)/2],MOD-2)) % MOD ;
        }
        int sz = odd.size() ;
        ans = (ans * max(1,sz)) % MOD ;
        cout << ans << el ;
    }
    return 0 ;
 }
