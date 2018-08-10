
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

int a[2*1000003] ; 

int main(){
    int n , m ; sci(n) ; sci(m) ; 
    memset(a,-1,sizeof(a)) ; 
    if (n==0 && m >=3){
        cout << "-1" << el ; 
        return 0 ;
    }
    if (m== 0 && n >= 2){
        cout << "-1" << el ; 
        return 0 ; 
    }
    
    if (m > 2*n+2){
        cout << "-1" << el; 
        return 0 ; 
    }
    if (n > m+1){
        cout << "-1" << el; 
        return 0 ; 
    }
    bool b1 = false , b2 = false ;
    int n1 = n , m1 = m ; 
    int fl1 = 0 ; 
    int idx = 0 ; 
    while (n1 != 0){
        a[idx] = 0 ;n1 -= 1 ; 
        if (m1 == 0){
            if (n1 >=1){
                cout << "-1" << el ; 
                return 0 ; 
            }
            break ; 
        }
        a[idx+1] = 1 ; 
        idx += 2 ; 
        m1 -= 1 ; 
    }
    idx = 1 ; 
    
    while (m1 != 0 && a[idx] !=-1){
        a[idx] += 1 ; 
        idx += 2 ; 
        m1 -= 1 ; 
    }
     //cout << m1 << el ;
    if (m1 > 2){
        cout << "-1" << el ; 
        return 0 ; 
    }
    forn(i,m1){
        cout << "1"  ; 
    }
    idx = 0 ;
    while (a[idx] != -1){
        cout << a[idx]  ; 
        idx++ ; 
        forn(i,a[idx]){
            cout << "1" ; 
        }
        idx++ ; 
    }
    return 0 ; 
}