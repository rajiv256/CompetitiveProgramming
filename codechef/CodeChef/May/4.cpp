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
#define MXN 100003
#define MOD 1000000007
#define gc getchar_unlocked

ll cnt[1003] ;
vector<int> adj[1003] ;
int x[1003] ;
int n , m , s ;
ll L[1003][1003] ;
bool isValid(int a){
    if (a >= 0 && a < n){
        return true ;
    }
    return false ;
}



int main(){
    int t ; sci(t) ;
    while(t--){
        sci(n) ; sci(m) ; sci(s) ;
        forn(i,n){
            cnt[i] = 0 ;
        }
        forn(i,m){
            x[i] = 0 ;
        }
        memset(L,0,sizeof(L))  ;
        for(int i = 0 ; i < m ; i++){
            sci(x[i]) ;
        }
        s -= 1 ;
        L[0][s] = 1%MOD ;
        for(int d = 1 ; d <= m ; d++){
            for(int i = 0 ; i < n ; i++){
                if (L[d-1][i] != 0){
                    if (isValid(i-x[d-1])){
                        L[d][i-x[d-1]] += L[d-1][i] ;
                        L[d][i-x[d-1]] %= MOD ;
                    }
                    if (isValid(i+x[d-1])){
                       L[d][i+x[d-1]] += L[d-1][i] ;
                       L[d][i+x[d-1]] %= MOD ;
                    }

                }
            }

        }
        for(int i = 0 ; i < n ; i++){
            cout << L[m][i] << sp ;
        }

        cout << el ;

    }

}