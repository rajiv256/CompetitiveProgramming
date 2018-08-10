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
#define ll long long

int a[25] ; 
int parent[25] ; 
int L[25][25] ; 

int IDX = -1; 

int solve(int sum , int prev , int idx , int n){
    if (sum < 0){
        return 0 ;
    }
    if (sum == 0){
        IDX = idx-1 ; 
        return 1 ; 
    }
    if (idx == n){
        if (sum == 0){
            IDX = idx-1 ; 
            return 1 ; 
        }
        return 0 ;
    }
    if (prev != -1){
        if (L[prev][idx] != -1){
            return L[prev][idx] ; 
        }
    }
    parent[idx] = prev ; 
    L[idx][idx+1] = solve(sum-a[idx],idx,idx+1,n) ; 
    if (L[idx][idx+1] == 1){
        return 1 ; 
    }
    parent[idx] = -1 ; 
    L[prev][idx+1] = solve(sum,prev,idx+1,n) ; 
    if (L[prev][idx+1] ==1){
        return 1 ; 
    }
    return 0 ; 
}


int main(){
    int t ; sci(t) ; 
    while (t--){
        forn(i,25){
            a[i] = -1 ;
            parent[i] = -1 ; 
            forn(j,25){
                L[i][j] = -1 ; 
            }
        }
        
        int n ; sci(n) ; 
        forn(i,n){
            sci(a[i]) ; 
        }
        int sum = 0 ; 
        forn(i,n){
            sum += a[i] ; 
        }
        if (sum%4 != 0 || n < 4){
            cout << "no" << el ; 
            continue ; 
        }
        int fl = 0  ;
        
        forn(i,4){
            int x = solve(sum/4,-1,0,n) ; 
            
            if (x == 0){
                 cout << "no" << el ; 
                 fl = 1 ; 
                 break ; 
            }
            x = IDX  ; 
            //cout << "IDX : " <<  IDX << el ; 
            while (x != -1){
                a[x] = 0 ;
                x = parent[x] ;  
            }
            
            IDX = -1 ; 
            forn(i,25){
            
            parent[i] = -1 ; 
            forn(j,25){
                L[i][j] = -1 ; 
            }
        }
        
        }
        if (fl == 0)
            cout << "yes" << el ; 
    }
}