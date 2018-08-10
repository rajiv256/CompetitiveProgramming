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

int main(){
	int n , h , k ; 
	cin >> n >> h >> k ; 
	ll a[n] ; 
	ll sum = 0 ; 
	forn(i,n){
		cin >> a[i] ; 
	}
	int st = 0 ; ll hd = 0 ; ll time = 0 ;  
	while (st < n){
		//cout << st << sp << hd << el; 
		while (st<n && hd<=h){
			hd += a[st] ; 
			st++ ; 
		}
		
		if (st>=n){
			if (hd <= h){
				time += hd/k + (int)(!(hd%k==0)) ; 
				cout << time << el ;
				return 0 ; 
			}
			else{
				st = n ; 
				hd -= a[n-1] ; 
			}
		}
		st-- ; 
		if (hd > h){
			hd -= a[st] ;  
		}
		ll z = 0 ;
		 
		ll x= a[st]-(h-hd) ;
		time += x/k ;
		hd -= (x/k)*k ; 
		if (x%k!=0){
			time += 1 ; 
			hd -= k ; 
		}
		hd = max(hd,z) ;		
	}
	cout << time << el ; 
	return 0 ; 
}















