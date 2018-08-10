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
typedef pair<int,int> pii ; 

int main(){
	ios_base::sync_with_stdio(false)  ; 
	cin.tie(0) ; 
	cout.tie(0) ; 
	
	int n ; cin >> n ; 
	string s ; cin >> s ; 
	int a = 0 , b = 0 ; 
	for(int i = 0 ; i < s.size()-1 ; i++){
		if (s[i]!=s[i+1]){
			if (s[i]=='S'){
				a++ ;  //Seattle to Fransisco
			}
			if (s[i]=='F'){
				b++ ; 
			}
		}
	}
	if (a > b){
		cout << "YES" << el ; 
	}
	else{
		cout << "NO" << el ;  
	}
	
}
