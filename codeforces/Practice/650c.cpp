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
int pre[100005]  ; 
int suf[100005] ; 

int main(){
    int n , k ; 
    cin >> n >> k ; 
    char c ;
    memset(a,0,sizeof(a)) ;   
    string s ; cin >> s ; 
    a[0] = -1 ; 
    forn(i,n){
        a[i+1] = s[i]-'0' ; 
    }
    int cnt = 0 ;
    pre[0] = 0 ;  
    for(int i = 1 ; i <= n ; i++){
        //cout << a[i] << el ;
        if (a[i]==0){
            cnt++ ; 
            pre[i] = cnt ; 
        }
        else{
            pre[i] = cnt ; 
        }
    }
    cnt = 0 ; 
    for(int i = n ; i >= 1 ; i--){
        if (a[i] == 0){
            cnt++ ;
            suf[i] = cnt ;  
        }
        else{
            suf[i] = cnt ; 
        }
    }
    int ans = INT_MAX  ; 
    vi v ; 
    v.pb(0) ; 
    forn(i,n){
        v.pb(pre[i+1]) ; 
    }
     
    vi::iterator it1 , it2 ; 
    for(int i = 1 ; i <= n ; i++){
        if (a[i] == 0){
            if (pre[i] > k/2 && suf[i]> k/2){
                if (k%2 == 0){
                    it1 = lower_bound(all(v),pre[i]-k/2) ; 
                    it2 = lower_bound(all(v),pre[i]+k/2) ; 
                    if (it1 != v.begin() && it2 != v.end()){
                        int li = (it1-v.begin()) ;
                        int ri = (it2-v.begin()) ;  
                        //cout <<i << sp<< li << sp << ri << el ; 
                        ans = min(ans,max(i-li,ri-i)) ; 
                    }
                }
                else{
                    //cout << i-1 << sp << a[i] << el ;     
                    it1 = lower_bound(all(v),pre[i]-k/2) ; 
                    it2 = lower_bound(all(v),pre[i]+k/2+1) ; 
                    if (it1 != v.begin() && it2 != v.end()){
                        int li = (it1-v.begin()) ; 
                        int ri = (it2-v.begin()) ;
                        //cout << li << sp << ri << el ;  
                        ans = min(ans,max(i-li,ri-i)) ; 
                    }
                    
                    it1 = lower_bound(all(v),pre[i]-k/2-1) ; 
                    it2 = lower_bound(all(v),pre[i]+k/2-1) ; 
                    if (it1 != v.begin() && it2 != v.end()){
                        int li = (it1-v.begin()) ; 
                        int ri = (it2-v.begin()) ; 
                        //cout << li << sp << ri << el ;
                        ans = min(ans,max(i-li,ri-i)) ;  
                    }
                }        
            }    
        }
    }
    cout << ans << el ; 
    return 0  ;  
}
