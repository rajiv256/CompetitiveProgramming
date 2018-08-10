// SPOJ prob
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
#define PI 3.141592653589793

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ;

typedef struct Point {
	int x , y , idx  ;
}Point;

Point pivot ;

double dist(Point a, Point b){
	int dx = b.x-a.x ;
	int dy = b.y-a.y ;
	return sqrt(dx*dx+dy*dy) ;
}
int orientation(Point a, Point b , Point c){
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x) ;
}

// Compare using polar angles
bool compare(Point const& p1, Point const& p2){
	int ori = orientation(pivot,p1,p2) ;
	if (ori==0){
		return (dist(pivot,p1)==dist(pivot,p2))?(p1.idx<p2.idx):dist(pivot,p1)<dist(pivot,p2);
	}
	return (ori > 0)?true:false  ;
}
bool issame(Point const& p1, Point const& p2){
	if (p1.x==p2.x && p1.y==p2.y){
		return true ;
	}
	return false ;

}

int convexHull(Point P[], Point C[], int n){

	int sz = 2 ;
	for(int i = 2 ; i < n ; i++){
		while (sz>=2 && orientation(C[sz-2],C[sz-1],P[i])<=0) sz-- ;
		C[sz] = P[i] ;
		sz++ ;
	}

	return sz ;
}



int main(){
	int t; sci(t) ;
	while (t--){
		int n ; sci(n) ;
		Point P[n] ;
		int x, y  ;
		for(int i = 0 ; i < n ; i++){
			sci(x) ; sci(y)  ;
			P[i].x = x ; P[i].y = y ; P[i].idx = i ;
		}
		pivot = P[0] ;      // choose pivot in the bottom-left corner.
		for(int i = 1 ; i < n ; i++){
			if (pivot.y > P[i].y || (pivot.y==P[i].y && pivot.x>P[i].x)){
				pivot = P[i] ;
			}
		}
		int pidx = pivot.idx ;
		Point temp = P[0] ;
		P[0] = pivot ;
		P[pidx] = temp ;

		sort(P+1,P+n,compare) ;
		if (n==1){
			printf("0.00\n");
			printf("%d\n\n",P[0].idx );
			continue ;
		}
		if (n==2){
			double di = dist(P[0],P[1]) ;
			printf("%.2f\n",2*di) ;
			printf("%d %d\n\n",P[0].idx,P[1].idx);
			continue ;
		}


		Point C[n];     // C is our convex hull.
		forn(i,0,n){
			C[i] = P[i] ;
		}
		//------- END OF PART 1 --------- //
		int SZ = convexHull(P,C,n);
		vector<Point> ans ;
		forn(i,0,SZ){
			ans.pb(C[i]) ;
		}
		unique(all(ans),issame) ;
		// END OF PART2 -------------- //
		SZ = ans.size() ;
		double d = 0.0 ;
		for(int i = 0 ; i < SZ ; i++){
			d += dist(ans[i],ans[(i+1)%SZ]) ;
		}
		printf("%.2f\n",d) ;
		for(int i = 0 ; i < SZ ; i++){
			printf("%d ",ans[i].idx+1 );
		}
		printf("\n\n");


	}

}
