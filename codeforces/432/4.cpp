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
#define INF 1000000003
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

ll c[20*MXN] ; 
ll s[20*MXN] ; 
ll x , y , n ; 




int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 

	scanf("%lld%lld%lld",&n,&x,&y);
	int i,j,k,p=x/y; ll xxx; 
	for (i=1; i<=n; i++){
		scanf("%lld",&xxx);
		c[xxx]++; s[xxx]+=xxx;
	}
	for (i=1; i<=2000000; i++){
		c[i]+=c[i-1]; s[i]+=s[i-1];
	}

	
	
	ll ans=(ll)n*x; 
	for (int i=2; i<=1000000; i++){
		ll tmp=0;
		for (int j=i; j<=1000000+i && tmp<ans; j+=i){
			int k=max(j-i+1,j-p);
			tmp+=((ll)(c[j]-c[k-1])*j-(s[j]-s[k-1]))*y;
			tmp+=(ll)(c[k-1]-c[j-i])*x;
		}
		ans=min(ans,tmp);
	}
	cout << ans << el ; 
	return 0 ; 
}






















