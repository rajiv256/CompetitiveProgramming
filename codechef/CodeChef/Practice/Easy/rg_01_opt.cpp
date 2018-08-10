#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>

	
using namespace std; 

typedef vector<int> vi ; 
#define vvi vector<vector<int> > 
typedef map<int,int> mii ; 
#define forn(i,n) for(int i=0;i<n;i++)
#define INF 1000000000 

struct edge{
	int u ; 
	int v ; 
	int w ; 
	
}; 

bool mcomp(const edge& a , const edge& b){
	return a.w > b.w ; 
}

void getSpanningTree(vvi& msp , vector<edge>& ed , mii& comp , vvi& wt, vvi& nwts, int n){
	set<int> s ; int ecnt = 0 ; 
	while (s.size() < n){
		int p = ed[ecnt].u ; int q = ed[ecnt].v ; int w = ed[ecnt].w ; 
		//cout << p << " out " << q << endl ; 
		//cout << comp[p] << " map-view " << comp[q] << endl  ; 
		if (comp[p] != comp[q]){
			//	cout << p << " in " << q << endl ; 
			s.insert(p) ; s.insert(q) ; 
			nwts[p][p] = INF ; 
			nwts[q][q] = INF ; 
			nwts[p][q] = w ; 
			nwts[q][p] = w ; 
			msp[p].push_back(q) ; 
			msp[q].push_back(p) ; 
			for (map<int,int> :: iterator it = comp.begin() ; it != comp.end() ; it++){
				if ((*it).second == q+1){
					comp[(*it).first] = p+1 ; 
				}
			}		
		}
		ecnt++ ; 
		
	}
	return ; 
}

void dfs (int src ,vvi& msp,vvi& nwts , vi& minWt , vector<pair<int,int> >& Q , vector<bool>& vis){
	Q.push_back(make_pair(src,minWt[0]))  ;
	vis[src] = true ; 
	//cout << src << endl ; 
	forn(i,msp[src].size()){
		if (!vis[msp[src][i]]){
			if (minWt[0] > nwts[src][msp[src][i]]){
				minWt[0] = nwts[src][msp[src][i]] ;
				Q[msp[src][i]].second = minWt[0] ; 
			}
			dfs(msp[src][i],msp,nwts,minWt,Q,vis) ; 
		}
	}

}



int main() {
	int n , e ; cin >> n >> e ; 
	vi v; 
	vvi wt(n,vi(n,0)) ; 
	mii comp ; 
	forn(i,n){
		comp[i] = i+1 ; 
	} 
	edge ee ;
	vector<edge> ed ; 
	while (e--){
		int a , b , ww ; 
		cin >> a >> b >> ww ; 
		ee.u = a ; ee.v = b ; ee.w = ww ; 
		ed.push_back(ee) ; 
		wt[a][b] = ww ; 
		wt[b][a] = ww ; 
	}

	sort(ed.begin(),ed.end(),mcomp);
	forn(i,ed.size()){
		cout << ed[i].w  ; 
 	}
 	cout << endl ; 
	vvi msp(n,v) ; vvi nwts(n,vi(n,0)) ; 
	getSpanningTree(msp,ed,comp,wt,nwts,n);

	vvi res(n,vi(n,0)) ; 
	forn(i,n){
		vi minWt ; minWt.resize(1) ;minWt[0] = INF ;  
		vector<pair<int,int> > Q(n,make_pair(0,0)) ; 
		forn(j,n){
			Q[j].first = j ; 
			Q[j].second = 0 ; 
		}
		vector<bool> vis(n,false) ; 
		dfs(i,msp,nwts,minWt,Q,vis) ; 
		res[i][i] = 0 ; 
		forn(j,Q.size()){
		
			res[i][Q[j].first] = Q[j].second ; 
			res[Q[j].first][i] = Q[j].second ;	

			 
		}
		res[i][i] = 0 ; 
	}
	forn(i,n){
		forn(j,n){
			cout << res[i][j] << " " ; 
		}
		cout << endl ; 
	}
	return 0 ; 

}
