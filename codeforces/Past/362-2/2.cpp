#include <bits/stdc++.h>
using namespace std ; 

#define ll long long 
#define el endl 
#define forn(i,st,en) for(int i = st ; i < en ; i++)
#define sp " " 
#define pb push_back

string format(string s){
	ret = "" ; 
	it = s.size()-1 ;
	while (it >= 0 && (s[it]=='0' || s[it]=='.')){
		it -= 1 ; 
	}
	if (s[it]=='.'){
		it -= 1 ;
	}
	while (it >= 0){
		ret += s[it--] ; 
	}
	return reverse(ret) ; 
}




int main(){
	string s ; cin >> s ; 
	string s1 = "" ; string s2 = "" ; 
	int it = 0 ; 
	while (it < s.size() && s[it]=='e'){
		s1 += s[it++] ; 
	}
	it += 1 ; 
	while (it < s.size()){
		s2 += s[it++] ; 
	}
	string a  = format(s1) ; 
	int b = atoi(s2.c_str()) ; 

	vector<char> v ; 
	int idx = -1 ; 
	forn(i,0,s1.size()){
		if (s1[i]=="."){
			idx = i ; 
		}
		else{
			v.pb(s1[i]) ; 
		}
	}
	idx += b ;
	if (idx < a.size()){
		
	}




}