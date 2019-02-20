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

bool prime[10*MAXN] ;
void sieve(){
  memset(prime, true, sizeof prime) ;
  for(int i = 2 ; i < 10*MAXN ; i++){
    if (prime[i] == false) continue ;
    for(int j = 2 ; i*j < 10*MAXN ; j++){
      prime[i*j] = false ;
    }
  }
}


int main(){
  int n , k ; cin >> n >> k ;
  int x = 1e9 ; int a , b ;
  for(int i = 1 ; i <= sqrt(n) ; i++){
    if (n % i == 0){
      a = i ; b = n/i ;
      if (a < k && b < k){
        x = min(x, min(k*b + a, k*a + b)) ;
      }
      else if (a < k){
        x = min(x, k*b + a) ;
      }
      else if (b < k){
        x = min(x, k*a + b)  ;
      }
    }
  }
  cout << x << el ;
}
