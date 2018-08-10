// This code is wrong. Not handled the case where 
// there are more than one LIS. 

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
#define MXN 1000003
#define gc getchar_unlocked

ll a[400007] ; 
ll parent[400007] ; 
ll LIS[400007] ; 

void lis(int n){
    LIS[0] = 1 ; 
    parent[0] = 0 ; 
    forn(i,n){
        forn(j,i){
            if (a[j] < a[i]){
                if (LIS[i] < LIS[j]+1){
                    LIS[i] = LIS[j]+1 ; 
                    parent[i] = j ; 
                }
            }
        }
    }
}

int main(){
    int n , m ; cin >> n >> m ; 
    forn(i,n){
        cin >> a[i] ; 
        parent[i] = i ; 
        LIS[i] = 1 ; 
    }
    lis(n) ; 
    // forn(i,n){
    //     cout << parent[i] << sp << el ; 
    // }
    // cout << el ;
    // forn(i,n){
    //     cout << LIS[i] << sp << el ; 
    // }
    int maxV = LIS[0] ; int maxI = 0 ; 
    for(int i = 1 ; i < n ; i++){
        if (maxV < LIS[i]){
            maxV = LIS[i] ; 
            maxI = i ; 
        }
    } 
    
    int curr = maxI ; 
    vi v  ;
    while (parent[curr] != curr){
        v.pb(curr) ; 
        curr = parent[curr] ; 
    }
    v.pb(curr) ;
    reverse(all(v)) ;
    forn(i,v.size()){
        cout << v[i] << sp ; 
    } 
    cout << el ; 
    int len = v.size() ;  
    //cout << len << el ; 
    forn(i,m){
        int idx , h ; 
        cin >> idx >> h ; 
        idx-- ; 
        
        
        if (binary_search(all(v),idx)){
            vi :: iterator lo = lower_bound(all(v),idx) ; 
            vi :: iterator up = upper_bound(all(v),idx) ; 
            if (lo == v.begin()){
                if (h < a[*(lo+1)]){
                    cout << len << el ; continue ; 
                }
                else{
                    cout << len-1 << el  ; continue ;
                }
            }
            else if (up == v.end()){
                if (h > a[*(lo-1)]){
                    cout << len << el; continue ; 
                }
                else{
                    cout << len-1 << el ; continue ; 
                }
            }
            else{
                if (h > a[*(lo-1)] && h < a[*up]){
                    cout << len << el ; continue ; 
                }
                else{
                    cout << len-1 << el ; continue ; 
                }
            }
            
        }
        else{
            vi :: iterator lo = lower_bound(all(v),idx) ; 
            vi :: iterator up = upper_bound(all(v),idx) ; 
            if (lo == v.begin()){
                if (h < a[*lo]){
                    cout << len+1 << el; continue ;
                }
                else{
                    cout << len << el ; continue ; 
                }
            }
            if (up == v.end()){
                if (h > a[*(up-1)]){
                    cout << len+1 << el ; continue ; 
                }
                else{
                    cout << len << el ; continue ; 
                }
            }
            else{
                lo -= 1 ; 
                if (h > a[*lo] && h < a[*up]){
                    cout << len+1 << el ; continue ; 
                }
                else{
                    cout << len << el ; continue ; 
                }
            }
            
            
            
        }  
    }
}