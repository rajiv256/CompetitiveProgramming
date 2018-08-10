// Needs DP solution. Think. Its easy only.
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

int area[505][505] ;
int field[505][505] ;
int rep[505][505] ;

int main(){
    int t ; sci(t) ; int x = 1 ;
    while (t--){
        int m , n ,k ; sci(m) ; sci(n) ; sci(k) ;
        forn(i,m){
            forn(j,n){
                sci(area[i][j]) ;
            }
        }
        memset(field,-1,sizeof(field)) ;
        memset(rep,0,sizeof(rep)) ;

        forn(i,m){
            forn(j,n){
                forn(ii,m){
                    forn(jj,n){
                        if (ii+k-1 < m && i >= ii && i < ii+k){
                            if (jj+k-1 < n && j >= jj && j < jj+k){
                                if (field[ii][jj] < area[i][j]){
                                    field[ii][jj] = area[i][j] ;
                                    rep[ii][jj] = 1 ;
                                }
                                else if (field[ii][jj] == area[i][j]){
                                    rep[ii][jj] += 1 ;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << "Case " << x << ":" << el ;
        x++ ;
        forn(i,m-k+1){
            forn(j,n-k+1){

                if (rep[i][j] == 1){
                    cout << field[i][j] << sp ;
                }
                else{
                    cout << field[i][j] << "(" << rep[i][j] << ")" << sp ;
                }
            }
            cout << el ;
        }

    }
    return 0 ;
}