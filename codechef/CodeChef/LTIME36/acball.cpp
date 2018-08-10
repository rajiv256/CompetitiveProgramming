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

int main(){
	int t ; sci(t) ; 
	while (t--){
		string s1 ; string s2 ; cin >> s1 >> s2 ; 
		string s = "" ; 
		for (int i = 0 ; i < s1.size() ; i++){
			if (s1[i]==s2[i]){
				if (s1[i]=='W')
					 s+='B'  ;
				else 
					s+= 'W' ; 
			}
			else 
				s+='B' ; 
		}
		cout << s <<el ;  
	}
}