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
#define MXN 500009
#define gc getchar_unlocked
#define val(i) (orient[i]==1?a+b+1:a+1) 

int n, a, b, T , t= 0 ; 
int orient[MXN] ; 

int l[MXN] ; 
int r[MXN] ; 



int main(){
    sci(n) ; sci(a) ; sci(b) ; sci(T) ; 
    string s ; cin >> s ;
    memset(orient,0,sizeof(orient)) ; 
    forn(i,n){
        if (s[i] == 'w'){
            orient[i] = 1 ; 
        }
    } 
    int fp = 0 ; 
    int bp = n-1 ; 
    int ori = 0 ; 
    int remT = T ; 
    
    if (orient[0]==0){
        l[0] = 1  ; 
    }
    else{
        l[0] = b+1 ; 
    }
    for(int i = 1 ; i < n ; i++){
        l[i] = l[i-1]+val(i) ; 
    }
    if (orient[n-1]==0){
        r[0] = 1 ; 
    }
    else{
        r[0] = b+1 ; 
    }
    for(int i = n-2 ; i>= 0 ; i--){
        r[n-1-i] = r[n-2-i]+val(i) ; 
    }
    
    int ans = 0 ; 
    forn(i,n){
        cout << l[i] << sp ; 
    }
    cout << el ; 
    forn(i,n){
        cout << r[i] << sp ; 
    }
    
    cout << el ; 
    for(int i = 0 ; i < n ; i++){
        remT = T-l[i]-a ; 
        if (remT < 0){
            break ; 
        }
        if (remT < r[0]){
            ans = max(ans,i+1) ; 
        }
        int* it = upper_bound(r,r+n,remT) ;
        int extent = (int)(it-r)-1 ; 
        cout << i << sp << extent << el  ; 
        ans = max(ans,(min(n,i+extent+2))) ; 
         
    }
    cout << ans << el  ; 
    return 0 ; 
}