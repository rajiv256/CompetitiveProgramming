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
 #define SZ(C) sizeof(C)/sizeof(C.at(0))
 #define all(x) (x).begin(),(x).end()
 #define clr(x) memset((x),0,sizeof(x))
 #define abs(x) ((x<=0)?(-x):(x))
 #define MAXN 1000005
 #define INF (int)1E10+1
 #define MOD (int)1E9+7
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define forn(i,x,y) for(int i=(x); i<(y) ;i++)
 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;


 struct tup {
     int first, second, index  ;
 }L[3*MAXN],Ls[3*MAXN] ;

int P[17][3*MAXN] ;

int S[3*MAXN] ;
char A[3*MAXN] ;
int step = 0 ;
string sa , sb ;
int counts[3*MAXN] ;
int N ;

vector<pair<int,int> > res ;
vector<pair<int,int> >v ;

void counting_sort(int idx){
    memset(counts,0,sizeof(counts)) ;
    res.clear();

    for(int i = 0 ; i < N ; i++){
        int p = (idx==1)?Ls[i].second:Ls[i].first ;
        counts[p]++ ;
    }
    for(int i = 1 ; i < 3*MAXN ; i++){
        counts[i] += counts[i-1] ;
    }
    for(int i = 0 ; i < N ; i++){
        res.pb(mp(0,0)) ;
    }
    for(int i = N-1 ; i>=0 ; i--){
        int p = (idx==1)?Ls[i].second:Ls[i].first ;
        res[counts[p]-1].yy = Ls[i].index ;
        counts[p]-- ;
    }
}

void radix_sort(){

    for(int i = 0 ; i < N ; i++){
        Ls[i].first = L[i].first+3 ;
        Ls[i].second = L[i].second+3 ;
        Ls[i].index = L[i].index ;

    }
    counting_sort(1) ;
    for(int i = 0 ; i < N ; i++){
        int idx = res[i].yy ;
        Ls[i].first = L[idx].first+3 ;
        Ls[i].second = L[idx].second+3 ;
        Ls[i].index = L[idx].index ;
    }
    counting_sort(0) ;
    for(int i = 0 ; i < N ; i++){
        int idx = res[i].yy ;
        Ls[i].first = L[idx].first ;
        Ls[i].second = L[idx].second ;
        Ls[i].index = L[idx].index ;
    }

    std::copy(Ls,Ls+N,L) ;
}


bool vcmp(const string& s1, const string& s2){
    return (s1[0]<=s2[0]) ;
}
bool tcmp(const tup& t1, const tup& t2){
    return (t1.first < t2.first)?true:(t1.first>t2.first)?false:(t1.second<t2.second)?true:(t1.second>t2.second)?false:(t1.index<t2.index)?true:false ;
}

void build_suffixarray(string s){
    N = s.size() ;

    for(int i = 0 ; i < N ; i++){
        P[0][i] = s[i]-'a' ;
    }
    step = 1 ;
    for(int cnt=1 ; cnt < N ; cnt*=2){
        for(int i = 0 ; i < N ; i++){
            L[i].index = i ;
            L[i].first = P[step-1][i] ;
            L[i].second = (i+cnt < N)?P[step-1][i+cnt]:-1 ;
        }

        radix_sort() ;

        for(int i = 0 ; i < N ; i++){
            P[step][L[i].index] = (i>0 && L[i].first==L[i-1].first && L[i].second==L[i-1].second)?P[step][L[i-1].index]:i ;
        }
        step++ ;
    }

    forn(i,0,N){
        S[P[step-1][i]] = i ;
    }
}
// belong to different strings
bool different(int i , int j , int sz1){
    if (i>=0 && j >=0 && ((i < sz1 && j > sz1) || (i>sz1 && j<sz1))){
        return true ;
    }
    return false ;
}

int LCP(int suff1 , int suff2, int N){
    int ret = 0 ;

    for(int k = step-1 ; k >= 0 ; k--){

        if (different(suff1,suff2,sa.size())&& suff1 < N && suff2 <N && P[k][suff1] == P[k][suff2] && P[k][suff1]!=-1){

            if (different(suff1+(1<<k)-1,suff2+(1<<k)-1,sa.size())){
                ret   += (1<<k) ;
                suff1 += (1<<k) ;
                suff2 += (1<<k) ;
            }
        }
    }
    return ret ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;

    cin >> sa >> sb ;
    string s = sa+ (char)96 + sb ;

    memset(L,0,sizeof(L)) ;    // Check
    memset(P,-1,sizeof(P)) ;    // Check

    forn(i,0,N){
        v.pb(mp(0,0)) ;
        res.pb(mp(0,0)) ;
    }
    build_suffixarray(s) ;

    int N = s.size() ;

    int ans = 0 ;
    for(int i = 0 ; i < N-1 ; i++){

        if (different(L[i].index,L[i+1].index,sa.size())){
            int lcp = LCP(L[i].index,L[i+1].index,N);
            ans = max(ans,lcp) ;
        }
    }
    cout << ans << el ;


}
