#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mi ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pi pair<int,int>
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el "\n"
#define ll long long
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x)
#define MXN 1000003
#define gc getchar_unlocked

int parent(int p){
	
}


int main(){
	
	int n , t ; cin >> n >> t ; 
	int l = 0 ; 
	int ng = (n*(n+1))/2 ; 
	double a[111] ; 
	memset(a,0,sizeof(a)) ; 
	a[0] = t ; 
	int ans = 0 ; int st = 0 ; 
	while (l < n){
		//cout << st << el ;
		for(int i = st ; i <= st+l ; i++){
			if (a[i] <= 1){
				continue ; 
			}
			double rem = a[i]-1 ; 
			a[i] = 1 ; 
			a[i+l+1] += rem/2 ; 
			a[i+l+2] += rem/2 ; 
		}
		st = st+l+1 ;
		l++ ; 
		 
	}
	
	
	forn(i,ng){
		if (a[i] == 1){
			ans += 1 ; 
		}
	}
	
	cout << ans << el ; 
	return 0 ; 
	
}






















