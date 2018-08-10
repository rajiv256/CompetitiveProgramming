#include <bits/stdc++.h>

using namespace std ; 

#define ll long long 
#define el endl 
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define clear(x) memset(x,0,sizeof(x))
#define MXN 100003 
#define INF 10000000000

ll L[MXN] ; 

bool great(string G, string g){
	if (G.size() > g.size()){
		return true ; 
	}
	if (G.size() < g.size()){
		return false ; 
	}
	if (G.size() == g.size()){
		int it = 0 ; 
		while (it < g.size()){
			if (g[it] > G[it]){
				return false ; 
			}
			it++ ; 
		}
	}
	return true ; 
}



int solve(string s , string a , string b , int idx){
	if (idx == s.size()){
		return 0  ; 
	}
	string temp = "" ; 
	ll ret = -1 ; 
	if (L[idx] != -1){
		return L[idx] ; 
	}

	for (int i = idx ; i < s.size() ; i++){
		temp += s[i] ;
		

		if (great(temp,a) && great(b,temp)){
			
			L[i+1] = solve(s,a,b,i+1) ; 
		
			if (L[i+1] != -1){
				if (ret==-1){
					ret = 1+L[i+1] ; 
				}
				else{
					ret= min(ret,1+L[i+1]) ; 
				}
			}
		}
	}
	return ret ; 
	 
}

int main(){
	int t ; sci(t) ; 
	ios_base::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	while (t--){
		string s ; string a ; string b ; 
		cin >> s >> a >> b ; 
		forn(i,0,MXN){
			L[i] = -1 ; 
		}
		L[0] = solve(s,a,b,0) ; 
		
		if (L[0] <= 0){
			cout << "-1" << el ; 
		}
		else
			cout << L[0]-1 << el ;
	}
}