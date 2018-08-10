#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<pair<int,int> > > vvp  ;
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
#define MXN 100005
#define MOD 1000000007
#define ll long long

int a[3*MXN] ;
int a0[3*MXN] ; 
int a1[3*MXN] ; 

int main(){
    int n , k ; sci(n) ; sci(k) ; 
    forn(i,n){
        sci(a[i]) ; 
    }
    memset(a0,0,sizeof(a0)) ; 
    memset(a1,0,sizeof(a1)) ; 
    if (a[0] == 0){
        a0[0] =1 ; 
        a1[0] = 0  ; 
    }    
    else{
        a1[0] = 1 ; 
        a0[0] = 0 ; 
    }
    for(int i = 1 ; i < n ; i++){
        if (a[i] == 1){
            a1[i] = a1[i-1]+1 ;
            a0[i] = a0[i-1] ;  
        }
        else{
            a0[i] = a0[i-1]+ 1;
            a1[i] = a1[i-1] ;  
        }
    }
    if (k == 0){
        int res = 0 ; int x = 0 ;
        forn(i,n){
            if (a[i] == 0){
                res = max(res,x)  ; 
                x = 0 ; 
            }
            if (a[i] == 1){
                x++ ; 
            }
        }
        if (x != 0){
            res = x ; 
        }
        cout << res << el ; 
        forn(i,n){
            cout << a[i] << sp ; 
        }
        cout << el; 
        return 0 ; 
    }
    int ans = INT_MIN ; int resTo = 0 ; int resFr = 0 ;  
    for(int i = 0 ; i < n ; i++){
        int rz = 0 ; 
        if (i > 0){
            rz += a0[i-1] ;


        }
        int idx = lower_bound(a0,a0+n,k+rz)-a0  ;
       
        idx = min(n-1,idx) ;
        idx++ ; 
        while(idx < n){
            if (a[idx]==1)
                idx++ ; 
            else
                break ; 
        }
        idx-- ; 
        
        if (ans < idx-i+1){
            ans = idx-i+1 ; 
            resTo = i ;
            resFr = idx ; 
        }
    }
    cout << ans << el ; 
    for(int i = resTo ; i <= resFr ; i++){
        a[i] = 1 ; 
    }
    forn(i,n){
        cout << a[i] << sp ; 
    }
    cout << el ; 
    return 0  ;
    
}