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

typedef struct node{
    int lo, hi ;
    int maxi ;
}node ;

node stree[4*maxn] ;
int a[maxn] ;

void build(int s, int lo, int hi){
    if (lo == hi){
        stree[s].maxi = a[lo] ;
        return ;
    }
    int mid = (lo+hi)>>1 ;
    build(2*s+1, lo, mid) ;
    build(2*s+2, mid+1, hi) ;
    stree[s].maxi = max(stree[2*s+1].maxi, stree[2*s+2].maxi) ;
}

int query(int s, int lo, int hi, int left, int right){
    if (left > hi || right < lo){
        return -(1e9+7) ;
    }
    if (lo >= left && hi<=right){
        return stree[s].maxi ;
    }
    int mid = (lo+hi)>>1 ;
    int t1  = query(2*s+1, lo, mid, left, right) ;
    int t2  = query(2*s+2, mid+1, hi, left, right) ;
    return max(t1,t2) ;
}









int main(){
    memset(stree, 0, sizeof stree) ;
    int n, L ; cin >> n >> L ;
    forn(i,0,n) cin >> a[i] ;

    build(0, 0, n-1) ;

    for(int x = 0 ; x < n-L+1 ; x++){
        cout << query(0, 0, n-1, x, x+L-1) << el ;
    }
    return 0 ;
}


























//}
