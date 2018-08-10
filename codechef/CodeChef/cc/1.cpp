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

int a[100005] ;
int l[100005] ; 

int dp(int idx, int n){
    if (idx == n){
        return 0 ; 
    }
    if (idx+1 == n){
        return 1 ; 
    }
    if (l[idx] != -1){
        return l[idx] ; 
    }
    if (a[idx] < 0){
        l[idx+1] = dp(idx+1,n) ; 
        if (a[idx+1] < 0){
            return 1  ; 
        }
        else{
            return (1+l[idx+1]) ; 
        }
    }
    if (a[idx] >= 0){
        l[idx+1] = dp(idx+1,n) ; 
        if (a[idx+1] >= 0){
            return 1 ; 
        }
        else{
            return (1+l[idx+1]) ;
        }
    }
    
}
int main(){
    int t ; sci(t) ; 
    while (t--){
        memset(l,-1,sizeof(l)) ;
        memset(a,0,sizeof(a)) ; 
        int  n ; 
        sci(n) ; 
        forn(i,n){
            sci(a[i]) ; 
        }
        l[0] = dp(0,n) ; 
        forn(i,n){
            cout << l[i] << sp ; 
        }
        cout << el ; 
    }
    return 0 ; 
}