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
    ll A , B , C ;
    CASET {
        cin >> A >> B >> C ;
        ll ca = abs(C-A) ;
        ll ab = abs(A-B) ;
        ll bc = abs(B-C) ;
        ll ans = 4*1e9 ;
        if (A <= B && B <= C){
            ll loc = 0 ;
            if (ca % 2 != 0){
                loc++ ;
                loc += abs(B-(A+1+C)/2) ;
                ans = min(ans,loc) ;
            }

            ll loc2 = 0 ;
            if (ca % 2 != 0){
                loc2++ ;
                loc2 += abs(B-(A-1+C)/2) ;
                ans = min(ans,loc2) ;
            }

            ll  loc3 = 0 ;
            if (ca % 2 == 0){
                loc3 = abs(B-(A+C)/2) ;
                ans = min(ans,loc3) ;
            }

        }
        if (C <= B && B <= A){
            ll loc = 0 ;
            if (ca % 2 != 0){
                 loc++ ;
                 loc += abs(B-(A+C-1)/2) ;
                 ans = min(ans,loc) ;
            }


            ll loc2 = 0 ;
            if (ca % 2 != 0){
                loc2++ ;
                loc2 += abs(B-(A+C+1)/2) ;ans = min(ans,loc2) ;
            }
            ll  loc3 = 0 ;
            if (ca % 2 == 0){
                loc3 = abs(B-(A+C)/2) ;ans = min(ans,loc3) ;
            }



        }
        if (A<=C && C<= B){
            ll loc = 0 ;
            if (ca % 2 != 0){
                loc++ ;
                loc += bc + (C-A-1)/2 ;
                ans = min(ans,loc) ;
            }

            ll loc2 = 0 ;
            if (ca % 2 != 0){
             loc2++ ;
             loc2 += abs(B-(A-1+C)/2) ;ans = min(ans,loc2) ;
            }
            ll  loc3 = 0 ;
            if (ca % 2 == 0){
                loc3 = abs(B-(A+C)/2) ;ans = min(ans,loc3) ;
            }


        }
        if (B <= C && C <= A){
            ll loc = 0 ;
            if (ca % 2 != 0){
                loc++ ;
                loc += abs(B-(A+C-1)/2) ;
                ans = min(ans,loc) ;
            }

            ll loc2 = 0 ;
            if (ca % 2 != 0){
                loc2++ ;
                loc2 += abs(B-(A+C+1)/2) ;ans = min(ans,loc2) ;
            }
            ll  loc3 = 0 ;
            if (ca % 2 == 0){
                loc3 = abs(B-(A+C)/2) ;ans = min(ans,loc3) ;
            }

        }
        if (B <= A && A <= C){
            ll loc = 0 ;
            if (ca % 2 != 0){
                loc++  ;
                loc += abs(B-(A-1+C)/2) ;
                ans = min(ans,loc) ;
            }

            ll loc2 = 0 ;
            if (ca % 2 != 0){
                loc2++ ;
                loc2 += abs(B-(A+1+C)/2) ;ans = min(ans,loc2) ;
            }
            ll  loc3 = 0 ;
            if (ca % 2 == 0){
                loc3 = abs(B-(A+C)/2) ;ans = min(ans,loc3) ;
            }

        }
        if (C <= A && A <= B){
            ll loc = 0 ;
            if (ca % 2 != 0){
                loc++ ;
                loc += abs(B-(A+1+C)/2) ;
                ans = min(ans,loc) ;

            }

            ll loc2 = 0 ;
            if (ca % 2 != 0){
                 loc2++ ;
                 loc2 += abs(B-(A-1+C)/2) ;ans = min(ans,loc2) ;
            }
            ll  loc3 = 0 ;
            if (ca % 2 == 0){
                loc3 = abs(B-(A+C)/2) ;ans = min(ans,loc3) ;
            }

        }

        cout << ans << el ;
    }
    return 0 ;
}
