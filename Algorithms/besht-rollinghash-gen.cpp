// 11855 UVA 4

/* I solemnly swear that I am upto no good. */
 #include <iostream>
 #include <cstdio>
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
 #include <stdio.h>


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

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 ll MOD1 = 999983 , p1 = 971 , MOD2 = 999871 ,p2 = 1037 ;
 map<pair<ll,ll>,ll> m ;
 ll hash1[1002], hash2[1002] ;

 string s ;






 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    while (true){
        string str = "" ;
        getline(cin,str) ;
        if (str.size()==0){ break ; }
        memset(hash1,0,sizeof(hash1)) ;
        memset(hash2,0,sizeof(hash2)) ;
        string s ;
        for(int i = 0 ; i < str.size() ; i++){
            if (str[i]>='A' && str[i]<='Z') s += str[i] ;
        }
        int n = s.size();

        for(int len = 1 ; len <= n ; len++){
            m.clear() ;
            for(int i = 0 ; i < n ; i++){
                if (i+len-1 >= n){
                    m[mp(-1LL,-1LL)]++ ;
                    continue ;
                }

                hash1[i] = (hash1[i]*p1)%MOD1 + (ll)s[i+len-1] ;
                hash2[i] = (hash2[i]*p2)%MOD2 + (ll)s[i+len-1] ;
                m[mp(hash1[i],hash2[i])]++ ;
            }
            int ans = 0 ;
            for(auto it : m){
                if (it.xx != mp(-1LL,-1LL)){
                    ans = max((ll)ans,it.yy) ;
                }
            }
            if (ans == 0) {
                break ;
            }
            else if (ans > 1){
                cout << ans << el ;
            }

        }
        cout << el ;


    }




 }
