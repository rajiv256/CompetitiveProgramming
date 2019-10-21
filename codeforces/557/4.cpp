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

	int n , m ; cin >> n >> m ; 
	VVI adj(n, VI()) ; 
	int x , y;
	for(int i  = 0 ; i < m ; i++){
		cin >> x >> y ; x-- ; y-- ; 
		adj[x].pb(y) ; 
		adj[y].pb(x) ; 
	}
	for(int i = 0 ; i < n ; i++){
		sort(all(adj[i])) ; 
	}

	SI div ; 
	div.insert(1) ; 
	for(int i =  2; i <= sqrt(n) ; i++){
		if (n % i == 0){
			div.insert(i) ; div.insert(n/i) ; 
		}
	}
	VI divv = VI(all(div)) ; 

	for(auto it : divv){
		bool b = true ; 
		// cout << it << "------\n" ; 
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < adj[i].size() ; j++){
				int xx = (i +it)%n ; 
				int yy = (adj[i][j] + it)%n ; 
				//cout << xx << sp << yy << el ; 
				if (!binary_search(all(adj[xx]), yy)){
					b = false ; 
					break ; 
				}
			}
		}
		if (b){
			cout << "Yes" << el ; 
			return 0 ; 
		}
	}
	cout << "No" << el ; 
	return 0 ; 


}
































//}
