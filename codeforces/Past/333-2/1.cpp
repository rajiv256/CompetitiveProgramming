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

int main(){
    int n1 , b1 , n2 , b2 ;
    sci(n1) ; sci(b1) ;
    ll num1 = 0 ; int x ;

    forn(i,n1){
        sci(x) ;
        num1 *= b1 ;
        num1 += x ;

    }
    ll num2 = 0 ;
    sci(n2) ; sci(b2) ;
    forn(i,n2){
        sci(x) ;
        num2 *= b2 ;
        num2 += x ;
    }
    if (num1 < num2){
        cout << '<' << el ;
    }
    if (num1 == num2){
        cout << '=' << el ;
    }
    if (num1 > num2){
        cout << '>' << el ;
    }
}