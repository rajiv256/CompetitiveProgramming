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
#define sci(x) scanf("%d",&x)
#define MXN 100003

int main(){
	int n ; cin >> n ; 
	int a[n] ; 
	forn(i,n){
		cin >> a[i] ; 
	}
	sort(a,a+n) ; 
	int curr = 1 ; 
	forn(i,n){
		if (a[i] == curr){
			curr++ ; 
			continue ; 
		}
		if(a[i] < curr){
			continue ; 
		}
		else{
			a[i] = curr ; 
			curr++ ; 
			continue ; 
		}
	}
	cout << curr << el ; 
}
