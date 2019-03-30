#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <sys/time.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <cmath>

using namespace std ;

#define xx first
#define yy second
#define ll long long
#define ld long double
#define el (char)0x0A
#define sp " "
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define clr(x) memset((x),0,sizeof(x))
#define uint unsigned int
#define CASET  int t;cin>>t;while(t--)
#define forn(i,x,y) for(int i=x;i<y;i++)
#define maxn 100005
#define inf 10000000010
#define mod 1000000007
#define last_set_bit(x) log2((x)&(-x))
#define add(x,y) (x)=((x)+(y))%MOD
#define PI 3.141592653589793

typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

bool bet(int x, int a, int b){
    if (x>=a && x <= b) return true ;
    return false ;
}
bool intersect(pair<int,int> p1, pair<int,int> p2){
    int a = p1.xx ; int b = p1.yy ; int c = p2.xx ; int d = p2.yy ;
    if (bet(c,a,b) || bet(d,a,b) || bet(a,c,d) || bet(b,c,d)) return true ;
    return false ;
}


int main(){
    int n ,m ; cin >> n >> m ;
    vector<pair<int,int> > v ;
    for(int i = 0 ; i < m ; i++){
        int a, b ; cin >> a >> b ;
        v.pb(mp(a,b)) ;
    }
    int q ; cin >> q ;
    while (q--){
        int c, d ; cin >> c >> d ;
        int fl = 1  ;
        for(int i = 0 ; i < v.size() ; i++){
            if (intersect(v[i], mp(c,d))){
                fl = 0 ;
            }
        }
        if (fl){
            cout << "OK" << el ;
            v.pb(mp(c,d)) ;
        }
        else{
            cout << "NG" << el ;
        }
    }


}
