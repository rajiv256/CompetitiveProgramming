#include <bits/stdc++.h> 
using namespace std ; 

#define ll long long 
#define el endl 
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100003 
#define INF 10000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()

int main(){
	int N  ; cin >> N ; 
	int a[N] , L[N] ; 
	forn(i,0,N){
		cin >> a[i] ; 
		L[i] = 1 ; 
	}
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < i ; j++){
			if (a[j] <= a[i]){
				if (L[i] < L[j]+1){
					L[i] = L[j]+1 ; 
				}
			}
		}
	}
	int maxi = 1 ; 
	for(int i = 0 ; i < N ; i++){
		maxi = max(L[i],maxi) ; 
	}
	cout << maxi << el ; 

}