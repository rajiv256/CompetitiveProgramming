#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int>  vi ; 
typedef vector<pair<int,int> > vp ;
typedef vector<bool> vb ; 
typedef unsigned long long ull ;

#define forn(i,n) for(int i = 0 ; i < n ; i++)
#define lld long long int 
#define MAX 1000001 

ull a[MAX],bit[MAX] = {0} , res = 0 ; 

int N , Q , p , q ; 
char c ; 

void update(int idx , int val ){
	while (idx <= N){
		bit[idx] += val ; 
		idx += (idx & -idx) ; 
	}
}

ull getSum(int n){
	ull r = a[n] ; 
	while ( n > 0 ){
		r += bit[n] ; 
		n -= n & -n ; 
 	}
 	return r ; 

}

int main() {
	cin >> N >> Q ; 
	cin >> a[1] ; 
	for(int i = 2 ; i <= N ; i++){
		int k ; 
		cin >> k ;
		a[i] = a[i-1] + k ;  
	}

	while (Q--){
		cin >> c ; 
		cin >> p >> q ; 
		p++ ; 
		if (c == 'T'){
			update(p,-q) ; 
		}
		else if (c == 'G'){
			update(p,q) ; 
		}
		else {
			q++ ;
			if (p == q){
				res = a[q] - a[p-1] ; 
			}
			else{
				if (p != 1){
					res = getSum(q) - getSum(p-1) ; 
				}
				else {
					res = getSum(q) ; 
				}
			}
			cout << res << endl ; 
			res = 0 ; 
		}
		
	}
	return 0 ; 
}