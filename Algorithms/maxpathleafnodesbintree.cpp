// Not complete. But a few modifications will be sufficent. 



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
#define INF 10000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef std::vector<std::vector<int> > vvi;
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

void dfs(vector<pair<pair<int,int>,int> >& tree, int root, int N){
	//cout << root << el ; 
	if (root >= N){
		return ; 
	}
	if (2*root+1 >= N){
		return ; 
	}
	else{
		dfs(tree,2*root+1,N) ;
		dfs(tree,2*root+2,N) ; 
		if (2*root+1 >= N){
			return ; 
		}
		tree[root].xx.xx = 1+max(tree[2*root+1].xx.xx,tree[2*root+1].xx.yy) ; 
		tree[root].xx.yy = 1+max(tree[2*root+2].xx.xx,tree[2*root+2].xx.yy) ; 
		tree[root].yy    =  tree[root].xx.xx+tree[root].xx.yy  ; 
	}
	return ; 
}




int main(){
	int N ; cin >> N ; 
	vector<pair<pair<int,int>,int> >tree ;
	forn(i,0,N){
		tree.pb(mp(mp(0,0),0)) ; 
	}  
	dfs(tree,0,N) ; 
	int ans = INT_MIN ; 
	forn(i,0,N){
		ans = max(ans,tree[i].yy) ; 
	}
	cout << ans << el ; 
}