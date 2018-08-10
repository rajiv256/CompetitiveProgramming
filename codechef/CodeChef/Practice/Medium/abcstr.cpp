
#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned int ull ;

#define forn(i,n) for(int i = 0; i < n ; i++)
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el endl
#define ll long long
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
//#define sci(x) scanf("%d",&x)
#define MXN 100003
#define gc getchar_unlocked	

void sci(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}



int main(){
	string s ; cin >> s ;	 
	int n = s.size() ; 
	
	ull a[n+1][3] ; 
	memset(a,0,sizeof(a)) ; 
	
	for(int i = 1 ; i <= n ; i++){
		a[i][0] = a[i-1][0] ; 
		a[i][1] = a[i-1][1] ; 
		a[i][2] = a[i-1][2] ; 
		a[i][s[i-1]-'A'] += 1 ; 
	}
	ull ans = 0 ; ull na , nb , nc ; 
	for(int i = 1 ; i <= n ; i++){
		for(int j = i+1 ; j <= n ; j++){
			na = a[j][0]-a[i-1][0] ; nb = a[j][1]-a[i-1][1] ; nc = a[j][2]-a[i-1][2] ; 
			if ((na==nb) && (nb==nc)){
				ans += 1 ; 
			}
		}
	}
	printf("%u\n",ans) ;   
	return 0 ; 



}