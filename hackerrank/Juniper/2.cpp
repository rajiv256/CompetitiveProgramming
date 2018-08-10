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

int L[60][1009] ;

int solve(int time,int ch ,vector<vb > channels , int n){

    if (time == 60){
        return 0 ;
    }
    if (L[time][ch] != -1){
        return L[time][ch] ;
    }
    int x = ch-1 ;
    if (x < 0){
        x += n;
    }
    L[time+1][ch] = solve(time+1,ch,channels,n) ;
    L[time+1][(ch+1)%n] = solve(time+1,(ch+1)%n,channels,n) ;
    L[time+1][x] = solve(time+1,x,channels,n) ;
    int ans = 0 ;
    if (channels[ch][time]==true){
        ans = max(ans,L[time+1][ch]);
    }
    else{
        ans = max(ans,1+L[time+1][ch]) ;
    }
    ans = max(ans,max(L[time+1][x],L[time+1][(ch+1)%n])) ;
    return ans ;
}

int main(){
    int n ; sci(n) ;
    vb adv(60,false)  ;
    vector<vb > channels(n,adv) ;
    int m ;
    forn(i,n){
        sci(m) ;
        int st , en ;
        forn(j,m){
            sci(st) ; sci(en) ;
    memset(L,-1,sizeof(L)) ;
            //cout << st << sp << en << el ;
            for(int k = st ; k < en ; k++){
                channels[i][k] = true ;
            }
        }
    }
    //cout << "ccame" << el ;
    int ans = solve(0,0,channels,n) ;
    cout << ans << el ;
}