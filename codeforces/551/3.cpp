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
	int n ; cin >> n ;

	string s; cin >> s; 
	if (s[0] == '?') s[0] = '(' ; 
	if (s[n-1] == '?') s[n-1] = ')' ;  
	
	if (s[0] != '(' || s[n-1] != ')' || n&1){
		cout << ":(" << el ; 
		return 0 ; 
	}
	int qs = 0 , ls = 0 , rs = 0 ; 
	for(int i = 0 ; i < n ; i++){
		switch(s[i]){
			case '(': ls++ ; break ; 
			case ')': rs++ ; break ; 
			default : qs++ ; break ; 
		}
	}
	if (abs(ls - rs) > qs){
		cout << ":(" << el ; 
		return 0 ; 
	}
	int lqs ; int rqs ; 
	if (ls == rs){
		lqs = qs/2 ; // we can see that in this case qs will be even. 
		rqs = qs/2 ; 
	}
	else if (ls > rs){
		rqs = ls-rs ; 
		lqs = (qs-rqs)/2 ; 
		rqs     += lqs ; 
	}
	else{
		lqs = rs-ls ; 
		rqs = (qs-lqs)/2; 
		lqs   += rqs ;  
	}
	int i = 0 ; 
	while (i < n && lqs > 0){
		if (s[i] == '?'){
			s[i] = '(' ; 
			lqs-- ; 
		}
		i++ ; 
	}
	i = 0 ; 
	while (i < n && rqs > 0){
		if (s[i] == '?'){
			s[i] = ')' ; 
			rqs-- ; 
		}
		i++ ; 
	}
	int left = 0 ; int right =0 ; 
	forn(i,0,n-1){
		if (s[i] == '(') left++ ; 
		else right++ ; 
		if (left == right){
			cout << ":(" << el ; 
			return 0 ;
		}
	}
	cout << s << el ; 
	return 0 ; 
}
































//}
