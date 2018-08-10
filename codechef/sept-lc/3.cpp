
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
typedef vector<vector<int> > vvi ;
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

map<int,int> count_map(string s){
	map<int,int> m ; 
	for(int i = 0 ; i < s.size() ; i++){
		int x = s[i]-'0' ; 
		m[x]++ ; 
	}
	return m ; 
}
map<int,int> cc(int num){
	map<int,int> m ; 
	m[num%10]++ ; 
	m[num/10]++ ; 
	return m ; 
}

int main(){
	int t ; cin >>t  ; 
	while (t--){
		string s ; cin >> s ; 

		map<int,int> cmap =  count_map(s) ;
		s = "" ; 
		for(int i = 65 ; i <= 90 ; i++){
			map<int,int> charmap = cc(i) ; 
			int fl = 1 ;  
			for(mii::iterator it = charmap.begin() ; it != charmap.end() ; it++){
				if ((*it).yy > cmap[(*it).xx]){
					fl = 0 ; 
				}
			}
			if (fl) s += ((char)i) ; 
		} 
		cout << s << el; 
		
	}
	return 0 ; 


}








































