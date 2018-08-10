// Done!! see
#include <bits/stdc++.h>

using namespace std ;
typedef vector<int> vi ; 
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ; 
typedef vector<pair<int,pair<int,int> > > vpp ; 
typedef vector<bool> vb ;
typedef set<int> si ; 
typedef map<int,int> mii ; 
typedef map<int,vector<int> > miv ; 
typedef unsigned long long ull ; 
typedef vector<vector<pair<int,int> > > vvp ;

#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> > 
#define MOD 1000000007
#define MXN 100005
#define MAX 10000000000 
#define sp " " 
#define el "\n"
#define ll long long int 
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x) 
#define mysqrt(n) (int)(sqrt(n))
#define printv(v,sz) forn(i,sz){cout<<v[i]<<sp;}cout<<el 

ll a[503][503] ; 
ll dupe[503][503]  ;
void floydWarshall(int n) {
    forn(k,n){
        forn(i,n){
            forn(j,n){
                if ((i != j) && (j != k)){
                    if (dupe[i][j] > dupe[i][k]+dupe[k][j]){
                        dupe[i][j] = dupe[i][k]+dupe[k][j] ; 
                    }
                }
            }   
        }
    }
    return ; 
}

ll sumAllShortestPaths(int n,vb& over){
    
    ll sum = 0 ; 
    forn(i,n){
        forn(j,n){
           if (i != j)
           if (!over[i] && !over[j])
               sum += dupe[i][j] ; 
        }
    }
    return sum ; 
}

void removeVertex(int s, int n,vb& over){
    forn(j,n){
           forn(k,n){
               cout << dupe[j][k] << sp ; 
           }
           cout << el ;
    }
    cout << el ; 
    forn(i,n){
        forn(j,n){
            if (i != j){
                if (dupe[i][j] == dupe[i][s]+dupe[s][i]){
                    ll mini = 1000000 ; 
                    forn(k,n){
                        if (k != i && k != j && !over[k] && !over[i] && !over[j]){
                            if (i == 2 && j == 0){
                                cout << dupe[i][k] << sp << dupe[k][j] << el ; 
                            }
                            mini = min(mini , dupe[i][k]+dupe[k][j]) ; 
                            dupe[i][j] = mini ; 
                        }
                    }
                }
            }
        }
    }
}


int main(){
    int n ; cin >> n ; 
    forn(i,n){
        forn(j,n){
            cin >> a[i][j] ; 
        }
    }
    forn(i,n){
        forn(j,n){
           dupe[i][j] = a[i][j] ;  
        }
    }
    vi v(n) ; 
    forn(i,n){
        cin >> v[i] ; 
        v[i]-- ; 
    }
    floydWarshall(n) ; 
    vb over(n,false); 
    forn(i,n){
       ll sum = sumAllShortestPaths(n,over) ; 
       cout << sum << el ; 
       //cout << el ; 
       over[v[i]] = true ;  
       removeVertex(v[i],n,over) ; 
       forn(j,n){
           forn(k,n){
               cout << dupe[j][k] << sp ; 
           }
           cout << el ;
       }
    }
    return 0 ; 
}