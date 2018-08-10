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
typedef vector<vector<pair<int,int> > > vvp ;

#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> > 
#define MOD 1000000007
#define MXN 100005
#define sp " " 
#define el "\n"
#define ll long long int 
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x) 
#define mysqrt(n) (int)(sqrt(n))
#define printv(v,sz) forn(i,sz){cout<<v[i]<<sp;}cout<<el 
int A[MXN] ; 
int L[MXN] ; 
int dp (int S , int N){
    L[0] = 0 ;
    forn(i,N){
        L[A[i]] = 1 ; 
    }
    forn(i,N){
        forn(j,S+1){
            if (L[j] != 10000){
                if (L[j+A[i]] == 10000){
                    L[j+A[i]] = L[j] +1 ; 
                }
                else {
                    if (L[j+A[i]] > L[j] +1){
                    L[j+A[i]] = L[j] +1 ; 
                }
     
                }
                           }
            
        }
    }
    return L[S] ; 
    
}



int main(){
    memset(A,0,sizeof(A)) ; 
    forn(i,MXN){
        L[i] = 10000 ; 
    } 
    
    int N ; sci(N) ; 
    forn(i,N){
        sci(A[i]) ; 
    }
    int S ; sci(S) ; 
    
    int ans = dp(S,N) ; 
    printv(L,S+1) ; 
    cout << ans << el ;
    
}