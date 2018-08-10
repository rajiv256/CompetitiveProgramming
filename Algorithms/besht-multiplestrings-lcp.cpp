/* I solemny swear that I am upto no good. */
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
 #define MAXN 130005
 #define INF (int)1E10+1
 #define MOD (int)1E9+7
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 struct tup {
     int si ;
     int nsi ;
     int idx ;
     tup(){

     }

 };
 tup L[5*MAXN] ;
 int S[35][5*MAXN] ;
 int P[5*MAXN] ;
 int LCP[5*MAXN] ;
 int N ;
 string megas ;
 vector<int> v ;
 vector<string> strs  ;

 bool cmp(const tup& t1, const tup& t2){
     return (t1.si==t2.si)?(t1.nsi<t2.nsi):(t1.si<t2.si)  ;
 }
 bool compare(const tup &a , const tup &b) {
    return a.si == b.si ?a.nsi < b.nsi :a.si < b.si;
}

 void build_suffixarray(string s){
     for(int i=0; i<N; i++)
         S[0][i] = s[i] - 'a';


    for(int cnt = 1, step = 1; (cnt>>1) < N ; cnt<<=1) {
        for(int i = 0; i<N ; i++) {
            //cout << S[step-1][i] << el ;
            L[i].si = S[step-1][i];
            L[i].nsi = (i+cnt < N) ? S[step-1][i+cnt] : -1;
            L[i].idx = i;
        }

        sort(L,L+N,compare);

        int rnk = 0;
        S[step][L[0].idx] = 0;
        for(int i = 1 ; i<N ; i++) {
            if(L[i-1].si == L[i].si && L[i].nsi == L[i-1].nsi)
                rnk = S[step][L[i-1].idx]; //same as the last one
            else
                rnk = i;
            S[step][L[i].idx] = rnk;
        }
        step++ ;
    }

    return ;
 }

 int section(int i){
     int ret = upper_bound(all(v),i)-v.begin()-1 ;
     return ret ;
 }
 int lcp(int i1, int i2, int N){
     int ret = 0 ;
     int sec1 = section(i1) ;
     int sec2 = section(i2) ;
     for(int i = ceil(log2(N)) ; i >= 0 ; i--){

          if (i1 < N && i2 < N && S[i][i1]==S[i][i2] && megas[i1]!=(char)96 && S[i][i1]!=-1){
             int k = pow(2,i) ;
             if (section(i1+k-1)!=sec1 || section(i2+k-1)!=sec2) continue ;
             ret += k ;
             i1 += k ;
             i2 += k ;
         }
     }
     return ret ;

 }

map<int,int> start ;
map<int,int> findinL ;
int x, y ;
int bsearch1(int lo, int hi, int compwith, int actual){
    int iter = 0 ;
    while (lo < hi && iter<=25 ){
        int mid = (lo+hi)/2 ;
        int val = lcp(L[mid].idx, L[compwith].idx,N) ;

        if (val < actual){
            lo = mid+1 ;
        }
        if (val >= actual){
            hi = mid ;
        }
        iter++ ;
    }
    return lo ;
}
int bsearch2(int lo, int hi, int compwith, int actual){
    int iter = 0 ;
    while (lo < hi && iter<=25){
        int mid = (lo+hi+1)/2 ;
        int val = lcp(L[mid].idx,L[compwith].idx,N) ;
        if (val >= actual){
            lo = mid ;
        }
        else{
            hi = mid-1 ;
        }
        iter++ ;
    }

    return lo ;

}
int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n , q ; string s ; char pad = (char)96 ;

    clock_t BEGIN = clock() ;
    cin >> n ; megas = "" ;
    for(int i = 1 ; i <= n ; i++){
        cin >> s ;
        start[i] = megas.size() ;
        v.pb(max(0,start[i]-1));
        megas += s+pad ;
    }

    megas = megas.substr(0,megas.size()-1) ;
    N = megas.size() ; string mm = megas ;
    build_suffixarray(mm) ;

    for(int i = 0 ; i < N ; i++){
        findinL[L[i].idx] = i ;
    }
    start[n+1] = megas.size() ;

    cin >> q ;
    while (q--){
        cin >> x >> y ;
        //cout << megas << el ;
        int actual = lcp(start[x],start[y],N) ;
        int fst = findinL[start[x]] ;
        int snd = findinL[start[y]] ;
        //for(int i = 0 ; i < N ; i++){
            //cout << L[i].idx << sp ;
        //}
        //cout << el ;

        if (actual==0){
            cout << "0" << el ;
            continue ;
        }
        if (fst > snd) swap(fst,snd) ;

        int leftmost = bsearch1(0,fst,snd,actual) ;
        int rightmost = bsearch2(snd,N-1,fst,actual) ;
        cout << rightmost-leftmost+1 << el ;
    }

 }
