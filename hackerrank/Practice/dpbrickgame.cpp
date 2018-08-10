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
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp " " 
#define el "\n"
#define ll long long int 
#define sci(x) scanf("%d",&x)

ll a[100005] ; 
ll L[2][100005] ; 

ll solve(int idx ,int flag , int n){
    if (idx == n){
        return 0 ; 
    }
    if (L[flag][idx] != -1){
        return L[flag][idx] ; 
    }
    if (flag == 0){
        L[1][idx+1] = solve(idx+1,1,n) ; 
        L[1][idx+2] = solve(idx+2,1,n) ; 
        L[1][idx+3] = solve(idx+3,1,n) ; 
        return (max(a[idx]+L[1][idx+1], max(a[idx]+a[idx+1]+L[1][idx+2],a[idx]+a[idx+1]+a[idx+2]+L[1][idx+3])));
    }
    if (flag == 1){
        L[0][idx+1] = solve(idx+1,0,n) ; 
        L[0][idx+2] = solve(idx+2,0,n) ; 
        L[0][idx+3] = solve(idx+3,0,n) ; 
        return (min(L[0][idx+1], min(L[0][idx+2],L[0][idx+3])));
    }
}




int main(){
    int t ; sci(t) ; 
    while (t--){
        int n ; sci(n) ; 
        memset(a,0,sizeof(a)) ; 
        memset(L,-1,sizeof(L)) ; 
        forn(i,n){
            cin >> a[i] ; 
        }
        L[0][0] = solve(0,0,n) ; 
       
        cout << L[0][0] << el ; 
    }
    return 0 ; 
}