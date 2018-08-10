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


int main(){
	int n1, n2 , n3 ; cin >> n1 >> n2 >> n3 ; 
	int a1[n1] ; int a2[n2] ; int a3[n3] ; 
	forn(i,n1){
		cin >> a1[i] ; 
	}
	forn(i,n2){
		cin >> a2[i] ; 
	}
	forn(i,n3){
		cin >> a3[i] ; 
	}
	int aa1[n1] ; int aa2[n2] ; int aa3[n3] ; 
	forn(i,n1){
		aa1[i] = a1[n1-i-1] ; 
	}
	forn(i,n2){
		aa2[i] = a2[n2-i-1] ; 
	}
	forn(i,n3){
		aa3[i] = a3[n3-i-1] ; 
	}
	int c1[n1] ; int c2[n2] ; int c3[n3] ; 
	c1[0] = aa1[0] ; c2[0] = aa2[0] ; c3[0] = aa3[0] ; 
	for(int i = 1; i < n1 ; i++){
		c1[i] = c1[i-1]+aa1[i] ; 
	}
	for(int i = 1 ; i < n2 ; i++){
		c2[i] = c2[i-1]+aa2[i] ; 
	}
	for(int i = 1 ; i < n3 ; i++){
		c3[i] = c3[i-1]+aa3[i] ; 
	}

	int it2 = 0 ; int it3 = 0 ; 
	int ans = 0 ; 
	for(int i = 0 ; i < n1 ; i++){
		while ((c2[it2] < c1[i]) && (it2 <n2))
			it2++ ; 
		while ((c3[it3]<c1[i]) && (it3<n3))
			it3++ ; 
		if (c1[i]==c2[it2] && c1[i]==c3[it3]){
			ans = max(ans,c1[i]) ; 
		}

	}
	cout << ans << el ; 

	return 0 ;





}