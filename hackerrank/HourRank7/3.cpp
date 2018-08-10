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
#define MOD 1000000007

ll ans = 0 ; 
ll N ; 
int T ; 

int main(){
    sci(T) ;
    while (T--){
        cin >> N ; 
        ans = 0 ; 
        ll start ,diff ,maxdiff ;
        for(start = 1 ; start <= N ; start++){
            maxdiff = N-start ; 
            for(diff = 1 ; diff <= maxdiff ; diff++){
                ans += (N-start)/diff ;
                ans %= MOD ;  
            }
        }
        ans += (N%MOD) ; 
        ans %= MOD ; 
        cout << ans << el; 
    }
    return 0 ; 
}