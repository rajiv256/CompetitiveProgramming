#include <iostream>
#include <cmath>
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std ; 

#define M 100000


#define forn(i,n) for (int i = 0 ; i < n ;i++)


int contig(int a[],int n,int prev[] , int now[]){
	prev[0] = a[0] ; 
	now[0] = a[0] ; 
	int ans = -1E9 ;
	if (ans < prev[0])
		ans = prev[0] ; 
	for (int i = 1 ; i < n ; i++){
		prev[i] = prev[i-1] + a[i] ;
		if (ans < prev[i])
			ans = prev[i] ;   
	}
	 
	for (int i = 1 ; i < n ; i++){
		for (int j = i+1 ; j < n ; j++){
			now[j] = prev[j] - prev[i-1] ; 
			if (ans < now[j])
				ans = now[j] ; 

		}
	}
	if (ans < a[n-1])
		ans = a[n-1] ; 
	return ans ; 

}

int non_contig(int a[],int n,int L2[]){
	L2[n-1] = a[n-1] ; 
	forn(i,n){
		L2[i] = a[i] ;
	}

	for (int i = n-1 ; i >= 0 ; i--){
		for (int j = i+1 ; j < n ; j++){
			if (L2[i] < L2[j] + a[i]){
				L2[i] = L2[j] + a[i] ;
			}
		}
	}
	int ans = -1E9;
	forn(i,n){
		if (ans < L2[i]){
			ans = L2[i] ; 
		}
	}
	return ans ;
}

int main() {
	int t ; cin >> t ; 
	int prev[M+1] = {0} ; 
    int now[M+1] = {0} ; 
    int L2[M+1] = {0} ; 
    //cout <<"sdff\n" << t << endl ; 
		
    while (t--){
		memset(prev,0,sizeof(int)*(M+1)) ; 
        memset(now,0,sizeof(int)*(M+1)) ; 
        memset(L2,0,sizeof(int)*(M+1)) ; 
        int n ; cin >> n ; 
		int a[n] ; int temp; 
		forn(i,n){
			cin >> temp ; a[i] = temp ; 
		}
		int ans1 = contig(a,n,prev,now) ; 
		int ans2 = non_contig(a,n,L2) ; 
		cout << ans1 << " " << ans2 << endl ; 
	}
	return 0 ; 							
}