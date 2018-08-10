/* 
        Code written by rajiv. 
        God speed!
*/
#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define sclf(x) scanf("%lf",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100005
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

int n , m , k ;  
 
char c[1002][1002] ; 

int dist[1002][1002] ; 
bool vis[1002][1002]; 

bool valid(int x, int y){
	if (x >=0 && y >=0 && x<n && y<m && c[x][y]=='.'){
		return true ; 
	}
	return false ; 
}

queue<pair<int,pair<int,int> > > q ; 

void bfs(int x1,int y1, int x2,int y2){
	q.push(mp(0,mp(x1,y1))) ; 
	while(!q.empty()){
		pair<int,pair<int,int> > p = q.front() ; 
		q.pop() ; 
		int wt = p.xx ; 
		int x = p.yy.xx ; 
		int y = p.yy.yy ; 

		dist[x][y] = min(wt,dist[x][y])  ; 
		
		if (x == x2 && y==y2){
			cout << wt << el ; 
			return ; 
		}
		vis[x][y] = true ; 
		for(int i= 1 ; valid(x+i,y)&& (i <=k)  ; i++){
			if (!vis[x+i][y]){
				if (x+i==x2 && y==y2){
					cout << wt+1 << el ; 
					return ; 
				}
				q.push(mp(wt+1,mp(x+i,y))) ; 
				vis[x+i][y] = true ; 
			}
		}
		for(int i= 1 ; valid(x-i,y) && (i <=k) ; i++){
			if (!vis[x-i][y]){
				if (x-i==x2 && y==y2){
					cout << wt+1 << el ; 
					return ; 
				}
				q.push(mp(wt+1,mp(x-i,y))) ; 
				vis[x-i][y] = true ; 
			}
		}
		for(int i = 1 ; (valid(x,y+i)) &&  (i <=k) ; i++){
			if (!vis[x][y+i]){
				if (x==x2 && y+i==y2){
					cout << wt+1 << el ; 
					return ; 
				}
				q.push(mp(wt+1,mp(x,y+i))) ; 
				vis[x][y+i] = true ; 
			}
		}
		for(int i = 1 ; valid(x,y-i) && (i <=k) ; i++){
			if (!vis[x][y-i]){
				if (x==x2 && y-i==y2){
					cout << wt+1 << el ; 
					return ; 
				}
				q.push(mp(wt+1,mp(x,y-i))) ; 
				vis[x][y-i] = true ; 
			}
		}
	}
	cout << "-1" << el ; 
	return ; 
}


int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false)  ; 

	cin >> n >> m >> k ; 
	
	int xx = 0 ; 
	forn(i,0,n){
		forn(j,0,m){
			cin >> c[i][j] ; 
		}
	}
	int x1 , y1 , x2 , y2 ; 
	cin >> x1 >> y1 >> x2 >> y2 ; 
	x1-- ; y1-- ; x2-- ; y2-- ; 

	
	forn(i,0,n){
		forn(j,0,m){
			dist[i][j] = INF ; 
		}
	}
	memset(vis,false,sizeof(vis)) ; 
	
	bfs(x1,y1,x2,y2) ; 
	// if (dist[x2][y2]>=INF){
	// 	cout << "-1" << el ; 
	// }
	// else{
	// 	cout << dist[x2][y2] << el ; 
	// }
	
	
	return 0 ; 
			
}
