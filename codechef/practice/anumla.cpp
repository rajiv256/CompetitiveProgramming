/* 
        Code written by rajiv. 
        God speed!
*/
#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define sclf(x) scanf("%lf",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

#define N 16 

int b[1<<N] , c[1<<N] ; 
int a[N] ; 

int main(){
	int t ; sci(t) ; 

	while(t--){
		int n ; sci(n) ; 
		forn(i,0,1<<n){
			sci(b[i]) ; 
		}
		int m = 1<<n ; 
		sort(b,b+m) ; 
		
		multiset<int> s ;
		int cptr = 0 ; int aptr = 0 ; 


		for(int i = 1 ; i < m ; i++){
			int next = -1 ; 
			if (!s.empty()){
				next = *s.begin() ; 
			}

			if (b[i]==next){
				s.erase(s.begin()) ; 
			}
			else{
				a[aptr] = b[i]; 
				int tcptr = cptr ; 
				for(int j = 0 ; j < tcptr ; j++){
					c[cptr++] = c[j]+b[i] ; 
					s.insert(c[j]+b[i]) ; 
				}
				c[cptr++] = a[aptr] ;
				aptr++ ;  

			}

		} 
		for(int i = 0 ; i < n ; i++){
			printf("%d ",a[i] );
		}
		printf("\n");

		



		

	}
}