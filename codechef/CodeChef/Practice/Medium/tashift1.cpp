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


int prefix(string s , string t,int i , int j){
	int cnt = 0 ; 
	while (s[i]==t[j] && i<s.size()){
		cnt++ ; 
		i++ ; j++ ; 
	}
	return cnt ; 
}

int main(){
	int N ; cin >> N ; 
	string s , t ; cin >> s >> t ; 
	vi v12 ; 
	vi v21 ;
	int x = prefix(s,t,0,0) ; 
	v12.pb(x) ; 
	v21.pb(x) ;  
	forn(i,1,N){
		if (s[0]==t[i]){
			if (v12[i-1]==0)
				v12.pb(prefix(s,t,0,i));
			else 
				v12.pb(v12[i-1]-1) ; 
		}
		else{
			v12.pb(0) ; 
		}
		if (s[i]==t[0]){
			if (v21[i-1]==0)
				v21.pb(prefix(s,t,i,0)); 
			else{
				v21.pb(v21[i-1]-1) ;
			}
		}
		else{
			v21.pb(0) ; 
		}
	}
	int ans = 0 ; int nshift = 0 ;  
	for(int i = 0 ; i < N ; i++){
		if (ans < v12[i]){
			ans = v12[i] ; 
			nshift = i ; 
		}
		if (i+v12[i] == N){
			if (ans < v12[i]+v21[v12[i]]){
				ans = v12[i]+v21[v12[i]] ; 
				nshift = i ; 
			}
		}
	}
	cout << nshift << el ;

}