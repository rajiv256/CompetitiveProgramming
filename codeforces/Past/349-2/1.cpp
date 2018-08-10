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
#define PI 3.141592653589793
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
	double d , h , v ,e ; 
	cin >> d >> h >> v >> e ; 
	if (e*(PI*d*d)/4 > v){
		cout << "NO" << el ; 
		return 0 ; 
	}
	else{
		double t = h/(((4*v)/(PI*d*d))-e) ; 
		if (t <= 10000){
			cout << "YES\n" ; 
			printf("%.12f\n",t) ;
			return 0 ; 
		}
		else{
			cout << "NO" << el ; 
		}
	}
	return 0 ; 
	
	
	
}






















