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

int n ;

bool inlimits(int idx){
    if (idx >= 0 && idx < n){
       return true ;  
    }
    return false ; 
}

bool check(int eidx,int cidx, vi& v){
    if (eidx %2 == 0){
        if (v[cidx] > v[eidx-1] && v[cidx] > v[eidx+1]){
            if (cidx%2 == 0){
                if (v[eidx] > v[cidx-1] && v[eidx] > v[cidx+1]){
                    return true ; 
                }
            }
            else{
                if (v[eidx] < v[cidx-1] && v[eidx] < v[cidx+1]){
                    return true ; 
                }
            }
        }
    }
    else{
        if (v[cidx] < v[eidx-1] && v[cidx] < v[eidx+1]){
            if (cidx%2 == 0){
                if (v[eidx] > v[cidx-1] && v[eidx] > v[cidx+1]){
                    return true ; 
                }
            }
            else{
                if (v[eidx] < v[cidx-1] && v[eidx] < v[cidx+1]){
                    return true ; 
                }
            }
        }
    }
    return false ; 
}

int main(){
    
    cin >> n ; 
    vi v(n+2) ;
    v[0] = INT_MAX ; 
    if (n%2==1){
        v[n+1] = INT_MAX ; 
    }
    else{
        v[n+1] = INT_MIN ; 
    }
    forn(i,n){
        cin >> v[i+1] ; 
    }
    int cnt = 0 ; 
    int fl = 1 ; //incre
    int cf = 0 ;  // conflict with i , i+1 
    for(int i = 1 ; i <= n ; i++){
        if (fl == 1){
            if (v[i] < v[i+1]){
                fl = 0 ; 
                continue ; 
            }
            else{
                fl = 0; 
                cf = i ; 
                cnt++ ; 
            }
        }
        if (fl == 0){
            if (v[i] > v[i+1]){
                fl = 1; 
                continue ; 
            }
            else{
                fl = 1 ; 
                cf = i ; 
                cnt++ ; 
            }
        }
    }
    if (cnt >= 2){
        cout << "0 jjdj"  << el ; 
        return 0 ; 
    }
    int ans = 0 ; 
    for(int i = 1 ; i <= n ; i++){
        if (i != cf && i != cf+1){
            if (check(i,cf,v)){
                ans += 1 ; 
            }
        }
    }
    cf += 1 ; 
    for(int i = 1; i <= n ; i++){
        if (i != cf && i != cf-1){
            if (check(i,cf,v)){
                ans += 1 ; 
            }
        }
    }
    int temp = v[cf] ; 
    v[cf] = v[cf-1] ; 
    v[cf-1] = temp ;
    cf -= 1 ; 
    if (cf%2 == 0){
        if (v[cf] > v[cf+1]){
            ans += 1 ; 
        }
    }
    else{
        if (v[cf] < v[cf+1]){
            ans += 1 ; 
        }
    }
    
    cout << ans << el ;
    return 0 ; 
}