#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std ;
typedef vector<int> vi ; 
typedef vector<pair<int,int> > vp ; 

typedef unsigned long long ull ; 

#define forn(i,n) for (int i = 0 ; i < n ; i++)
#define lld long long int

struct Event {
	int st ; int end ; int c ; 

	bool operator< (const Event& e) const 
	{
		if (st < e.st){
			return true ; 
		}
		else if(st == e.st){
			if (end <= e.end){
				return true ;
			}
			else {
				return false ; 
			}
		}
		return false ;
	}
}; 


bool overlap(Event p1 , Event p2){
	if (p2.st >= p1.end){
		return false ; 
	}
	return true ; 
}


void dp(vi& L , Event ev[] , int n){
	forn(i,n){
		L[i] = ev[i].c ; 
	}
	for (int i = n-1 ; i >= 0 ; i--){
		for (int j = i+1 ; j<n; j++){
			if (!overlap(ev[i],ev[j])){
				if (L[i] < L[j] + ev[i].c){
					L[i] = L[j] + ev[i].c ; 
				}
			}
		}
	}
	/*forn(i,n){
			cout << L[i] << " "<< endl ; 
		}*/
	return ; 
}





int main() {
	int t ; cin >> t ; 
	while (t--){
		int n ; cin >> n ; 
		
		Event ev[n] ;  

		int a,b,c ; 
		for (int i = 0 ; i < n ; i++){
			cin >> a >> b >> c ; 
			ev[i].st = a ; ev[i].end = b ; ev[i].c = c ;  
		}
		std::sort(ev,ev+sizeof(ev)/sizeof(ev[0])) ; 
		/*forn(i,n){
			cout << ev[i].st << " " << ev[i].end << endl ; 
		}*/
		vi L(n,0) ;
		dp(L,ev,n) ; 
		int maxi = -1 ; 
		forn(i,n){
			if (maxi < L[i]){
				maxi = L[i] ; 
			}
		}
		cout << maxi << endl ; 

	}
}
