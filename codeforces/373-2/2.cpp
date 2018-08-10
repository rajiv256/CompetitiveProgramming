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

int main(){
	int n ; cin >> n ; 
	string s ; cin >> s ; 
	int nrb = 0 ; int nbr = 0 ; 
	string s1 ; string s2 ;  
	char ch[2] = {'r','b'} ; 
	forn(i,0,n){
		s1 += ch[i%2] ; 
		s2 += ch[(i+1)%2] ; 
	}
	//cout << s1 << el << s2 << el ; 
	int ans  = INT_MAX ; 
	forn(i,0,n){
		if (s1[i] == s[i]){
			continue ; 
		}
		if (s[i]=='r' && s1[i]=='b'){
			nbr ++ ; 
		}
		if (s[i]=='b' && s1[i]=='r'){
			nrb++ ; 
		}
	}
	ans = max(nbr,nrb) ; 
	nbr = 0 ; nrb = 0 ; 
	forn(i,0,n){
		if (s2[i] == s[i]){
			continue ; 
		}
		if (s[i]=='r' && s2[i]=='b'){
			nbr ++ ; 
		}
		if (s[i]=='b' && s2[i]=='r'){
			nrb++ ; 
		}
	}
	ans = min(ans,max(nrb,nbr)) ; 
	cout << ans << el ; 
}