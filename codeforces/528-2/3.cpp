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

VPII path(PII& p1, PII& p2){
  int x1 = p1.xx ; int y1 = p1.yy ; int x2 = p2.xx ; int y2 = p2.yy ;
  VPII v ;
  int x = x1 , y= y1 ;
  while (x != x2){
    v.pb(mp(x,y)) ;
    if (x > x2) x-- ;
    else x++ ;
  }
  v.pb(mp(x,y)) ;
  while (y != y2){
    v.pb(mp(x2,y)) ;
    if (y > y2) y-- ;
    else y++;
  }
  v.pb(mp(x2,y2)) ;
  return v ;
}
bool inside(PII& p, PII& p1, PII& p2){
  return (p.xx >= min(p1.xx, p2.xx) && p.xx <= max(p1.xx, p2.xx) && p.yy>=min(p1.yy, p2.yy) && p.yy<=max(p1.yy, p2.yy)) ;
}
PII get_nearest(PII& p, PII& p1, PII&  p2){
  PII ans = mp(p1.xx, p1.yy) ; int d = 1e9 ;
  for(int i = min(p1.xx, p2.xx) ; i <= max(p1.xx, p2.xx) ; i++){
    for(int j = min(p1.yy, p2.yy) ; j <= max(p1.yy, p2.yy) ; j++){
      int ldd = abs(p.xx-i) + abs(p.yy-j) ;
      if (ldd < d){
        d = ldd ;
        ans = mp(i,j) ;
      }
    }
  }
  return ans ;
}

int main(){
  int x, y ;
  VPII v ;
  for(int i = 0 ; i < 3 ; i++){
    cin >> x >> y ;
    v.pb(mp(x,y)) ;
  }
  int ans = 1e9+5 ;
  set<PII > s ;
  PII p1, p2 , p3 , p4;
  sort(all(v)) ;
  do {
    // cout << v[0].xx << sp << v[0].yy << sp << v[1].xx << sp << v[1].yy << sp << v[2].xx << sp << v[2].yy << el ;
    if (!inside(v[0], v[1], v[2])){

      PII np = get_nearest(v[0], v[1], v[2]) ;
      if (ans > abs(v[1].xx-v[2].xx) + abs(v[1].yy-v[2].yy) - 1 + abs(np.xx - v[0].xx) + abs(np.yy - v[0].yy) - 2){
        p1 = v[1] ; p2 = v[2] ; p3 = v[0] ; p4 = np ;
        ans = abs(v[1].xx-v[2].xx) + abs(v[1].yy-v[2].yy) - 1 + abs(np.xx - v[0].xx) + abs(np.yy - v[0].yy) - 2 ;
      }
    }
  }while (next_permutation(all(v))) ;
  // cout << p1.xx << sp << p1.yy << sp << p2.xx << sp << p2.yy << sp << p3.xx << sp << p3.yy << sp << p4.xx << sp << p4.yy << el ;
  VPII v1 = path(p1, p4) ;
  VPII v2 = path(p4, p2) ;
  VPII v3 = path(p4, p3) ;
  for(auto it : v1){
    s.insert(it) ;
  }
  for(auto it : v2){
    s.insert(it) ;
  }
  for(auto it : v3){
    s.insert(it) ;
  }
  cout  << s.size() << el ;
  for(auto it : s){
    cout << it.xx << sp << it.yy << el  ;
  }
  return 0 ;






}
