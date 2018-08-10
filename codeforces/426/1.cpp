/* 
        Code written by rajiv.
        God speed!
*/
#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define sclf(x) scanf("%lf",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100005
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ;

int geti(char c , int a[]){
  for(int i = 0 ; i < 4 ; i++){
    if ((int)c == a[i]){
      return i ;
    }
  }
  return 0 ;
}



int main(){
  char st , en ; cin >> st >> en ;
  int a[4]= {118,60,94,62} ;
  string ans = "undefined" ;
  int n ; cin >> n ;

  int sti = geti(st,a) ; int eni = geti(en,a) ;

  int actencw = (sti + n%4 + 4)%4 ;
  int actenccw = (sti - n%4+4)%4 ;

  if (actencw == eni  && actenccw == eni){
    ans = "undefined" ;
  }
  else if (actenccw == eni){
    ans = "ccw" ;
  }
  else if (actencw == eni){
    ans = "cw" ;
  }
  cout << ans << el ;
  return 0 ;


}
