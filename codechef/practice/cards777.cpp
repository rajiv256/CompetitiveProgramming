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
typedef vector<vector<int,int> > vvi ; 
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


int main(){
	int t ; cin >> t ; 
	while (t--){
		double res = 0.0 ; 
		int r , b , p ; 
		cin >> r >> b >> p ; 

		int tot = r+b ; 
		int rtr = p ; int rtb = r+b-p ; 
		int rcr = r ; int rcb = b ; 

		int np = 0 ; 
		while (np < tot){

			if (rcr < rcb){
				res += rcb/(rcb+rcr) ; 
				rtb-- ; rcb-- ; 
			}
			if (rcr > rcb){
				res += rcr/(rcb+rcr) ; 
				rtr-- ; rcr-- ; 
				rcr-- ; 
			}
			if (rcr == rcb){
				res += rcb/(rcb+rcr) ; 
				rtb-- ; rcb-- ; 
			}

			np++ ; 
		}
		printf("%.7f\n",res );

	}
}	