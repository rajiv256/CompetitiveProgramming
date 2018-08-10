#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <cmath>

using namespace std ; 
typedef vector<int> vi ; 
#define forn(i,n) for (int i = 0 ; i < n ; i++)

int array2num(vi buff){
	int res = 0 ; 
	forn(i,buff.size()){
		res += pow(2.0,double(i))*buff[i] ; 
	}
	return res ; 
}

int main() {
	int t ; cin >> t ; 
	while (t--){
		//cout << "wtf" ;
		int n ; cin >> n ;
		//cout << "here\n" ;   
		string s ; cin >> s ;

		vector<char> v ; v.resize(s.size()) ; 
		vi buff ; buff.resize(n) ; 
		forn(i,s.size()){
			int temp = i ; 
			forn(j,n){
				buff[n-j-1] = temp%2 ; 
				temp = temp/2 ; 
			}
			int num = array2num(buff) ; 
			v[num] = s[i] ; 
		}
		forn(i,s.size()){
			cout << v[i] ; 
		}
		cout << endl ; 
	}
	return 0 ; 
}

