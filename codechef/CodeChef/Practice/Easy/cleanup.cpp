#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using namespace std ;

typedef vector<int> vi ; 

#define forn(i,n) for (int i = 0 ; i < n ; i++)

int main() {
	int t ; cin >> t ; 
	while (t--){
		int n , m ; cin >> n >> m ; 
		vi tasks ; tasks.resize(n) ; 
		forn(i,n){
			tasks[i] = i+1 ; 
		}
		forn(i,m){
			int k ; cin >> k ; 
			tasks.erase(remove(tasks.begin(),tasks.end(),k),tasks.end()) ;
		}
		sort(tasks.begin(),tasks.end()) ; 
		 
		int flag = 0 ;  vi chef ; vi ass ; 
		for (int i = 0 ; i < tasks.size() ; i+=2){
			chef.push_back(tasks[i]) ; 
		}
		for (int i = 1 ; i < tasks.size() ; i+= 2){
			ass.push_back(tasks[i]) ; 
		}
		//sort(chef.begin(),chef.end()) ; 
		//sort(ass.begin(),ass.end()) ; 
		forn(i,chef.size()){
			cout << chef[i] << " " ; 
		}
		cout << endl ; 
		forn(i,ass.size()){
			cout << ass[i] << " " ; 
		}
		cout << endl ; 
	}
	return 0 ; 
}
