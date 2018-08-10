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
#define hashp 999983 

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

typedef struct node{
	int mini, maxi ;  
	int zor ; 
}node ; 

node stree[10*MXN+2] ;
int a[3*MXN] ; 
int N , M , Q ; 
int ans = INT_MAX ; 

void build(int s, int l , int h , int idx){
	if (l==h && h!=idx){
		return ; 
	}
	if (l==h && h == idx){
		stree[s].mini=stree[s].maxi = a[idx] ; 
		stree[s].zor = a[idx] ; 
		return ; 
	}
	int mid = (l+h)/2 ; 
	build(2*s+1,l,mid,idx) ; 
	build(2*s+2,mid+1,h,idx) ; 
	stree[s].mini = min(stree[2*s+1].mini, stree[2*s+2].mini);
	stree[s].maxi = max(stree[2*s+1].maxi, stree[2*s+2].maxi) ; 
	stree[s].zor = stree[2*s+1].zor^stree[2*s+2].zor ; 
	return ; 
} 

void query(int s, int low, int high, int L, int R){
	
	if (high <L || low >R){
		return  ; 
	}
	if (low == high){
		if (stree[s].zor>=M){
			ans = min(ans,1) ; 
		}
		return ; 
	}
	int mid = (low+high)/2 ; 
	
	if (low>=L && high<=R && stree[s].zor >= M){
		ans = min(ans,high-low+1) ; 
	}
	
	query(2*s+1,low,mid,L,R) ; 
	query(2*s+2,mid+1,high,L,R) ; 
	return ; 

}

int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 

	int t ; cin >> t ; 
	while (t--){
		cin >> N >> M >> Q ; 

		clr(a) ; 
		clr(stree) ; 
		forn(i,0,N){
			cin >> a[i] ; 
			build(0,0,N-1,i) ; 
		}
		int L , R ; 
		
		while (Q--){
			ans = INT_MAX ; 
			cin >> L >> R ; 
			query(0,0,N-1,L-1,R-1) ; 
			if (ans == INT_MAX){
				cout << "-1" << el; 
			}
			else{
				cout << ans << el ; 
			}
		}
	}

}











