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
#define MOD 1000000007
#define ll long long

ll req(int r){
    if (r == 0)
        return 1 ;
    if (r ==1){
        return 10 ;
    }
    ll temp = req (r/2) ;
    ll k = ((temp)*(temp))%MOD ;
    if (r%2==0){
        return k ;
    }
    else{
        return 10*k ;
    }
}


int main(){
    string s ; cin >> s ;
    int a[s.size()] ;
    forn(i,s.size()){
        a[i] = s[i]-'0' ;
    }
    int n = s.size() ;
    ll L[n] ; L[0] = 0 ; int ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        ans *= 10 ; ans += a[i] ;
        ans %= MOD ;
        L[0] += ans ;
        L[0] %= MOD ;
    }

    for(int i = 1 ; i < n ; i++){
        L[i] = L[i-1] - (a[i-1]*(req(n+1-i)/9))%MOD ;
    }

    ll res = 0 ;
    forn(i,n){
        res += L[i] ; res %= MOD ;
    }
    cout << res << el ;
    return 0 ;
}
