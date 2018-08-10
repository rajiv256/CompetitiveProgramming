#include <bits/stdc++.h>

using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100003
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()


typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define YES "YES\n"
#define NO "NO\n"


int main(){
  ll n , q , c; cin >> n >> q >> c ;
  vector<pair<ll,ll> > allstars ;
  vector<ll> bri ; ll x, y , si ;
  ll cnt[c+1][102][102] ;
  clr(cnt) ; 
  forn(i,0,n){
      cin >> x >> y >> si ;
      allstars.pb(mp(x,y)) ;
      bri.pb(si) ;
      cnt[si][x][y] += 1 ;
  }
  for(int i = 0 ; i <= c ; i++){
    cnt[i][0][0] = 0 ;
    for(int j  = 1 ; j <= 101 ; j++){
      for(int k = 1 ; k <= 101; k++){
        cnt[i][j][0] = 0 ;
        cnt[i][0][k] = 0 ;
        cnt[i][j][k] = cnt[i][j][k-1] + cnt[i][j-1][k] - cnt[i][j-1][k-1] + cnt[i][j][k] ;
      }
    }
  }

  ll mod = c+1 ;
  while (q--){
    ll ans = 0 ;
    ll ti , x1 ,y1 , x2 , y2  ; cin >> ti >> x1 >> y1 >> x2 >> y2 ;
    for(int i = 0 ; i <= c ; i++){
      ll add = cnt[i][x2][y2] ;

      ll rem = cnt[i][x1-1][y2] + cnt[i][x2][y1-1] -  cnt[i][x1-1][y1-1] ;
      ll each = (i+ti+mod)%mod ;
      ans += (add-rem)*each ;
    }
    cout << ans << el ;
  }
  return 0 ;
}
