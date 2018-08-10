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
 int F[MAXN] ;
 void build_failure(string pat){
     F[0] = 0 ;
     F[1] = 0 ;
     for(int i = 2 ; i < pat.size() ; i++){
         int j = i-1 ;
         while (j > 0 ){
             if (pat[i-1] == pat[F[j]]){
                 F[i] = F[j]+1 ;
                 break ;
             }
             else{
                 j = F[j]-1 ;
             }
         }
         if (j == 0){
             F[i] = 0 ;
         }
     }
 }
 vector<int> matches ;
 void match(string str, string pat){
     int sp = 0 ; int pp = 0 ;
     while (sp < str.size()){

         if (str[sp] == pat[pp]){
             sp++ ; pp++ ;
             if (pat[pp]=='$'){
                 matches.pb(sp-pat.size()+1) ;
                 pp = F[pat.size()-1] ;
             }
             continue ;
         }
         else{
             while (pp > 0){
                 pp = F[pp] ;
                 if (pat[pp] == str[sp]){
                     sp++ ; pp++ ;
                     break ;
                 }
             }
         }
         if (pp == 0){
             sp++ ;
         }
     }
     return  ;
 }

PII check(VI& v1, VI& v2, int sz){
     sort(all(v1)) ;
     sort(all(v2)) ;
     for(auto it : v1){
         if (lower_bound(all(v2),it+sz) != v2.end()){
             return mp(it, *lower_bound(all(v2),it+sz)) ;
         }
     }
     return mp(-1,-1) ;
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n , m ,K ; cin >> n >> m >> K ;
    string s , t ;
    cin >> s >> t ;
    if (t.size() < K){
        matches.clear() ;
        memset(F,0,sizeof F) ;

        string pat = t + '$' ;
        build_failure(pat) ;
        match(s,pat) ;
        if (matches.size()>0){
            cout << "No" << el ;
            return 0 ;
        }
        else{
            cout << "Yes" << el  ;
            cout << matches[0]+1  << el  ;
            return 0 ;
        }
    }
    else{
        for(int k = 1 ; k <= K ; k++){


        string t1 = t.substr(0,k) ;
        string t2 = t.substr(k,t.size()) ;
        matches.clear() ;
        memset(F,0,sizeof F) ;
        string pat = t1 + '$' ;
        build_failure(pat) ;
        match(s,pat) ;
        VI v1 = matches ;
        matches.clear() ;
        memset(F,0,sizeof F) ;
        pat = t2 + '$' ;
        build_failure(pat) ;
        match(s,pat) ;
        VI v2 = matches ;

        // Write the intersect fn
        PII ans = check(v1,v2,t1.size()) ;

        if ( ans.xx != -1 && ans.xx < ans.yy){
            cout << "Yes" << el ;
            cout << ans.xx+1  << " " << ans.yy+1 << el ;
            return 0 ;
        }

        t1 = t.substr(0,t.size()-k) ;
        t2 = t.substr(t.size()-k,t.size()) ;
        matches.clear() ;
        memset(F,0,sizeof F) ;
        pat = t1 + '$' ;
        build_failure(pat) ;
        match(s,pat) ;
        v1 = matches ;
        matches.clear() ;
        memset(F,0,sizeof F) ;
        pat = t2 + '$' ;
        build_failure(pat) ;
        match(s,pat) ;
        v2 = matches ;
        ans = check(v1,v2, t1.size()) ;
        if (ans.xx != -1 && ans.xx < ans.yy){
            cout << "Yes" << el ;
            cout << ans.xx+1  << " " << ans.yy+1 << el ;
            return 0 ;
        }
        }
    }
    cout << "No" << el ;
    return 0 ;

 }
