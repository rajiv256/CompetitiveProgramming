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

 int diff(char a , char b){
     if (a > b) return diff(b,a) ;
     return min(b-a,a+26-b) ;
 }
 int change(string s , int p , int st , int en){
    int sz = s.size() ;
    while (s[st] == s[sz-st-1]) st++ ;
    while (s[en] == s[sz-en-1]) en-- ;
    int ret = 0 ;
    if (st <= en)
        ret += min(abs(p-st),abs(en-p)) ;
    for(int i = st ; i <= en ; i++){
        ret += diff(s[i],s[sz-i-1]) ;
    }
    ret += max(0,en-st) ; 

    return ret ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n , p ;  cin >> n >> p ; p-- ;
    string s ; cin >> s ;
    int st1 = 0 ; int en1 = n/2-1 ;
    int st2 = n/2+(n%2) ; int en2 = n-1 ;
    int a1 = 0 , a2 = 0 , a3 = 0 , a4 = 0 ;

    a1 += change(s,p,st1,en1) ;
    a2 += change(s,p,st1,en1) ;
    a3 += change(s,p,st2,en2) ;
    a4 += change(s,p,st2,en2) ;
    int ans = min(a1,min(a2,min(a3,a4))) ;
    cout << ans << el ;
 }
