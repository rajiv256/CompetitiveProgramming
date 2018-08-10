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

int main(){
	int t ; sci(t) ; 
	//ios::sync_with_stdio(0) ; 
	cin.tie(0); 
	while(t--){
		ll n , k , e , m ,x; 
		cin >> n >> k >> e >> m ; 
		ll scores[n-1] ; 
		 
		forn(i,n-1){
			scores[i]=0;
		}
		forn(i,n-1){
			
			forn(j,e){
				cin >> x ; 
				scores[i] += x ;  
			}
		}
		//cout << "done1" << el ;
		ll myScore = 0 ; 
		forn(i,e-1){
			ll x ; cin >> x ; 
			myScore += x ; 
		}
		//cout <<"done2" <<el; 
		vector<pair<ll,ll> > v ; 
		sort(scores,scores+n-1) ; int cnt = 1 ; 
		ll curr = scores[0] ; int idx = 1; 
		//cout << curr << el ;
		while (idx < n-1){
			if (scores[idx]==curr){
				cnt++ ; 
				idx++ ; 
				if (idx == n-1){
					v.pb(mp(curr,cnt)) ; 
					break; 
				}
			}
			else{
				v.pb(mp(curr,cnt)) ; 
				curr = scores[idx] ; 
				cnt = 1 ;
				idx++ ; 
				if (idx==n-1){
					v.pb(mp(curr,cnt)); 
					break ; 
				}
			}
		}
//		forn(i,v.size()){
//			cout <<v[i].xx<< sp << v[i].yy << el ; 
//		}
//		cout <<el ; 
		sort(all(v)) ; 
		//reverse(all(v)) ; 
		
		ll ans = v[0].xx+1 ;  ll num = 0 ; 
		//cout << ans << el ; 
		for(int i = v.size()-1 ; i>=0 ; i++){
			ll xx = v[i].xx ; ll yy = v[i].yy ; 
			num += yy ; 
			//cout << num << sp << k <<sp << xx<< el ; 
			if (num < k){
				ans = xx-1 ; 
			}
			if (num==k){
				ans = xx+1 ;
				break ; 
			}
			if (num > k){
				ans = xx+1 ; 
				break ; 
			}
		}
		if (ans > e*m){
			cout << "Impossible" << el; 
			continue ; 
		}
		else{
			if (ans-myScore > m){
				cout <<"Impossible" <<el; 
				continue;
			}
			cout << max((ll)0,ans-myScore) << el ; 
			continue ; 
		}
		
	}
}



















