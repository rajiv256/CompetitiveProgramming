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

int mind(char a , char b){
	if (a == b)
		return 0  ; 
	if (a > b){
		return mind(b,a) ; 
	}
	return min(b-a,a+26-b) ; 
}

int main(){
	string s ; cin >> s ; 
	char ch = 'a' ; 
	int ans = 0 ; 
	forn(i,0,s.size()){
		ans += mind(ch,s[i]) ; 
		ch = s[i] ; 
	}
	cout << ans << el ;
}