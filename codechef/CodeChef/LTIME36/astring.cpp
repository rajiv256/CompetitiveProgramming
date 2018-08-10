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



char* s ;

int main(){
	int t ; sci(t) ; 
	s = (char*)malloc(sizeof(char)*100003) ;
	while (t--){
		scanf("%s",s) ; int k ; sci(k) ;  
		
		int n = strlen(s) ;
		string ans = "" ; 
		int ceI = n-k ; 
		int csI = 0 ; 
		for(int i = 0 ; i < k ; i++){
			char c = s[csI] ; int mini = csI ; 
			//cout << csI << sp << ceI << el ; 
			for(int j = csI ; j <= ceI ; j++){
				if (s[j] < c){
					c = s[j] ; 
					mini = j ; 
				}
			}
			ans += c ; 
			csI = mini+1 ; 
			ceI = ceI +1 ;
		}
		cout << ans << el ; 
	}
} 
































