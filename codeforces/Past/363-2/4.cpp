#include <bits/stdc++.h>

using namespace std ; 

#define ll long long 
#define el endl 
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100003 
#define INF 10000000000
#define MOD 1000000007

typedef vector<int> vi ; 
typedef vector<char> vc ; 
typedef vector<bool> vb ; 
typedef pair<int,int> pii ; 
typedef vector<pii > vpii ; 
typedef vector<vi > vvi ; 

#define pb push_back
#define mp make_pair
#define xx first
#define yy second 

int parent[2*MXN] ; 
int anc[2*MXN] ; 


int main(){
	int n ; cin >> n ; 
	int a[n] ; 
	forn(i,0,n){
		cin >> a[i] ; 
		a[i]-= 1 ;
	}
	int ans = 0 ; 
	int root = -1 ;
	forn(i,0,n){
		anc[i] = -1 ; 
		parent[i] = -1 ; 
	}
	forn(i,0,n){
		if (a[i]==i)
			root = i ; 
	}

	int T = -1 ; 
	for(int i = 0; i< n ; i++){
		 T++ ;
		if (anc[i]==-1){
			int x = i ; 
			 
			while (anc[x]==-1){
				//cout << x << el ; 
				anc[x] = T ;
				x= a[x] ;  
			}
			if (anc[x]==T){
				if (root == -1){
					root = x ; 
					a[x] = x ; 
					ans++ ; 
				}
				if (x != root){
					a[x] = root ; 
					ans++ ; 
				}
			}
		}
	}
	cout << ans << el ; 
	forn(i,0,n){
		cout << a[i]+1 << sp ; 
	}
	cout << el ; 
}