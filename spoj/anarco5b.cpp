//rajiv's code
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
#define MOD 1000000007
#define sp " " 
#define el "\n"
#define ll long long int 
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x) 

int dp[2][10003] ; 
int a[10003] ; 
int b[10003] ; 

ll solve(int choice, int idx, int n1 , int n2){
    if (choice == 0 && idx == n1){
        return 0 ; 
    }
    if (choice == 1 && idx == n2){
        return 0 ; 
    } 
    if (dp[choice][idx] != -1){
        return dp[choice][idx] ; 
    }
    if (choice == 0){
         
        if (binary_search(b,b+n2,a[idx])){
            int* idx2p = upper_bound(b,b+n2,a[idx]) ; 
            int idx2 = idx2p-b ; 
            dp[0][idx+1] = solve(0,idx+1,n1,n2) ; 
            dp[1][idx2] = solve(1,idx2,n1,n2) ; 
            return (a[idx]+max(dp[0][idx+1],dp[1][idx2])) ; 
        }
        else{
            dp[0][idx+1] = solve(0,idx+1,n1,n2) ; 
            return (a[idx]+dp[0][idx+1]) ; 
        }
    }
    
    if (choice == 1){
        if (binary_search(a,a+n1,b[idx])){
            int* idx2p = upper_bound(a,a+n1,b[idx]) ;
            int idx2 = idx2p-a ;  
            dp[1][idx+1] = solve(1,idx+1,n1,n2) ; 
            dp[0][idx2] = solve(0,idx2,n1,n2) ; 
            return (b[idx]+max(dp[1][idx+1],dp[0][idx2])) ; 
        }
        else{
            dp[1][idx+1] = solve(1,idx+1,n1,n2) ; 
            return (b[idx]+dp[1][idx+1]) ; 
        }
    }
}





int main(){
    int n ; sci(n) ; 
    while (n != 0){
        memset(a,0,sizeof(a)) ; 
        memset(b,0,sizeof(b)) ; 
        memset(dp,-1,sizeof(dp)) ; 
        int n1 , n2 ; 
        forn(i,n){
            sci(a[i]) ;
        }
        n1 = n ; 
        sci(n) ; 
        forn(i,n){
            sci(b[i]) ; 
        }
        n2 = n ; 
        
        ll res = max(solve(0,0,n1,n2),solve(1,0,n1,n2)) ; 
        cout << res << el ; 
        sci(n) ; 
    }
    return  0 ; 
}