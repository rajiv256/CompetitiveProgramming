// #dynamic-programming
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


bool valid(string s){
  int x ; stringstream(s) >> x ;
  if ((x >= 1) && (x <=26)) return true ;
  return false ;
}
int main(){

  string s = "" ;
  while (true){
    getline(cin,s) ;
    if (s == "0") break ;

    int n = s.size() ;
    ll L[n+2][2] ; clr(L) ; 
    L[0][0] = 1 ;
    L[0][1] = 0 ;

    for(int i = 1 ; i < n ; i++){
      L[i][0] = L[i-1][0] + L[i-1][1] ;
      string ss = "" ;
      ss += s[i-1]; ss+=s[i] ;
      L[i][1] = 0 ;
      if (valid(ss)){
        L[i][1] = L[i-1][0] ;
      }
    }
    ll ans = L[n-1][0] + L[n-1][1] ;
    printf("%lld\n",ans);
  }

  return 0 ;
}
