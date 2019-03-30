/*
        Code written by rajiv.
        God speed!
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

#define ll long long
#define el "\n"
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define sclf(x) scanf("%lf",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MAXN 100005
#define INF 0x3f3f3f3f
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define set_bits(x) __builtin_popcount(x)
#define lsb(x) __builtin__ffs(x)-1
#define printV(container) copy(container.begin(), container.end(), ostream_iterator<vector<int> >(cout, ' '));
#define printS(container) copy(container.begin(), container.end(), ostream_iterator<set<int> >(cout, ' '));
#define gcd(a,b) __gcd(a,b)


typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ;
typedef pair<int,int> pii ;

int NMAX = 2*MAXN ;




int main(){
	cin.tie(0) ;
	ios_base::sync_with_stdio(false)  ;
	ll n , m , k ; cin >> n >> m >> k ;
	ll a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	// cout << "here" << el ;
	vector<pair<ll,ll> > v ;
	for(ll i = 0 ; i < n ; i++){
		v.pb(mp(a[i],i)) ;
	}
	sort(all(v), greater<pair<ll,ll> >()) ;
	vector<ll> km ;
	for(int i = 0 ; i < k*m ; i++){
		km.pb(v[i].yy+1) ;
	}
	sort(all(km));
	ll sum = 0 ;
	for(ll i = 0 ; i < k*m ; i++){
		sum += v[i].xx ;
	}
	cout << sum << el ;
	for(ll i = 1 ; i <= k-1 ; i++){
		cout << km[m*i - 1] << sp ;
	}
	cout << el ; 
	return 0 ;

}
