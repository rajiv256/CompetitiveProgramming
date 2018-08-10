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



enum {IN = 0 , OUT = 1 } ; 



int nboys , ngirls , L ; 

struct Event{
	int t, id ,sex, io ; 
	Event(){} 
	Event(int T, int ID , int IO , int S) : t(T), id(ID), io(IO) , sex(S) {}
	bool operator< (const Event& e) const {
		if (t != e.t) return (t < e.t) ; 
		return (io < e.io) ;
	}
} ; 


bool bpm(int u , vb& bp ,vb& gp, int *matchR,vb& seen, bool **A , bool **G){
	for (int v = 0 ; v < ngirls ; v++){
		//cout << "safe\n" ;
		if (bp[u] && gp[v] && A[u][v] && G[v][u] && !seen[v]){
			seen[v] = true ; 
			if (matchR[v] < 0 || bpm(matchR[v],bp,gp,matchR,seen,A,G)){
				//cout << "Out\n" ; 
				matchR[v] = u ; 
				return true ; 
			}
		}
	}
	return false ; 
}


int maxMatching(vb& bp, vb& gp , bool **A , bool **G){
	int result = 0 ; 
	int* matchR = (int*)malloc(sizeof(int)*ngirls);  
	forn(i,ngirls){
		matchR[i] = -1 ; 
	}
	for (int u = 0 ; u < nboys ; u++){
		vb seen(ngirls,false) ; 
		if (bpm(u,bp,gp,matchR,seen,A,G)){
			result ++ ; 
		}
	}
	return result ; 
}

int main() {
	int T ; scanf("%d",&T)  ; 
	while (T--){
		scanf("%d%d%d",&nboys,&ngirls,&L) ; 
		
		bool **A = (bool**)malloc(sizeof(bool*)*nboys) ; 
		forn(i,nboys){
			A[i] = (bool*) malloc(sizeof(bool)*ngirls) ; 
		}
		//memset(A,0,sizeof(A)) ; 

		bool **G = (bool**) malloc(sizeof(bool*)*ngirls) ; 
		forn(i,ngirls){
			G[i] = (bool*)malloc(sizeof(bool)*nboys) ; 
		}
		//memset(G,0,sizeof(G)) ; 
		forn(i,nboys){
			forn(j,ngirls){
				A[i][j] = false ; 
				G[j][i] = false ; 
			}
		}
		vector<Event> events ; 
		int t ,sex = 1 ; int n ;  
		forn(i,nboys){
			scanf("%d",&t) ; 
			events.pb(Event(t,i,0,sex)) ; 
			scanf("%d",&t) ; 
			events.pb(Event(t,i,1,sex)) ; 
			scanf("%d",&n) ; 
			int temp ; 
			forn(j,n){
				cin >> temp ; 
				//cout << "temp: " << temp <<  el ; 
				A[i][temp] = true ; 
			}
		}		
		sex = 0 ; 
		forn(j,ngirls){
			scanf("%d",&t) ; 
			events.pb(Event(t,j,0,sex)) ; 
			scanf("%d",&t) ; 
			events.pb(Event(t,j,1,sex)) ;
			scanf("%d",&n) ; 
			int temp ;
			forn(i,n){
				cin >> temp ;
				G[j][temp] = true ; 
			}
		}
		sort(events.begin() , events.end()) ; 
		vb bp(nboys,false) ; vb gp(ngirls,false) ; 
		int tpre = 0 	; int nmatch = 0 ; 
		
		vi ans(min(nboys,ngirls)+1 , 0) ; 
		//cout << "b4\n" ;
		forn(i, events.size()){
			//cout << i << "Huh?" << el  ;
			Event e = events[i] ; 

			int t = e.t , id = e.id , sex = e.sex , io = e.io ; 
			if (io == IN){
				if (sex == 1){
					bp[id] = true ; 
				}
				else{
					gp[id] = true ; 
				}
			}

			if (io == OUT){
				if (sex == 1){
					bp[id] = false ; 
				}
				else {
					gp[id] =  false ;
				}
			}

			ans[nmatch] += t - tpre ; 
			tpre = t ; 
			nmatch = maxMatching(bp,gp,A,G) ; 

		}

		ans[nmatch] += L-tpre ; 

		forn(i,ans.size()){
			cout << ans[i] << sp ;
		}
		cout << el ; 

	}
	return 0 ; 
}

