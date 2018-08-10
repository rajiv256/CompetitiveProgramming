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

class point{
	public : 
	double x1,x2,x3,x4,x5 ; 

	point(double y1,double y2,double y3,double y4,double y5){
		x1 = y1  ;
		x2 = y2 ; x3 = y3 ; x4 = y4 ; x5 = y5 ; 
	}
	point(){

	}
	void print(){
		cout << x1 << sp << x2 << sp << x3 << sp << x4 << sp << x5 << el ; 
	}
}; 
point operator-(point const& p2, point const& p1){
		point p ; 
		p.x1 = p2.x1-p1.x1 ; 
		p.x2 = p2.x2-p1.x2 ; 
		p.x3 = p2.x3-p1.x3 ; 
		p.x4 = p2.x4-p1.x4 ; 
		p.x5 = p2.x5-p1.x5 ;  
		return p ; 
	}
bool operator<(point const& p1,point const& p2) {
		return (p1.x1<p2.x1)?true:(p1.x1>p2.x1)?false:(p1.x2<p2.x2)?true:(p1.x2>p2.x2)?false:(p1.x3<p2.x3)?true:(p1.x3>p2.x3)?false:(p1.x4<p2.x4)?true:(p1.x4>p2.x4)?false:(p1.x5<=p2.x5)?true:false ;   
}
double dotprod(point const& p1, point const& p2){
	double ret = 0.0 ; 
	ret += p1.x1*p2.x1 + p1.x2*p2.x2 + p1.x3*p2.x3 + p1.x4*p2.x4 + p1.x5*p2.x5 ; 
	return ret ; 
}
double mag(point const& p1){
	double ret = 0.0 ; 
	ret += p1.x1*p1.x1 + p1.x2*p1.x2 + p1.x3*p1.x3 + p1.x4*p1.x4 + p1.x5*p1.x5 ;
	return sqrt(ret) ;  
}
vector<point> v ; 
double solve(int p, int i, int j){
	point ab = v[i]-v[p] ; 
	point ac = v[j]-v[p] ; 
	double dot = dotprod(ab,ac); 
	double magg = mag(ab)*mag(ac) ; 
	double val = dot/magg ; 
	return val ; 
}
int main(){
	int n ; cin >>n ; 
	double x1, x2 , x3 ,x4 , x5 ; 
 
	
	for(int i = 1 ; i <= n ; i++){
		cin >> x1 >> x2 >> x3 >> x4 >> x5 ; 
		point p = point(x1,x2,x3,x4,x5) ; 
		v.pb(p) ;   
	}
	
	if (n > 20){
		cout << "0" << el ; 
		return 0 ; 
	}
	vi ans ; 
	for(int i = 0; i < n ; i++){
		int fl = 1 ; 
		for(int j = 0 ; j < n ;j++){
			for(int k = 0 ; k < n ; k++){
				if (i == j || j==k || k==i){
					continue ; 
				}
				double val = solve(i,j,k) ; 
				if (val >0){
					fl = 0; 
					break ; 
				}
			}
		}
		if (fl){
			ans.pb(i+1) ; 
		}
	}
	cout << ans.size() << el ; 
	forn(i,0,ans.size()){
		cout << ans[i] << sp ; 
	}
	if (ans.size()!=0)
	cout << el ; 

}


























