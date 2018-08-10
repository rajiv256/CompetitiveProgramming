
#include <bits/stdc++.h>

using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100003
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define YES "YES\n"
#define NO "NO\n"

int gcd(int a, int b){
	if (a < b) 
		return gcd(b,a) ; 
	if (b == 0)
		return a ; 
	return gcd(b,a%b);  
}

int main(){
	double ans = 0.0 ; 
	int  n ; sci(n) ; 
	int xx =0 ; int yy = n ; 
	
	for(double a = 0.0 ; a < n ; a++){
		double b = n - a ; 
		if ((b > a) && (gcd(b,a)==1)){
			if (ans < a/b){
				ans = a/b;
				xx = a ; yy = b ; 
			}
			
		}
	}
	printf("%d %d\n",xx,yy ); 
}