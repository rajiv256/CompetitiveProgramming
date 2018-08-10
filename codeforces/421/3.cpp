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
    int a , b ; int l , r ;
    cin >> a >> b >> l >> r ;
    string sa = "" ;
    for(int i = 0 ; i < a ; i++){
        sa += 'a'+i ;
    }
    string pre = "" ;
    pre += sa ;
    for(int i = 0 ; i < b ; i++){
        pre += 'a' ;
    }
    if (b >= a){
        for(int i = 1 ; i < a ; i++){
            pre += sa[i] ;
        }
        pre += 'a'+a ;
    }
    else{
        for(int i = 1 ; i < b ; i++){
            pre += sa[i] ;
        }
        char last = sa[sa.size()-1]+1 ;
        for(int i = 0 ; i <= a-b ; i++){
            pre += last ; last++ ;
        }
    }
    string rep = "" ;
    for(int i = 0 ; i < b ; i++){
        rep += 'a' ;
    }
    rep += sa.substr(1,a) ;
    rep += sa[sa.size()-1]+1 ;
    char c = rep[rep.size()-1]+1 ;
    for(int i = 0 ; i < b ; i++){
        rep += 'a' ;
    }
    string x = sa.substr(1,min(a,b)) ;

    if (b >= a){
        rep += sa.substr(1,a) ;
        rep += sa[sa.size()-1]+1 ;
    }
    else{
        while (x.size()!=a){
            x += c ; c++ ;
        }
        rep += x;
    }
    //cout << pre << sp << rep << el ;
    set<char> se ;
    l-- ; r-- ;
    if (l < a && r < a+b){
        string tmp = sa ;
        for(int i = 0 ; i < 26 ; i++){
            tmp += 'a'+(l+i)%26 ;
        }
        for(int i = l ; i <= r ; i++){
            se.insert(tmp[i]) ;
        }
        cout << se.size() << el ;
        return 0 ;
    }
    for(int i = l ; i < 2*a+b ; i++){
        se.insert(pre[i]) ;
        if (i == r){
            cout << se.size() << el ;
            return 0 ;
        }
    }
    l = max(2*a+b,l) ;
    if (l > r){
        cout << se.size() << el ;
        return 0 ;
    }
    if (r-l+1 > rep.size()){
        for(auto it : rep){
            se.insert(it) ;
        }
        cout << se.size() << el ;
        return 0 ;
    }
    else{
        l -= 2*a+b ; r -= 2*a+b ;
        ll x = l%rep.size() ;
        int nocc = 0 ;
        while (l <= r){
            se.insert(rep[x%rep.size()]) ;
            if (rep[x%rep.size()]=='a') nocc++ ;
            x++ ; l++ ;
        }
        cout << max((int)se.size()-(nocc>0),1) << el  ;
        return 0 ;
    }


 }
