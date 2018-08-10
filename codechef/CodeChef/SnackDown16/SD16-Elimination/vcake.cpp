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
#define scll(x) scanf("%lld",&x)
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

bool onetwo(ll m,ll k,ll j, ll r , ll c){
	if (m%r==0){
		ll x = m/r ;
		c = c-x ; 
		if (j%r==0 || k%r ==0){
			return true ; 
		}
		if (j%c==0 || k%c==0){
			return true ;
		}
	}
	return false ; 
}


int main(){
	int t ; sci(t) ; 
	while (t--){
		ll r , c , m , k , j ; scll(r) ; scll(c); scll(m) ; scll(k) ;scll(j) ;  
		
		if (m+k+j != r*c){
			cout << "No\n" ; 
			continue ; 
		}
		bool b = false ; 
		b |= onetwo(m,k,j,r,c) ;
		b |= onetwo(k,m,j,r,c) ;
		b |= onetwo(j,k,m,r,c) ;
		b |= onetwo(m,k,j,c,r) ;
		b |= onetwo(k,m,j,c,r) ;
		b |= onetwo(j,k,m,c,r) ;
		
		if (b){
			cout << "Yes" << el ;  
		}
		else{
			cout << "No" << el ; 
		}
		
	}
}





