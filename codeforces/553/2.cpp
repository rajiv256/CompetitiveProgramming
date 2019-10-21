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
#define CASET  int t;cin>>t;while(t--)
#define forn(i,x,y) for(int i=x;i<y;i++)
#define maxn 100005
#define inf 10000000010
#define mod 1000000007
#define last_set_bit(x) log2((x)&(-x))
#define add(x,y) (x)=((x)+(y))%MOD
#define PI 3.141592653589793

typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

int main(){

	int n , m ; cin >> n >>m ; 
	int a[n][m] ; 
	forn(i,0,n){
		forn(j,0,m){
			cin >> a[i][j] ; 
		}
	}
	
	if (n == 1){
		forn(i,0,m){
			if (a[0][i] != 0){
				cout << "TAK" << el ; 
				cout << i+1 << el ; 
				return 0 ; 
			}
		}
		cout << "NIE" << el ; 
		return 0 ; 
	}
	if (m == 1){
		int xoxo = 0; 
		forn(i,0,n){
			xoxo ^= a[0][i] ; 
		}
		if (xoxo != 0){
			cout << "TAK" << el ; 
			forn(i,0,n){
				cout << 1 << sp ; 
			}
			cout << el ; 
			return 0 ; 
		}
		else{
			cout << "NIE" << el ; 
			return 0 ; 
		}
	}
	vector<int> nonuniqrows ; SI s ;
	for(int i = 0 ; i < n ; i++){
		s.clear() ; 
		forn(j,0,m){
			s.insert(a[i][j]) ; 
		}
		if(s.size() > 1){
			nonuniqrows.push_back(i) ; 
		}
	}
	if (nonuniqrows.size() == 0){
		int xoxo = 0 ; 
		forn(i,0,n){
			xoxo ^= a[i][0] ; 
		}
		if (xoxo != 0){
			cout << "TAK" << el ; 
			forn(i,0,n){
				cout << 1 << sp ; 
			}
			cout << el ; 
			return 0 ; 
		}
		else{
			cout << "NIE" << el ; 
			return 0 ; 
		}
		return 0 ;  
	}
	int xoxo = 0 ; 
	VI ans ; 
	for(int i = 0 ; i < n ; i++){
		if (i != nonuniqrows[0]){
			xoxo ^= a[i][0] ; 
			ans.pb(0) ; 
		}
		else{
			ans.pb(-1) ; 
		}
	}
	int rownum = nonuniqrows[0] ; 
	forn(i,0,m){
		if (xoxo != a[rownum][i]){
			ans[rownum] = i ; 
			break ; 
		}
	}
	cout << "TAK" << el ; 
	forn(i,0,ans.size()){
		cout << ans[i]+1 << sp ; 
	}
	return 0 ; 

}
































//}
