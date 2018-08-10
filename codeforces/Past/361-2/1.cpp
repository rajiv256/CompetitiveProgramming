#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define pii pair<int,int>
#define INF 1000000000
#define sp " "
#define el "\n"
#define lld long long int
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define sci(x) scanf("%d",&x)
#define mp make_pair
#define ll long long

bool valid(int r , int c){
	if (r < 0 || c < 0 || r > 3 || c > 2){
		return false ; 
	}
	if (r==3){
		if (c!=1){
			return false ; 
		}
		return true ;  
	}
	return true ; 
}

bool check(vp steps, int r , int c){
	//cout << r << sp << c << " ### "<< el ;
	for (int i = 0 ; i < steps.size() ; i++){
		//cout << r << sp << c << " @@ " << el ; 
		if (!valid(r+steps[i].xx,c+steps[i].yy)){
			//cout <<r+steps[i].xx << sp << c+steps[i].yy << el ;
			return false ;
		}
		r += steps[i].xx ; c += steps[i].yy ; 
	}
	return true ; 
}

int main(){
	map<int,pair<int,int> > m ; 
	m[1] = mp(0,0) ; m[2] = mp(0,1) ; m[3] = mp(0,2) ; m[4] = mp(1,0) ; m[5] = mp(1,1) ; m[6] = mp(1,2) ; 
	m[7] = mp(2,0) ; m[8] = mp(2,1) ; m[9] = mp(2,2) ; m[0] = mp(3,1) ; 

	int n ; cin >> n ; 
	string s ; cin >> s ; 
	int a[n] ; 
	forn(i,n){
		a[i] = s[i]-'0' ; 
	}
	vp steps ;
	for(int i = 1; i < n ; i++){
		steps.pb(mp(m[a[i]].xx-m[a[i-1]].xx , m[a[i]].yy-m[a[i-1]].yy)) ; 
		//cout << steps[steps.size()-1].xx << sp << steps[steps.size()-1].yy << el ; 
	} 
	pii p = m[a[0]] ; 
	int fl = 0 ; 
	for(int i= 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			if (mp(i,j)==p){
				continue ; 
			}
			if (i == 3 && j!=1){
				continue ; 
			}
			if (check(steps,i,j )){
				//cout << i << sp << j << el ; 
				fl = 1 ; 
				break ; 
			}
		}
		if (fl == 1){
			break ; 
		}
	}
	if (fl==1){
		cout << "NO" << el ; 
		return 0 ; 
	}
	cout << "YES" << el ;
	return 0 ; 

}