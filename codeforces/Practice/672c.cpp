#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mi ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pi pair<int,int>
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el "\n"
#define ll long long
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x)
#define MXN 1000003
#define gc getchar_unlocked

double dist(double x1 , double y1 , double x2 , double y2){
	cout << sqrt(double(3.0)) << el ; 
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) ;
}


int main(){
	std::ios_base::sync_with_stdio(0) ;

	cin.tie(0) ;
	int ax,ay,bx,by,rx,ry ;
	cin >> ax >> ay >> bx >> by >> rx >> ry ;
	int n ; cin >> n ;
	pair<double,double> a[n] ;
	forn(i,n){
		cin >> a[i].xx >> a[i].yy ;
	}
	pair<double,int> da[n] ; pair<double,int> db[n] ; pair<double,int> r[n] ;
	forn(i,n){
		da[i] = mp(dist(ax,ay,a[i].xx,a[i].yy),i);
	}
	forn(i,n){
		db[i] = mp(dist(bx,by,a[i].xx,a[i].yy),i);
	}
	forn(i,n){
		r[i] = mp(dist(rx,ry,a[i].xx,a[i].yy),i);
	}
	sort(da,da+n) ; sort(db,db+n); sort(r,r+n); 
	double dist = 0 ; 
	forn(i,n){
		dist += 2*r[i].xx;
	}
	if (da[0].yy != db[0].yy){
		dist -= r[da[0].yy].xx ; 
		dist -= r[db[0].yy].xx ; 
		dist += da[0].xx ; 
		dist += db[0].yy ; 
	}
	else{
		if (da[0].xx+db[1].xx > da[1].xx+db[0].xx){
			dist -= r[da[1].yy].xx ; dist -= r[db[0].yy].xx ; 
			dist += da[1].xx+db[0].xx ; 
		}
		else if (da[0].xx+db[1].xx < da[1].xx+db[0].xx){
			dist -= r[db[0].yy].xx ; dist -= r[da[1].yy].xx ; 
			dist += da[0].xx+db[1].xx ; 
		}
		else{
			dist -= max(r[db[0].yy].xx+r[da[1].yy].xx,r[da[1].yy].xx+r[db[0].yy].xx ) ; 
			dist += da[0].xx+db[1].xx ; 
		}
	}
	printf("%.7f\n",dist) ; 
	return 0 ; 
}


















