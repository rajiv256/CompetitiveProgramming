// updated code . 
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

int main(){
    int n ; cin >> n ; 
    map<int,int> st ; map<int,int> en ;  
    int a , b ; 
    vp v ; 
    forn(i,n){
        cin >> a >> b ; 
        v.pb(mp(a,b)) ; 
        a += 1000000000 ; b += 1000000000 ; 
        st[a] += 1; en[b] += 1 ; 
    }
    sort(all(v)) ; 
    ll ans = 0 ; 
    for(map<int,int>:: iterator it = st.begin() ; it != st.end() ; it++){
        ll x = (*it).yy ; 
        ans += (x*(x-1))/2 ; 
    }
    for(map<int,int>:: iterator it = en.begin() ; it != en.end() ; it++){
        ll k = (*it).yy ; 
        ans += (k*(k-1))/2 ; 
    }
    ll cnt = 1  ;
    forn(i,n-1){
        if (v[i]==v[i+1]){
            cnt++ ; 
        }
        else{
            ans -= (cnt*(cnt-1))/2 ; 
            cnt = 1 ; 
        }
    }
    ans -= (cnt*(cnt-1))/2 ; 
    cout << ans << el ; 
    return 0 ; 
    
}