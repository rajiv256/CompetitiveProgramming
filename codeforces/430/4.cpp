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



#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define YES "YES\n"
#define NO "NO\n"



int main(){
	int n , m ; cin >> n >> m ; 

	int bor = 0 ; 
	forn(i,0,n){
		cin >> a[i] ;  
	}

	sort(a,a+n) ; 
	for(int i = 0 ; i < m ; i++){
		int x ; cin >> x ; 
	
		if (!binary_search(a,a+n,x)){
			cout << "0\n" ; 
		}
		else{
			int res = 1 ; 
			int low = (lower_bound(a,a+n,x)-a) -1 ; 
			int high = (upper_bound(a,a+n,x)-a) ; 

			if (low > 0){
				
			}
			if (high < n){

			}


		}



	}




}