#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdlib.h> 

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
 
int b, g , l ; 

void update(vb& bp, vi& bs , vi& be , int t){
	forn(i,bp.size()){
		if (t >= bs[i] && t < be[i]){
			bp[i] = true ; 
		}
	}
	return ; 
}

bool bpm(int u , vb& bp , vb& gp , vb& seen , int *matchR , bool **A, bool **G){

	for (int v = 0 ; v < g ; v++){
		//cout << v << sp << u << sp << "G[1][0] : " << G[1][0] << el ; 
		if (bp[u] && gp[v] && A[u][v] && G[v][u] && !seen[v]){

			seen[v] = true ; 
			
			if (matchR[v] < 0 || bpm(matchR[v] , bp,gp,seen,matchR,A,G)){
				matchR[v] = u ; 
				return true ; 
			}
		}
	}
	return false ; 
}


int maxMatch(vb& bp , vb& gp , bool **A ,bool **G) {

	//int b = bp.size() ; int g = gp.size() ; 
	int* matchR = (int*)malloc(sizeof(int)*g);  
	forn(i,g){
		matchR[i] = -1 ; 
	}
	////cout << "OK!" << el ; 
	int result = 0 ; 
	for (int u = 0 ; u < b ; u++){
		if (!bp[u]){
			continue ; 
		}
		vb seen(g,false) ; 
		////cout << "entre`" << el ; 
		if (bpm(u,bp,gp,seen,matchR,A,G)){
			result ++ ; 
			////cout << "Noexite`" << el ; 
		}

	}
	return result ; 

}



int main() {
	int t ; cin >> t ; 
	while (t--){ 
		cin >> b >> g >> l ; 
		vi m(min(b,g)+1,0) ; 
		vi bs , be , gs , ge ; bs.rsz(b) ; be.rsz(b) ; gs.rsz(g) ; ge.rsz(g) ; 
		
		vi v ; 
		//bool A[b][g] ;   
		
		bool **A = (bool**) malloc(sizeof(bool*)*(b)) ; 
		forn(i,b){
			A[i] = (bool*) malloc(sizeof(bool)*(g)) ; 
		}
		bool **G = (bool**) malloc(sizeof(bool*)*(g)) ; 
		forn(i,g){
			G[i] = (bool*) malloc(sizeof(bool)*(b)) ; 
		}
		//memset(A,false,sizeof(A)) ; 
		forn(i,b){
			forn(j,g){
				A[i][j] = false ;
				G[j][i] = false ;  
			}
		}
		////cout << "complete\n" ;
		int aa , bb , n; 
		forn(i,b) {
			cin >> aa >> bb >> n  ; 
			////cout << i << sp << bb << el ; 
			bs[i] = aa ; be[i] = bb ; int temp  ; 
			forn(j,n){
				cin >> temp ; 
				A[i][temp] = true ;  
			}
		} 
		////cout << "complete\n" ;  
		forn(i,g){
			cin >> aa >> bb >> n ; 
			gs[i] = aa ; ge[i] = bb ; int temp ; 
			////cout << aa<< sp << bb << sp << n << el ; 
			forn(j,n){
				cin >> temp ; 
				////cout << temp << el ; 
				G[i][temp] = true ;  
			}
		}

		int time = 0 ; 
		while (time < l){
			vb bp(b,false) ; vb gp(g,false) ; 
			update(bp,bs,be,time) ; 
			update(gp,gs,ge,time) ; 
			forn(i,b){
				//cout << bp[i] << sp ; 
			}
			//cout << el ; 
			forn(i,g){
				//cout << gp[i] << sp ;
			}
			//cout << el  ; 
			////cout << "Enter\n" << el ; 
			int mm = maxMatch(bp,gp,A,G) ; 
			//cout << mm << sp<< "hehe\n" << el ; 
			m[mm] += 1 ; 
			time += 1 ; 
		}

		//cout << "complete\n" ; 
		forn(i,m.size()){
			cout << m[i] << sp ; 
		}
		cout << el ;

	}
	return 0 ; 
}