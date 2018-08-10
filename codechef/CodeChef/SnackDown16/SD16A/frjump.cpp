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
//#define sci(x) scanf("%d",&x)
#define MXN 100003
#define MOD 1000000007
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
 
ll arr[MXN] ; 
ll prod[MXN][3] ; 

void update(ll p , ll f, int n){
	if (p==1){
		for(int i = 1; i<= n ; i++){
			prod[i][2] *= arr[1] ; prod[i][1] *= f ; prod[i][2] %= MOD ; prod[i][1] %= MOD ;  
		}
		arr[1] = f ; 
		return ; 
	}
	ll num = p-1 ; 
	for(int i = 1 ; i <= sqrt(num) ; i++){
		if (i == sqrt(num)){
			if (sqrt(num)==(ll)sqrt(num)){
				prod[i][2] *= arr[p] ; prod[i][1] *= f ; 
			}
			continue ; 
		}
		if (num%i==0){
			prod[i][2] *= arr[p] ; prod[i][1] *= f ; 
			prod[num/i][2] *= arr[p] ; prod[num/i][1] *= f ;  
		}
	}
	
	
	arr[p] = f ; 
	return ; 
}

ll query(ll r){
	ll ret = 1; 
	ret = ((prod[r][0]*prod[r][1])/prod[r][2]) ; 
	return ret ; 
}

ll first(ll temp){
	while (temp/10 != 0){
		temp /= 10 ; 
	}
	return temp ; 
}



int main(){
	int n ; sci(n) ; 
	memset(arr,0,sizeof(arr)) ;
	memset(prod,1,sizeof(prod)) ; 
	for(int i = 1 ; i <= n ; i++){
		cin >> arr[i] ; 
		prod[i][0] = 1; prod[i][1] = 1  ;prod[i][2] = 1 ; 
	}
	for(int r = 1 ; r <= n ; r++){
		for(int i = 1 ;i <= n ; i+=r){
			prod[r][0]*= arr[i] ; prod[r][1] = 1 ; prod[r][2] = 1 ; 
		}
	}
	
	
	int q ; sci(q) ; int fl , p , f  , r ; 
	while (q--){
		sci(fl) ; 
		if (fl == 1){
			sci(p) ; sci(f) ; 
			update(p,f,n) ; 
			forn(i,n){
				cout << arr[i+1] << sp ; 
			}
			cout << el ; 
		}
		if (fl==2){
			sci(r) ; 
			ll ans = query(r) ;
			cout << first(ans) << sp << ans << el ; 
		}
	}
	
}
































