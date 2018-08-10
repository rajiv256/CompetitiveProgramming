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
  int n ; double s ; cin >> n >> s ;
  vector<pair<double,double> > left , right ; // pos, time
  double x , v , t ;
  forn(i,0,n){
    cin >> x >> v >> t ;
    if (t == 1) left.pb(mp(-x,x/v)) ;
    else right.pb(mp(x,1000000-x/v)) ;
  }
  sort(all(left)) ;
  sort(all(right)) ;

  double T6=1000000 ;
  double ret = 1000*T6  ;
  for(double i = 0 ; i <= T6 ; i++){
    double tl = i/s ; double tr = (T6-i)/s ;

    double mini1 = 10*T6  ;
    double mini2 = 10*T6  ;
    if (lower_bound(all(left),mp(-i,tl)) != left.end()){
      mini1 = tl ;
    }
    if (lower_bound(all(right),mp(i,tr)) != right.end()){
      mini2 = tr ;
    }
    mini1 = min(mini1,left[0].yy) ;
    mini2 = min(mini2,right[0].yy) ;
    ret = min(ret,max(mini1,mini2)) ;
  }
  printf("%.7f\n", ret);




}
