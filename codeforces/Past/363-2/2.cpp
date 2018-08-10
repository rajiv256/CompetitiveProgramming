#include <bits/stdc++.h>

using namespace std ; 
#define el endl 
#define forn(i,st,en)  for(int i = st ; i < en ; i++)
#define sp " "
#define pb push_back

typedef vector<char> vc  ; 
typedef vector<int> vi ; 

int main(){
	int n , m ; cin >> n >>m ; 
	char a[n][m] ; 
	forn(i,0,n){
		forn(j,0,m){
			cin >> a[i][j] ; 
		}
	}
	int nr[n] ; int nc[m] ; 
	memset(nr,0,sizeof(nr)) ; 
	memset(nc,0,sizeof(nc)) ; 

	int total = 0 ; 
	forn(i,0,n){
		forn(j,0,m){
			if (a[i][j]=='*'){
				nr[i]++ ; nc[j]++ ; 
				total++ ; 
			}
		}
	}
	forn(i,0,n){
		forn(j,0,m){
			if (a[i][j]=='*'){
				if (nr[i]+nc[j]-1 == total){
					cout << "YES" << el ; 
					cout << i+1 << sp << j+1 << el ;
					return 0 ; 
				}
			}
			else{
				if (nr[i]+nc[j]==total){
					cout << "YES" << el ; 
					cout << i+1 << sp << j+1 << el ;
					return 0 ; 	
				}
			}
		}
	}
	cout << "NO" << el ; 
	return 0 ; 
}
