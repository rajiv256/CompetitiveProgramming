#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std ;
#include <bits/stdc++.h> 
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
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp " " 
#define el "\n"
#define lld long long int 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 

int main() {
	char c ; vi v ;  
	forn(i,5) {

		string s ; cin >> s ; 
		if (i != 0){
			if (c != s[1]){
				cout << "NO\n" ;
				return 0 ;  
 			}
		}
		
		c = s[1] ; 
		if (s[0] == 'A'){
			v.push_back(1) ;
			  
		}
		else if (s[0] == 'J'){
			v.push_back(11) ; 
		}
		else if (s[0] == 'Q'){
			v.push_back(12) ; 
		}
		else if (s[0] == 'K'){
			v.push_back(13) ; 
		}
		else if (s[0] == 'T'){
			v.push_back(10) ; 
		}
		else {
			v.push_back(s[0]-'0') ; 
		}
		
		

	}
	sort(all(v)) ; 
	if (v[0] == 1){
		forn(i,5){
			v[i] -= 1 ; 
		}
		int res = 0 ; 
		forn(i,5){
			res += v[i] ; 
		}
 
		if (res == 10){
			cout << "YES\n" ; 
			return 0 ; 
		}
		// forn(i,5){
		// 	cout << v[i] << sp ; 
		// }
		//cout << el ; 
		v.erase(v.begin()) ; 
		v.push_back(13) ; 
		// forn(i,5){
		// 	cout << v[i] << sp ; 
		// }
		// cout << el ; 
		int t = v[0] ; 
		forn(i,5){
			v[i] -= t ; 
		}
		res = 0 ;
		forn(i,5){
			res += v[i] ; 
			//cout << res << "wtf" << el ;
		}
		//cout << res << el  ; 
		if (res == 10){
			cout << "YES\n" ; 
			return 0 ; 
		}
		cout << "NO\n" ; 
		return 0 ; 
	}
	int res = 0 ; 
	int t1 = v[0] ; 
	forn(i,5){
		v[i]-= t1 ; 
		res += v[i] ; 
	}
	if (res == 10){
		cout << "YES\n" ; 
		return 0 ;
	}
	cout << "NO\n" ; 
	return 0 ; 
	
}