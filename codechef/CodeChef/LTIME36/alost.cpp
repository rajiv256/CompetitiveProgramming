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
	int t ; sci(t) ; 
	while (t--){
		ll n , e ,  o ; 
		scanf("%lld%lld%lld",&n,&e,&o) ;
		int ret = 0 ; 
		for(int i = 1 ; i<=n ; i++){
			ll e1 = (i-1)*(n-i+1)+n-i+1 ; 
			if (e1==o){
				for(int j = 1 ; j <= n ; j++){
					if (j==i){
						printf("1") ; 
					}
					else{
						printf("2") ; 
					}
					printf(" ") ; 
				}
				ret = 1; 
				break ; 
			}
		}
		if (ret ==0){
			printf("-1") ; 	
		}
		printf("\n") ; 
	}
}