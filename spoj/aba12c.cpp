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

int cost[103] ;
int a[103];
int qt[103] ;



int main(){
    int t ; sci(t) ;
    while (t--){
        int n , k ;  sci(n) ; sci(k) ;
        memset(a,-1,sizeof(a)) ;
        int sz = 0 ; int k1 ;
        while (scanf("%d",&k1)!=EOF){
            a[sz] = k1 ;
            sz++ ;
        }

        vp v ;
        forn(i,sz){
            if (a[i] != -1){
                v.pb(mp(i+1,a[i])) ;
            }
        }

        memset(cost,-1,sizeof(cost)) ;
        memset(qt,-1,sizeof(qt)) ;
        forn(i,v.size()){
            cost[v[i].xx] = v[i].yy ;
        }
        forn(i,v.size()){
            qt[v[i].xx] = 1 ;

        }

        for(int i = 1 ; i < 103 ; i++){
            if (qt[i] != -1){
                for(int j = 1 ; j < 103 ; j++){
                    if (qt[j] != -1){
                        if (i+j < 103){
                            if (qt[i]+qt[j] < n){
                                qt[i+j] = min(qt[i+j],qt[i]+qt[j]) ;
                                cost[i+j] = min(cost[i+j],cost[i]+cost[j]) ;
                            }

                        }
                    }
                }
            }
        }
        cout << cost[k] << el ;
    }
    return 0 ;
}