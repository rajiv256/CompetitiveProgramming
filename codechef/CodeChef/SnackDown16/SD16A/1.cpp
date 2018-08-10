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
typedef unsigned long long ull ;

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
#define MXN 100003
#define MOD 1000000007
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
	int t ; sci(t) ; 
	while (t--){
		int n ; sci(n) ; int c[n+1] ; 
		int prev = -1 ; 
		int count = 0 ; int fl = 0 ; int x ;   
		forn(i,n){
			sci(x) ; 
			if (count >= 3){
				 fl = 1 ; 
			}
			if (prev != x){
				count = 1 ;
				prev = x ;
			}
			else{
				count += 1 ; 
			}
			if (count >= 3){
				 fl = 1 ; 
			}
			
		}
		
		if (fl){
			cout << "Yes" << el  ; 
		}
		else{
			cout << "No" << el ; 
		}
		
		
	}
	return 0 ; 
}




















