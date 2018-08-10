#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define pii pair<int,int>
#define INF 1000000000
#define sp " "
#define el "\n"
#define lld long long int
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define sci(x) scanf("%d",&x)
#define mp make_pair
#define ll long long


int abs(int a){
	if (a < 0){
		return -a ; 
	}
	return a ; 
}

int main(){
	int n ; sci(n) ; 
	pair<int,int> p[1003] ; 
	forn(i,n){
		int x ; cin >> x ; 
		p[i] = mp(x,i) ; 
	}
	sort(p,p+n) ; 
	int ans = INT_MAX ; 
	for(int i = 0 ; i < n-1 ; i++){
		if (p[i].xx==p[i+1].xx){
			ans = min(ans,abs(p[i+1].yy-p[i].yy)) ; 
		}
	}
	if (ans == INT_MAX){
		printf("-1\n") ; 
		return 0 ; 
	}
	cout << ans << el ; 


}