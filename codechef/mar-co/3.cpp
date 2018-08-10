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

 ll a[MAXN] ;
 ll L , R , N , K , M ;
 ll A[MAXN] ;

 bool cmp1(const pair<ll,ll>& p1, const pair<ll,ll>& p2){
     return (p1.yy < p2.yy)?true:(p1.yy == p2.yy)?(p1.xx < p2.xx):false  ;
 }
 bool cmp2(const pair<pair<ll,ll>,ll>& p1, const pair<pair<ll,ll>,ll>& p2){
     return cmp1(p1.xx, p2.xx) ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    CASET {
        cin >> N >> M >> K ;
        VI present ;
        bool marked[N] ;
        memset(A,-1,sizeof A) ;
        memset(marked,false, sizeof marked) ;
        for(int i = 0 ; i < N ; i++){
            cin >> a[i] ;
            if (a[i] != -1){
                A[i] = a[i] ;
                present.pb(i) ;
                marked[i] = true ;
            }
        }
        vector<pair<ll,ll> > I, D ;
        char c ;
        for(int i = 0 ; i < M ; i++){
            cin >> c ;
            cin >> L >> R ; L-- ; R-- ;
            if (c == 'I'){
                I.pb(mp(L,R)) ;
            }
            else{
                D.pb(mp(L,R)) ;
            }
        }
        sort(all(I),cmp1) ;
        sort(all(D),cmp1) ;
        vector<pair<ll,ll> > Inew, Dnew ;
        if (I.size()>0) Inew.pb(I[0]) ;
        if (D.size()>0) Dnew.pb(D[0]) ;
        for(int i = 1 ; i < I.size() ; i++){
            if (Inew[Inew.size()-1].yy >= I[i].xx){
                Inew[Inew.size()-1].yy = I[i].yy ;
                Inew[Inew.size()-1].xx = min(Inew[Inew.size()-1].xx,I[i].xx) ;
            }
            else{
                Inew.pb(I[i]) ;
            }
        }
        for(int i = 1 ; i < D.size() ; i++){
            if (Dnew[Dnew.size()-1].yy >= D[i].xx){
                Dnew[Dnew.size()-1].yy = D[i].yy ;
                Dnew[Dnew.size()-1].xx = min(Dnew[Dnew.size()-1].xx,D[i].xx) ;
            }
            else{
                Dnew.pb(D[i]) ;
            }
        }
        I = Inew ;
        D = Dnew ;
        // cout << I[0].xx << sp << I[0].yy << el ;
        bool valid = true ;
        vector<pair<pair<ll,ll>,ll> > v ;
        for(auto it : I) v.pb(mp(it,1)) ;
        for(auto it : D) v.pb(mp(it,-1)) ;
        sort(all(v),cmp2) ;
        // Ensure no overlap between the positive segment and negative segment
        for(int i = 0 ; i < v.size()-1 ; i++){
            if (v[i].yy != v[i+1].yy && v[i].xx.yy > v[i+1].xx.xx){
                valid = false ;
                break ;
            }
        }
        ll ans = 1 ;
        bool nonEmptyOccured = false ;
        bool chainAlive = false ;
        ll loc = 1 ;
        for(int i = 0 ; i < v.size() ; i++ ){
            ll l = v[i].xx.xx ; ll r = v[i].xx.yy ; ll fl = v[i].yy ;
            if (i != 0 && v[i-1].xx.yy == v[i].xx.xx){
                chainAlive = true ;

            }
            else{
                chainAlive = false ;
                nonEmptyOccured = false ;
                ans = ans*loc % MOD ;
                loc = 1 ;
            }
            for(int j = l ; j <= r ; j++) marked[j] = true ;
            ll lb = lower_bound(all(present),l)-present.begin() ;
            ll rb = upper_bound(all(present),r)-present.begin() ; rb-- ;

            if (lb > rb){  // all the elements are free.
                if(!nonEmptyOccured && )
                    loc = loc*(max(0LL,K-(r-l))) % MOD ;
                else{
                    loc = 1 ;
                }
            }
            else {
                nonEmptyOccured = true ;
                for(int j = present[lb]-1 ; j >= l ; j--){
                    if (A[j] != -1 && A[j] != A[j+1]-fl){
                        valid = false ;
                        break ;
                    }
                    if (A[j]==-1){
                        A[j] = A[j+1]-fl ;
                    }
                }
                for(int j = present[lb]+1 ; j <= r ; j++){
                    if (A[j] != -1 && A[j] != A[j-1]+fl){
                        valid = false ;
                        break ;
                    }
                    if (A[j] == -1){
                        A[j] = A[j-1] + fl ;
                    }
                }
            }
            for(int j = 0 ; j < N ; j++){
                if (A[j]!=-1 && (A[j] < 1 || A[j] > K)){
                    valid = false ;
                    break ;
                }
            }
            if (!valid) break ;
        }
        ans = ans*loc % MOD ;
        if (!valid){
            cout << "0" << el ;
            continue ;
        }
        for(int j = 0 ; j < N ; j++){
            if (!marked[j]){
                ans = ans*K %MOD ;
            }
        }
        cout << ans << el ;

    }
    return 0 ;
 }
