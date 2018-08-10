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
#define MXN 100005
#define MOD 1000000007
#define ll long long

int a[MXN] ;

int main(){

    int n , k ; sci(n) ; sci(k) ;
    string s ; cin >> s ;
    forn(i,n){
        a[i] = s[i]-'0' ;
    }
    int cf[n+1] ;
    cf[0] = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if (a[i-1] == 0){
            cf[i] = cf[i-1]+1 ;
        }
        else{
            cf[i] = cf[i-1] ;
        }
    }
    vi v ;
    int x = 0 ;
    while (x < n){
        if (a[x] ==1 ){
            v.pb(x) ;
            x++ ;
            while(x < n && a[x]==1){
                x++ ;
            }
            v.pb(x-1) ;
        }
        else{
            x++ ;
        }
    }

    int ans = INT_MAX ;
    for(int i = 1 ; i <= n ; i++){
        int st = i-1 ;
        if (a[st] == 0){
            if (binary_search(cf,cf+n+1,k+1+cf[i-1])){
                int idx = lower_bound(cf,cf+n+1,k+1+cf[i-1])-cf ;
                idx -= 1;
                int mid = (st+idx)/2 ;
                //cout << st << sp << idx << el ;
                if (a[mid]==0){
                    ans = min(ans,idx-mid) ;
                }
                else{
                    if (binary_search(all(v),mid)){
                        int pos = lower_bound(all(v),mid)-v.begin() ;
                        if (a[v[pos]-1]==0){
                            ans = min(ans,idx-(v[pos]-1))  ;
                        }
                        else if (a[v[pos]+1]==0){
                            ans = min(ans,v[pos]+1-st) ;
                        }
                    }
                    else{
                        int pos = lower_bound(all(v),mid)-v.begin() ;
                        int lb = pos-1 ;
                        int ub = pos ;
                        ans = min(ans,abs(idx-(v[lb]-1))) ;
                        ans = min(ans,abs(v[ub]+1-st)) ;
                    }
                }

            }
        }

    }
    cout << ans << el ;
    return 0  ;

}














