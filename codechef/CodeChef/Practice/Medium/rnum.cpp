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
	int t ; sci(t) ; 
	while (t--){
		int n ; sci(n) ; int a[n+1] ; 
		forn(i,n){
			sci(a[i]) ; 
		}
		a[n] = 10000000 ; 
		sort(a,a+n) ; 
		int size = 0 ; 
		int st = 0 ; 
		int amin = 0 , amax = 0 ; 
		while (st < n){
			if (a[st]+1 == a[st+1]){
				size += 1 ; 
				st += 1 ; 
				continue ; 
			}
			else{
				st++ ; 
				size += 1 ; 
				amin += size/3 ; 
				amax += size/2 ; 
				if(size%3!=0){
					amin += 1; 
				}
				if(size%2!=0){
					amax += 1 ; 
				}
				size = 0 ; 
			}
		}
		cout << amin << sp << amax << el ; 
		
	}
	return 0 ; 
}






















