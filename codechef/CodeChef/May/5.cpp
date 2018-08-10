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

ll f[222] ;
int a,n,q , k ;
int res = 0 ;


void rec(int rest , int pos, int cnt){
    if (cnt == k){
        if(rest == 0){
            res += 1 ;
            res%=1000000007 ;
        }
        return ;
    }
    if (pos < 0 ){
        return ;
    }
    if (rest == 0){
        return ;
    }
    if (1ll*f[pos]*(k-cnt) < rest){
        return ;
    }
    if (rest >= f[pos]){
        rec(rest-f[pos],pos,cnt-1) ;
    }
    rec(rest,pos-1,cnt) ;


}




int main(){
    f[0] = 1 ;
    f[1] = 2 ;
    for (int i = 2 ; i <= 42 ; i++){
        f[i] = f[i-1]+f[i-2] ;
    }
    int T ; sci(T) ;
    while(T--){
        res = 0 ;
        scanf("%d%d",&a,&k) ;
        rec(42,0) ;
        cout << res << el ;
        cout << res << el ;
    }



}