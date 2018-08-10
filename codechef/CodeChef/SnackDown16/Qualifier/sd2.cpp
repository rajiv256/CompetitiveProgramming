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
#define MXN 100003
#define gc getchar_unlocked
ll a[MXN] ; 
ll pre[MXN] ; 
ll suf[MXN] ; 
int n ; 


int main(){
	int t ; sci(t) ; 
	
	while (t--){
		memset(a,0,sizeof(a)); 
		memset(pre,0,sizeof(pre)) ; 
		memset(suf,0,sizeof(suf)) ; 
		
		sci(n) ; 
		ll z = 0 ; ll x ; 
		forn(i,n){
			scanf("%lld",&x) ;
			suf[i] = pre[i] = a[i] = x ; 
		}
		
		for(int i = 1 ; i < n ; i++){
			suf[i] += max(z,suf[i-1]) ; 
		}
		for(int i = n-2 ; i >= 0 ; i--){
			pre[i] += max(z,pre[i+1]) ; 
		}
		ll maxsum = a[0] ; 
		forn(i,n){
			maxsum = max(maxsum,a[i]) ;
			maxsum = max(maxsum,pre[i]); 
			maxsum = max(maxsum,suf[i]) ; 
			 
		}
		
		ll p = pre[0] ; ll s = suf[0] ;   
		for(int i = 0 ; i < n ; i++){
			if (a[i] >= 0){
				continue ; 
			}
			if (i == 0){
				maxsum = max(maxsum,pre[1]) ;
				continue ; 
			}
			else if (i == n-1){
				maxsum = max(maxsum,suf[n-2]); 
				continue ; 
			}
			else{
				p = pre[i+1] ; 
				s = suf[i-1] ; 
				maxsum = max(maxsum,p+s) ; 
				continue ; 
			}
		}
		cout << maxsum << el ; 
	}
	return 0 ; 
	
}
