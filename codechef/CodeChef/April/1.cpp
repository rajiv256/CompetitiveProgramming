#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
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

int a[103] ;
int b[103] ;


int main(){
    int t ; sci(t) ;
    while(t--){
        int n ; sci(n);
        vpp v ; int l , r ;
        forn(i,n){
            sci(a[i]) ;
        }
        forn(i,n){
            sci(b[i]) ;
        }
        forn(i,n){
            l = a[i] ; r = b[i] ;
            v.pb(mp(mp(l*r,r),i+1)) ;
        }
        sort(all(v)) ;
        int maxV = v[v.size()-1].xx.xx ;
        int maxR = v[v.size()-1].xx.yy ;
        int j ;
        for(j = v.size()-1 ; j >= 0 ; j--){
            if (v[j].xx.xx == maxV){
                if (v[j].xx.yy == maxR){
                    continue ;
                }
                else{
                    break ;
                }
            }
            else{
                break ;
            }
        }
        cout << v[j+1].yy << el ;


    }
    return 0 ;
}