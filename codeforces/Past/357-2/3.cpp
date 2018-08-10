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

int main(){
	string INS = "insert" ; string REM = "removeMin" ; string GET = "getMin" ; 
	priority_queue<int , std::vector<int>, std::greater<int> > pq ; 
	int n ; sci(n) ; int mini = INT_MAX ; 
	pq.push(mini) ; string s ;  vector<string> vs ; vi v ; 
	forn(i,n){
		cin >> s ; int x  ; 
		if (s==INS){
			cin >> x ; 
			pq.push(x) ; 
			mini = pq.top() ; 
			vs.pb(INS) ; v.pb(x) ; 
			continue ; 
		}
		if (s == REM){
			mini = pq.top() ; 
			if (mini==INT_MAX){
				vs.pb(INS) ; v.pb(1) ; 
				vs.pb(REM) ; 
				mini=INT_MAX ; 
				continue ; 
			}
			else{
				pq.pop() ; 
				mini = pq.top() ; 
				vs.pb(REM) ; 
				continue ; 
			}
		}
		if (s == GET){
			cin >> x ; 
			mini = pq.top() ; 
			if (mini == INT_MAX){
				pq.push(x) ; mini = pq.top()  ; 
				vs.pb(INS) ; v.pb(x) ; 
				vs.pb(GET) ; v.pb(x) ; 
				continue ; 
			}
			else{
				if (mini < x){
					mini = pq.top() ;
					while (mini < x){
						pq.pop() ; 
						vs.pb(REM) ; 
						mini = pq.top() ; 
					}
					if (mini == INT_MAX){
						pq.push(x) ; mini = pq.top()  ; 
						vs.pb(INS) ; v.pb(x) ; 
						vs.pb(GET) ; v.pb(x) ; 
						continue ; 
					}
					if (mini == x){
						vs.pb(GET) ; v.pb(x) ; 
						continue ; 
					}
					if (mini > x){
						vs.pb(INS) ; v.pb(x) ; 
						pq.push(x) ; mini = pq.top() ; 
						vs.pb(GET) ; v.pb(x) ;
						continue ; 
					}
				}
				if (mini==x){
					vs.pb(GET) ; v.pb(x) ; 
					continue ; 
				}
				if (mini > x){
					pq.push(x) ; mini = pq.top() ; 
					vs.pb(INS) ; v.pb(x) ; 
					vs.pb(GET) ; v.pb(x) ;
					continue ; 
				}
			
			}
		}
	}
	int it1 = 0 ; int it2 = 0 ; 
	cout << vs.size() << el ; 
	while((it1<vs.size()) || (it2<v.size())){
		cout << vs[it1] << sp ; 
		if(vs[it1]==REM){
			it1++ ; 
			cout << el ; 
			continue ; 
		}
		cout << v[it2] << el ; 
		it1++ ; it2++ ; 
	}
	
	
}
