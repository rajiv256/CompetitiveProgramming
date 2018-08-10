#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio> 
#include <cstdlib> 

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
#define pb push_back




int main() {

	int n , k ; scanf("%d%d",&n,&k) ; 
	vi v ; v.rsz(n) ; 
	forn(i,n){
		scanf("%d",&v[i]) ; 
	}


	int r ; scanf("%d",&r) ; 
	int st , en ; 
	while (r--){	
		scanf("%d%d",&st,&en) ;
		//cout << "What??" << el ; 
		vi dup(v) ; 
		sort(dup.begin()+st , dup.begin()+en+1) ; 
		int idx = st ; int cnt = 0 ; 
		while (true){
			if (idx + k > en){
				break ; 
			}
			if (dup[idx] == dup[idx+k]){
				//cout << idx <<el ; 
				cnt++ ;
				idx = idx+k ;  
				int temp = dup[idx+k] ; 
				for (int i = idx+k+1 ; i <= en ; i++){
					if (dup[i] != temp){
						idx = i ; 
						break  ; 
					}

				}
			}
			else {
				int temp = dup[idx] ; 
				for (int i = idx+k ; i >= idx ; i--){
					if (dup[i] == temp){
						idx = i+1 ; 
						break ;
					}
				}
			}
		}
		printf("%d\n",cnt) ;  
	}
	return 0 ; 
}