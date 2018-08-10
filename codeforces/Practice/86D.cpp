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
#define sci(x) scanf("%d",&x)
#define MXN 100003
#define gc getchar_unlocked	

typedef struct query{
	int idx ; 
	int l , r ; 
}query;



int BLOCK = 1 ; 
int arr[2*MXN] ; 
int occur[1000009] ;
query qs[2*MXN] ;
ll curr = 1  ;
inline void remove(int idx){
	ll temp = occur[arr[idx]] ; 
	occur[arr[idx]]-- ; 
	
		curr -= (2*temp-1)*arr[idx] ; 
	
	 
}
inline void add(int idx){
	
	ll temp =  occur[arr[idx]] ; 
	occur[arr[idx]] += 1  ;
	
	//cout << idx << sp << temp << el ;
	curr += (2*temp+1)*arr[idx] ; 
	
}
bool comp(query q1 , query q2){
	if ((q1.idx+1)/BLOCK != (q2.idx+1)/BLOCK){
		return ((q1.idx+1)/BLOCK < (q2.idx+1)/BLOCK) ; 
	}
	else{
		return (q1.r < q2.r) ; 
	}
}



int main(){
	int n , t ; cin >> n >> t ; 
	memset(arr,0,sizeof(arr)) ;
	memset(occur,0,sizeof(occur)) ; 
	memset(qs,0,sizeof(qs)) ; 
	BLOCK = sqrt(n) ; 
	forn(i,n){
		sci(arr[i]) ; 
	}
	int a , b  ; 
	int currL = 0 ; int currR = 0 ; curr = arr[0] ; occur[arr[0]] += 1 ;  
	
	forn(i,t){
		qs[i].idx = i ; 
		sci(a) ; sci(b) ; a-- ; b-- ; 
		qs[i].l = a ; qs[i].r = b ; 
	}
	
	sort(qs,qs+t,comp) ; 
	ll ans[t] ; 
	forn(i,t){
		int l = qs[i].l ; int r = qs[i].r ; 
		while (currL < l){
			//cout << "wth" << el ; 
			remove(currL) ; 
			currL++ ; 
		}
		while (currL > l){
			//cout << "wtfjh" << el ; 
			currL-- ; add(currL) ; 
		}
		while (currR > r){
			//cout << "wtf" << el ;
			remove(currR) ; 
			currR-- ; 
		}
		while (currR < r){
			//cout << "hell" << el ; 
			currR++ ; 
			add(currR) ; 
		}
		ans[qs[i].idx] = curr ; 
	}
	
	forn(i,t){
		cout << ans[i] << el ; 
	}
	
	return 0 ; 
}
