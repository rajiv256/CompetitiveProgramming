#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,char> > vp ;
typedef vector<vector<pair<int,char> > > vvp  ;

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
	int n , d ; sci(n); sci(d) ; 

	
	string s ; int ans = 0 ; int x = 0 ; 
	forn(i,d){
		cin >> s ; 
		int fin = s.find('0') ; 
		if (fin == string::npos){
			 ans = max(ans,x) ; 
			 x = 0 ; 
			 continue ; 
		}

		x += 1 ; 
		if (i==d-1){
			ans = max(ans,x) ; 
		}
	}
	ans = max(ans,x) ; 
	cout << ans << el ; 


}