#include <bits/stdc++.h>

using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100003
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<int,int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define YES "YES\n"
#define NO "NO\n"


typedef vector<pair<double,double> > vpdd ; 
typedef pair<double,double> pdd ; 

double sl(pdd p1, pdd p2){
	return (p2.yy-p1.yy)/(p2.xx-p1.xx) ; 
}


bool collinear(pdd p1, pdd p2 , pdd p3){    //check if we have to pass by ref

	return (sl(p1,p2)==sl(p2,p3))?true:false ; 
}

double slope(vpdd& points){


	for(int i = 0 ; i < points.size() ; i++){
		for(int j = i+1 ; j < points.size() ; j++){
			for(int k = j+1 ; k < points.size() ; k++){
				if (collinear(points[i],points[j],points[k])){
					return sl(points[i],points[j]) ; 
				}
			}
		}
	}
	return -INF; 

}



int main(){
	int n ; cin >> n ; 
	vpdd points ; 
	double x , y ; 
	for(int i = 0 ; i < n ; i++){
		cin >>  y ; 
		points.pb(mp(i+1,y)) ; 
	}

	if (n == 3){
		if (!collinear(points[0],points[1],points[2])){
			cout << "Yes\n" ; 
		}
		else{
			cout << "No\n" ; 
		}
		return 0 ; 
	}

	if (n == 4){
		map<double,double> m ; 
		for(int i = 0 ; i < points.size(); i++){
			for(int j = i+1 ; j < points.size() ; j++){
				m[sl(points[i],points[j])]++ ; 
			}
		}
		for(map<double,double> :: iterator it = m.begin() ; it != m.end() ; it++){
			if ((*it).yy == 2){
				cout << "Yes\n" ; 
				return 0 ; 
			}
		}
	}



	double slp = slope(points) ; 
	if (slp == -INF){
		cout << "No\n" ; return 0 ; 
	}
	set<double> intercepts ; 
	for(int i = 0 ; i < points.size() ; i++){
		intercepts.insert(points[i].yy - points[i].xx*slp) ; 
	}
	if (intercepts.size() != 2){
		cout << "No\n" ; 
	}
	else {
		cout << "Yes\n" ; 
	}
	return 0 ; 





}












































