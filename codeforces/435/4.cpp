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

string s ;
string ori ; 

int ham(){
	int ret = 0 ; 
	
	forn(i,0,s.size()){
		if (s[i]!=ori[i]){
			ret++ ; 
		}
	}


	//cin >> ret ; 
	return ret ; 
} 

void invert(int l, int h){
	forn(i,l,h+1){
		if (s[i]=='0') s[i] = '1' ; 
		else{
			s[i] = '0' ; 
		}
	}
}
void query() {
	cout << "? " << s << el ; 
	cout.flush() ; 
	return ; 
}
void bsearch(int l , int h , int prev){
	if (l == h){
		cout << "! " << l << sp << l+1 << el ;
		cout.flush(); 
		return ; 
	}
	int m = (l+h)>>1 ; 
	invert(l,m) ;
	query() ; 
	int hd1 = ham(); //cin >> hd1 ; 
	if (abs(prev-hd1) == m-l+1){
		invert(l,m) ; 
		invert(m+1,h) ; 
		query() ; 
		int hd2 = ham() ; //cin >> hd2 ; 
		if (abs(prev-hd2) == h-m){
			int fi = m+1 ; int se = m+2 ; 
			invert(m+1,h); 
			query() ; 
			int hd3 = ham() ;
			if (hd3 < hd2){
				if (s[m+1]=='0'){
					int temp = fi ; fi = se ; se = temp ; 
				}
			}
			else{
				if (s[m+1]=='1'){
					int temp = fi ; fi = se ; se = temp ; 
				}
			}
			cout << "! " << fi << sp << se << el; 
			cout.flush() ; 
			return ; 
		}
		else{
			bsearch(m+1,h,hd2) ; 
			return ; 
		}
	}
	else{
		bsearch(l,m,hd1) ; 
		return ; 
	}
}

int main(){
	cin >> ori ; 
	int n = ori.size() ; 
	
	//int n ; cin >> n ; 
	
	forn(i,0,n) s += '0' ; 
	query() ; 
	int HD = ham(); //cin >> HD ; 
	bsearch(0,n-1,HD) ; 
}
