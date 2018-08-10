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
#define MOD 1000000007
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
	int n , m ; sci(n) ; sci(m) ; int arr[n][m][3] ; 
	forn(i,n){
		forn(j,m){
			sci(arr[i][j][0]) ; 
		}
	}
 
	int q ; sci(q) ; 
	 
	while (q--){
		int a , b ; sci(a) ; sci(b) ; 
		
		forn(i,n){
			forn(j,m){
				arr[i][j][1] = 0 ; arr[i][j][2] = -1 ; 
				for(int k = 0 ; k < b ; k++){
					if (j+b-1<m){
						arr[i][j][1]+= arr[i][j+k][0] ; 
						arr[i][j][2] = max(arr[i][j][2],arr[i][j+k][0]) ; 
					}
				}
			}
		}
		int ans = INT_MAX ; 
		forn(i,n){
			forn(j,m){
				int sum = 0 ; int maxi = INT_MIN ; 
				if (arr[i][j][2]==-1){
					continue ; 
				}
				if (i+a-1<n){
					for(int l = 0 ; l < a ; l++){
						sum += arr[i+l][j][1] ; 
						maxi = max(maxi,arr[i+l][j][2]) ; 
					}
				}
				if (maxi != INT_MIN)
					ans = min(ans,a*b*maxi-sum) ; 
			}
		}
		cout << ans << el ; 
		
		
	}
	
	
}


























