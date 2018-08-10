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
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;
#define pb push_back
#define mp make_pair

// 0,1,1,2,3,...
int F(int n){
	if (n == 0){
		return 0 ; 
	}
	if (n == 1 || n==2){
		return 1 ; 
	}
	if (n%2==0){
		int k = n/2 ; 
		int l = F(k-1) ; int r = F(k) ; 
		
		return (((2*l)%MOD+r%MOD)*l)%MOD ; 
	}
	else{
		int k = (n+1)/2 ; 
		int l = F(k-1) ; int r = F(k) ; 
		return (((r*r)%MOD+(l*l)%MOD)%MOD) ; 
	}
}

typedef struct node {
	int num ;  
	int fib ; 
	void merge(node n1, node n2){
		fib = (n1.fib+n2.fib)%MOD ;  
	}

}node ; 

node stree[4*MXN] ; 

int arr[MXN] ;

void build(int low , int high , int s){
	if (low > high){
		return ; 
	}
	if (low == high){
		stree[s].num = arr[low] ;
		stree[s].fib = F(stree[s].num) ; 
		//cout << low << sp << stree[s].num+1 << sp << stree[s].fib << el ; 
		return ;  
	}
	int mid = (low+high)/2 ; 
	build(low,mid,2*s) ; 
	build(mid+1,high,2*s+1) ; 
	stree[s].fib = (stree[2*s].fib + stree[2*s+1].fib)%MOD  ; 
	return ; 
}

void update(int low , int high , int left ,int right , int s, int x){
	if (low>right || high<left){
		return ; 
	}
	if (low==high){
		stree[s].num += x ; 
		stree[s].fib = F(stree[s].num) ; 
		return ; 
	}
	int mid = (low+high)/2 ; 
	update(low,mid,left,right,2*s,x) ; 
	update(mid+1,high,left,right,2*s+1,x) ; 
	stree[s].merge(stree[2*s],stree[2*s+1]) ; 
	return ; 
}
int query(int low , int high, int left , int right , int s){
	//cout << s << sp << low << sp << high << sp << left << sp << right << el ;
	if (low>right || high<left){
		//cout << "her" << el ;
		return 0 ; 
	}
	if (low>=left && high<=right){
		return stree[s].fib ; 
	}
	int mid = (low+high)/2 ; 
	int x1 = query(low,mid,left,right,2*s) ; 
	int x2 = query(mid+1,high,left,right,2*s+1) ; 
	return (x1+x2)%MOD ; 
}




int main(){
	int n , m  ; cin >> n >> m ; 
	memset(arr,0,sizeof(arr)) ; 
	clr(stree) ; 
	//clr(lazy)  ; 

	forn(i,0,n){
		int x ; cin >> arr[i+1] ; 
	}
	build(1,n,1) ; 
	 
	forn(i,0,m){
		int fl , l , r,val ; 
		cin >> fl ; 
		if (fl == 1){
			cin >> l >> r >> val; 
			update(1,n,l,r,1,val) ; 
		}
		if (fl == 2){
			cin >> l >> r ; 
			cout << query(1,n,l,r,1) << el ; 
		}
	}
}