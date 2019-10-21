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
#define inf 1E9+10 
#define mod 1000000007
#define last_set_bit(x) log2((x)&(-x))
#define add(x,y) (x)=((x)+(y))%MOD
#define PI 3.141592653589793

typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
typedef map<int,int> MII ; typedef map<int,VI > MIV; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

int S[100005][26] ; 
int N[252][252][252] ; 


int recompute(int x, int y, int z, char c, int n){
	int t = n ; 
	if (x) { t = min(t, S[N[x-1][y][z]+1][c-'a']) ; }
	if (y) { t = min(t, S[N[x][y-1][z]+1][c-'a']) ; }
	if (z) { t = min(t, S[N[x][y][z-1]+1][c-'a']) ; }
	return t ; 
	
}

int main(){
	int n , q ; cin >> n >> q ; 
	string s , a, b , c ; 
	cin >> s ; a = "" ; b = "" ; c = "" ; 
    
	VVI idx(26, VI()) ; 
	for(int i = 0 ; i < s.size() ; i++){
		idx[s[i]-'a'].pb(i) ; 
	}
	for(int i = 0 ; i < 100005 ; i++){
		for(int j = 0 ; j < 26 ; j++){
			auto it = lower_bound(all(idx[j]), i)  ; 
			if (it == idx[j].end()){
				S[i][j] = n ; 
			}
			else{
				S[i][j] = *it ; 
			}
		}
	}
 	forn(i,0,252) forn(j,0,252) forn(k,0,252) N[i][j][k] = inf ; 

	N[0][0][0] = -1 ; 
	int asz = 0 ; int bsz = 0 ; int csz = 0 ; char sym, alph ; int x ;
	while (q--){
		 
		char sym, alph ; int x ; 
		cin >> sym >>  x ; 
		if (sym == '+'){
			cin >> alph ; 
			if (x == 1){
				++asz ; 
				a += alph ; 
				for(int i = 0 ; i <= bsz ; i++){
					for(int j = 0 ; j <= csz ; j++){
						N[asz][i][j] = recompute(asz, i, j, alph, n) ; 
					}
				}
			}
			if (x == 2){
				++bsz ; 
				b += alph ; 
				for(int i = 0 ; i <= asz ; i++){
					for(int j = 0 ; j <= csz ; j++){
						N[i][bsz][j] = recompute(i, bsz, j, alph, n) ; 
					}
				}
			}
			if (x == 3){
				++csz ; 
				c += alph ; 
				for(int i = 0 ; i <= asz ; i++){
					for(int j = 0 ; j <= bsz ; j++){
						N[i][j][csz] = recompute(i, j, csz, alph, n) ;
						  
					}
				}
				forn(i,0,asz+1){
					forn(j,0,bsz+1){
						cout << N[i][j][csz] << sp ; 
					}
					cout << el ;
				}
				cout << el ; 
			}
		}
		if (sym == '-'){
			if (x == 1){
				--asz; 
				a.pop_back() ; 
			}
			if (x == 2){
				--bsz ; 
				b.pop_back() ; 
			}
			if (x == 3){
				--csz ; 
				c.pop_back() ; 
			}
		}
		cout << asz << sp << bsz << sp << csz << sp << N[asz][bsz][csz] << el ; 
		bool ans = (N[asz][bsz][csz] < n) ; 
		cout << ((ans)?"YES":"NO")  << el ; 
	}
}
































//}
