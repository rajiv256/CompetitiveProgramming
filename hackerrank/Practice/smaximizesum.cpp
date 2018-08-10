#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>


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
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp " " 
#define el "\n"
#define ll long long int 
#define sci(x) scanf("%d",&x)

ll a[100005] ; 
ll msum[100005] ; 

int main(){
    int t ; cin >> t ; 
    while (t--){
        memset(a,0,sizeof(a)) ; 
        memset(msum,0,sizeof(msum)) ; 
        ll n , m ; cin >> n >> m ; 
        forn(i,n){
            cin >> a[i] ; 
        }
        forn(i,n){
            a[i] %= m ; 
        }
        forn(i,n){
            int j = i  ; 
            ll res = 0 ; 
            while ((res+j)%m > res){
                res = (res+j)%m ;
                j++ ;  
            }
            msum[i] = res ; 
        }
        sort(msum,msum+n) ; 
        cout << msum[n-1] << el ; 
        
    }
    
    return 0 ; 
}