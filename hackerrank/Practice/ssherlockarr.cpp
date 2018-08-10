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

int a[100003] ; 
int pref[100003] ; 
int main(){
    int t ; sci(t) ; 
    while (t--){
        memset(a,0,sizeof(a)) ; 
        int n ; sci(n) ; 
        forn(i,n){
            sci(a[i]) ; 
        }    
        memset(pref,0,sizeof(a)) ;
        pref[0] = a[0] ; 
        for (int i = 1 ; i < n ; i++){
            pref[i] = pref[i-1] + a[i] ; 
        }
        int fl = 0 ; 
        forn(i,n){
            int left , right ;
            if (i == 0)){
                left = 0 ; 
                right = pref[n-1]-pref[0]  ; 
            } 
            else if (i == n-1){
                left = pref[n-2] ; 
                right = 0 ; 
            }
            else {
                left = pref[i-1] ; 
                right = pref[n-1]-pref[i] ; 
            }
            if (left == right){
                cout << "YES" << el ;
                fl = 1 ; 
                break ;  
            }
        }
        if (fl == 1){
            continue  ; 
        }
        cout << "NO" << el ; 
    }
    return 0 ; 
}