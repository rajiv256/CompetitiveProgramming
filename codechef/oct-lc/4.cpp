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
#define hashp 999983 

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

string rep(char c, int x){
	string ret = "" ; 
	forn(i,0,x){
		ret += c ; 
	}
	return ret ; 
}
int starcnt(string s){
	int cnt = 0 ; 
	forn(i,0,s.size()){
		cnt += (s[i]=='*')?1:0 ; 
	}
	return cnt ; 
}
string pad(char c, int nas, int x){
	string padding = "" ; 
	int rem = nas ; 
	while (rem != 0){
		padding += rep(c,min(x,rem)) ; 
		rem -= min(x,rem) ;
		if (rem != 0){
			padding += "*" ; 
		} 
	}
	//cout << "pad : " << padding << el ; 
	return padding ; 
}

string solve(char a , char b , int x, int y, int as, int bs){
	
	// starts with a 
	string ans1 = "" ; 
	int nas = as ; 
	int nbs = bs ; 
	int sz = 0 ; 
	
	while (sz < x && nas>=nbs){
		nas -= nbs ; 
		sz++ ; 
	}
	 
	if (sz == x){
		forn(i,0,nbs){
			ans1 += rep(a,sz) ; 
			ans1 += b; 
		}
		
		ans1 += pad(a,nas,x) ; 
		
	}
	else if (nas<nbs){
		forn(i,0,nas){
			ans1 += rep(a,sz+1) ; 
			ans1 += b ; 
		}
		forn(i,nas,nbs){
			ans1 += rep(b,sz) ; 
			ans1 += a ; 
		}
	}
	

	// starts with b
	string ans2 = "" ; 
	nas = as ; 
	nbs = bs ; 
	sz = 0 ; 
	while (sz < x && nas>=nbs){
		nas -= nbs ; 
		sz++ ; 
	}
	
	if (sz == x){
		forn(i,0,nbs){
			ans2 += b; 
			ans2 += rep(a,sz) ; 
		}
		ans2 = pad(a,nas,x)+ans2 ; // may need to reverse here.  
	}
	else if (nas < nbs){
		forn(i,0,nas){
			ans2 += b ;
			ans2 += rep(a,sz+1) ; 
		}
		forn(i,nas,nbs){
			ans2 += b ;
			ans2 += rep(a,sz) ; 
		}
	}
	
	string ans = (starcnt(ans1) < starcnt(ans2))?ans1:ans2 ; 
	return ans ; 
}




int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(0) ; 

	int t; cin >> t ; 
	while (t--){
		string s ; cin >> s ; 
		int x , y ; cin >> x >> y ; 
		int nas = 0 ; int nbs = 0 ; 
		for(int i = 0 ; i < s.size() ; i++){
			if (s[i]=='a') nas++ ; 
			else nbs++ ; 
		}
		string ans = "" ; 
		if (nas == 0){
			ans = pad('b',nbs,y) ; 
		}
		else if (nbs == 0){
			ans = pad('a',nas,x) ; 
		}
		else if (nas < nbs){
			ans = solve('b','a',y,x,nbs,nas) ; 
		}
		else {
			ans = solve('a','b',x,y,nas,nbs) ; 
		}
		cout << ans << el ; 
	} 
}