#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;

#define forn(i,n) for(int i = 0; i < n ; i++)
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el endl
#define ll long long
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MXN 100003
#define gc getchar_unlocked	
void sci(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
void scll(ll &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

ll arr[MXN] ; 
ll levend[31]  ;
ll n , m , x , y  ; 

bool isValid(ll idx,int level){
	if ((idx<=0) || (idx>levend[level])){
		return false ; 
	}
	return true ; 
}

ll solve(ll x , ll y , int level){
	//cout << x << sp << y << sp << level << el ; 
	if (x > y){
		return 0 ; 
	}
	if (!isValid(x,level) || !isValid(y,level)){
			return 0 ;
		}
	if (level==0){
		ll ret = 0 ; 
		for(int i = x ; i<= y ; i++){
			ret += arr[i] ; 
		}
		return ret ; 
	}
	
	
	if (x==y){
		if(x&1){
			return solve(x/2+1,x/2+1,level-1) ; 
		}
		else{
			ll temp = 0 ; 
			temp += solve(x/2,x/2+1,level-1)  ; 
			return temp%MOD ; 
		}
	}

	
	ll ret = 0 ; 
	int pst = x/2 +(int)(!(x%2==0)) ;  
	int pen = y/2+1 ;  
	
	ret += 3*(solve(pst+1,pen-1,level-1)) ; ret %= MOD ;
	if (x%2==0){
		ret += solve(pst,pst,level-1)%MOD ; 
	}
	else{
		ret += 2*solve(pst,pst,level-1)%MOD ; 
	}
	ret %= MOD ; 
	
	if (y%2==0){
		ret += solve(pen,pen,level-1)%MOD ; 
	}
	else{
		ret += 2*solve(pen,pen,level-1)%MOD ; 
	}
	
	ret %= MOD ; 
	return ret ; 
	
}


int main(){
	int t ; sci(t) ; 
	
	while (t--){
		cin >> n >> m >> x >> y  ; 
		arr[0] = 0 ; 
		memset(arr,0,sizeof(arr)) ; 
		levend[0] = (ll)n ; 
		
		for(int i = 1 ; i < 31 ; i++){
			levend[i] = 2*levend[i-1] - 1 ; 
		}
		forn(i,n){
			scll(arr[i+1]) ; 
		}
		if (n==1){
			cout << arr[1] << el ; 
			continue ; 
		}
		ll ans = 0 ; 
		ans = solve(x,y,m) ; 
		cout << ans << el ; 
	}
}





























