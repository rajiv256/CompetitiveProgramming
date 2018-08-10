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

int b[1002][1002] ;
int a[1002] ;

void printarr(int x[], int n){
  forn(i,0,n){
    printf("%d ",x[i]);
  }
  printf("\n");
}

int getval(int idx , int n){
  vi poss ;
  poss.pb(-b[idx][0]) ;poss.pb(b[idx][0]) ;

  for(int i = 1 ; (i < idx) ; i++){
    vi v ;
    for(int j = 0 ; j < 2 ; j++){
      if (abs(a[i]-poss[j]) == b[idx][i]){
          v.pb(poss[j]) ;
      }
    }
    poss.clear() ;
    poss = v;
  }
  return poss[0] ;
}


int main(){
  int n , q ; sci(n) ; sci(q) ;

  forn(i,0,n){
    forn(j,0,n){
      sci(b[i][j]) ;
    }
  }
  a[0] = 0 ;
  forn(i,1,n){
    a[i] = getval(i,n) ;
  }
  printarr(a,n) ; int r ;
  while (q--){
    sci(r) ; r-- ;
    forn(i,0,n){
      sci(b[r][i]) ;
      b[i][r] = b[r][i] ;
    }
    int nz = 1 ;
    while (b[nz][0]==0) nz++ ;

    a[nz] = -b[nz][0] ;

    for(int i = nz+1; i < n ; i++){
      vi v1 ; v1.pb(-b[i][0]) ; v1.pb(b[i][0]) ;
      vi v2 ; v2.pb(a[nz]-b[i][nz]) ; v2.pb(a[nz]+b[i][nz]) ;
      sort(all(v1)) ;
      sort(all(v2)) ;
      forn(j,0,v1.size()){
        if (binary_search(all(v2),v1[j])){
          a[i] = *lower_bound(all(v2),v1[j]) ;
        }
      }
    }
    printarr(a,n) ;
  }
  return 0 ;
}
