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
#define INF 1000000003
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

bool collinear(vp& v){
	double a1 = v[1].xx-v[0].xx ; 
	double b1 = v[1].yy-v[0].yy ; 
	double a2 = v[2].xx-v[0].xx ; 
	double b2 = v[2].yy-v[0].yy ;

	return (a1*b2 == a2*b1) ; 
}

double slope(pair<int,int>& p1, pair<int,int>& p2){
	if (p2.xx==p1.xx){
		return INF ; 
	}
	else return ((double)(p2.yy-p1.yy))/(p2.xx-p1.yy) ; 
}
pair<int,int> midp(pair<int,int>& p1, pair<int,int>& p2){
	return mp((p1.xx+p2.xx)/2.0, (p1.yy+p2.yy)/2.0) ; 
}
ll dist(pair<int,int>& p1, pair<int,int>& p2){
	ll ret = (((ll)p2.xx-p1.xx)*((ll)p2.xx-p1.xx))+(((ll)p2.yy-p1.yy)*((ll)p2.yy-p1.yy)) ;
	return ret ;  
}


int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 

	pair<int,int> p0, p1, p2 ; 
	cin >> p0.xx >> p0.yy >> p1.xx >> p1.yy >> p2.xx >> p2.yy ;
	vp v ; v.pb(p0) ; v.pb(p1) ; v.pb(p2) ; 
	//sort(all(v)) ; 

	if (!collinear(v)){
		// double sl1 = slope(v[2],v[0]) ; 
		// double sl2 = slope(v[1],v[0]) ; 
		// sl1 = -1.0/sl1 ; 
		// sl2 = -1.0/sl2 ; 
		// pair<double,double> mp1 = midp(v[2],v[0]) ; 
		// pair<double,double> mp2 = midp(v[1],v[0]) ; 
		// double A1 = -sl1 ; 
		// double A2 = -sl2 ; 
		// double B1 = 1 ; 
		// double B2 = 1 ; 
		// double C1 = mp1.yy - sl1*mp1.xx ; 
		// double C2 = mp2.yy - sl2*mp2.xx ;
		// double det = A1*B2-A2*B1 ; 
		// double x = (B2*C1 - B1*C2)/det ; 
		// double y = (A1*C2-A2*C1)/det ; 
		ll d1 = dist(p0,p1) ; 
		ll d2 = dist(p1,p2) ; 
		ll d3 = dist(p2,p0) ; 
		if (d1==d2){
			cout << "Yes" << el ; 
		}
		else{
			cout << "No" << el ; 
		}

	} 
	else{
		cout << "No" << el ; 
	}












}










