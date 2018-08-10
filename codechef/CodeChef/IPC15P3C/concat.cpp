#include <bits/stdc++.h> 

using namespace std ; 

#define ll long long 
#define forn(i,st,en) for(int i = st ; i < en ; i++)
#define clean(x) memset(x,0,sizeof(x)) 
#define el endl 

int main(){
	ios_base::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	string s ; cin >> s ; 
	string p ; cin >> p ; 
	forn(i,0,s.size()){
		if (p.find(s[i]) == string::npos){
			cout << "-1" << el ; 
			return 0 ; 
		}
	}
	int count = 0 ; 
	int ptr = 0 ; 
	while (ptr < s.size()){
		int sptr = 0 ; count ++ ; 
		sptr = p.find(s[ptr]) ; 
		while (sptr!=string::npos && ptr < s.size()){
			ptr++ ; 
			sptr = p.find(s[ptr],sptr+1) ;  
		}
	}
	cout << count << el ; 




}