#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cstring>
#include <cmath>

using namespace std; 
#define forn(i,n) for(int i = 0 ; i < n ; i++)
#define M 1000000 

typedef vector<int> vi ; 
typedef unsigned long long ull ; 

bool pp[M+1] ; 
map<int,int> final ; 

void sieve() {
	 
	for (int i = 2 ; i <= sqrt(M) ; i++){
		if (!pp[i]){
			for (int j = 2 ; i*j <= M ; j++){
				pp[i*j] = true ; 
			}
		}
	}
	return ; 
}


void pm(map<int,int> m){
	cout <<"map start\n" ; 
	for (map<int,int> :: iterator it = m.begin() ; it != m.end() ; it++){
		cout << (*it).first <<" ---> "<< (*it).second << endl ; 
	}
	cout <<"map ends\n" ; 	

}

void getMap(ull n){
	int N  = n ; 
	  
	while (n %2 == 0){
		//cout << "added 2\n" ; 
		final[2] += 1 ; 
		n = n/2 ; 
	}
	int i = 3 ; 
	while ((n > 1) && i <= n){
		if (!pp[i]){
			while ((n%i == 0) && (n != 0)){
				final[i]+=1 ;
				n = n/i ; 
			}
		}
		i += 2 ; 
	}
	return  ; 


}


int main(){

	int t ; cin >> t ; 
	memset(pp,false,sizeof(bool)*(M+1)) ; 
	sieve() ; 
	/*forn(i,10){
		cout << pp[i] << " " ;
	}
	cout << endl ;*/
	while (t--){
		int n ; cin >> n ; 
		vector<ull> a ; a.resize(n) ;
		forn(i,n){
			cin >> a[i] ;
		}
		vector<map<int,int> > vm ; 
		ull num = 1 ;  
		forn(i,n){
			getMap(a[i]) ;  
		}
		
		
		/*forn(i,n){
			for (map<int,int> :: iterator it = vm[i].begin() ; it != vm[i].end() ; it++ ){
				final[(*it).first] += (*it).second  ;
			}	
		}*/
		ull result = 1 ; 
		for (map<int,int>:: iterator it = final.begin() ; it != final.end() ; it++){
			//cout << (*it).first <<" --> " << (*it).second << endl ; 
			result *= ((*it).second + 1) ; 
		}
		cout << result << endl ; 
		final.clear();

	}



}
