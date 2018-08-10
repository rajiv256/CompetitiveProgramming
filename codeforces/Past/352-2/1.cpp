#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mi ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pi pair<int,int>
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el "\n"
#define ll long long
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x)
#define MXN 100003
#define gc getchar_unlocked
int a[1001] ; 

int main(){
	int od = 9 ; 
	int td = 180 ; 
	int thd = 2700 ; 
	
	int n ; sci(n); 
	if (n <= 9){
		cout << n << el ;
		return 0 ; 
	}
	n -= 9 ; 
	int x = 9 ; 
	if (n <= 180){
		x += n/2 ; 
		if (n%2==0){
			cout << x%10 << el ; 
			return 0 ; 
		}
		x += 1 ; 
		x/= 10 ; 
		cout << x%10 << el ;
		return 0 ; 
	}
	n -= 180 ;
	x = 99 ; 
	
	x += n/3 ; 
	//cout << x << el ;
	if (n%3 == 0){
		cout << x%10 << el ; return 0 ; 
	}
	x += 1 ; 
	if (n%3 == 2){
		x /= 10 ; cout << x%10 << el ; return 0 ; 
	}
	if (n%3 == 1){
		x /= 100 ; cout << x%10 << el ; return 0 ; 
	}
	return 0 ; 
}
