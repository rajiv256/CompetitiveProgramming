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

int main(){
    int n ; sci(n) ; string  s ; cin >> s ; 
    if (n == 1){
        cout << "1" << el ; 
        return 0 ; 
    }
 
    int fl = 0 ; 
    if (s[0] == 'B'){
        fl = 1 ; 
    }
    vi v ; v.pb(fl) ; 
    for(int i = 1 ; i < n ; i++){
        if (fl == 0){
            if (s[i] == 'B'){
                fl = 1 ; 
                v.pb(fl) ; 
                continue ; 
            }
        }
        if (fl == 1){
            if (s[i]  == 'R'){
                fl = 0 ; 
                v.pb(fl) ;
                continue ;  
            }
        }
    }
    cout << v.size() << el ; 
    return 0 ;  
}