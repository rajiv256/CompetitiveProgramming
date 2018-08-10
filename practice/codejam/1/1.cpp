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
#define MXN 100005
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

int pivot(int n){
	return floor((n-1)/2) ; 
}
bool solve(int a[], int n , int si , int ei, int smallest, int largest){

	if (si >= ei){
		return true ;    // this is the worst case.  
	}
	int piv = si+pivot(ei-si+1) ; 

	if (a[piv] == smallest){
		int idx = -1 ; 
		for(int i = 0 ; i < n ; i++){
			if (a[i]==smallest){
				idx = i ; break ;  
			}
		}
		while (idx != si){
			int temp = a[idx] ;
			a[idx] = a[idx-1] ; 
			a[idx-1] = temp ; 
			idx-- ;  
		}
		return solve(a,n,si+1,ei,smallest+1,largest)  ; 
	}
	if (a[piv] == largest){
		int idx = n ; 
		for(int i = 0 ; i < n ; i++){
			if (a[i]==largest){
				idx = i ; break ;  
			}
		}
		while (idx != ei){
			int temp = a[idx] ;
			a[idx] = a[idx+1] ; 
			a[idx+1] = temp ; 
			idx++ ;  
		}
		return solve(a,n,si,ei-1,smallest,largest-1)  ; 
	}
	return false ; 


}






int main(){

	int t; sci(t) ; int kase = 1 ; 
	while (t--){
		//printf("kase : %d\n", kase);
		int n ; sci(n) ; 
		int a[n] ; forn(i,0,n) sci(a[i]) ; 

		if (solve(a,n,0,n-1,1,n)){
			printf("Case #%d: YES\n",kase);
		}
		else printf("Case #%d: NO\n",kase);

		kase++ ; 
	}

}
