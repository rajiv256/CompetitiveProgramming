
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
  int k ; cin >> k ;
  string s ; cin >> s ;
  map<int,int> :: iterator it ;
  map<int,int> m ;
  forn(i,0,s.size()){
    m[s[i]-'0']++ ;
  }
  ll sum = 0 ;
  for(it = m.begin() ; it != m.end() ; it++){
    sum += (it->xx)*(it->yy) ;
  }
  int ans = 0 ;
  if (sum >= k){
    cout << ans << el ;
    return 0 ;
  }
  
  for(it = m.begin(); it != m.end() ; it++){
    int avail = it->yy ;
    int addable = 9-it->xx ;
    if (avail*addable < k-sum){
      sum += avail*addable ;
      ans += avail ;
    }
    else{
      ans += (k-sum)/addable ;
      if ((k-sum)%addable !=0) ans++ ;
      break ;
    }


  }
  cout << ans << el ;
  return 0 ;



}
