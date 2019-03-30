/*
	Resilience is the greatest of all virtues.
	Code by rajiv
*/
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

typedef struct side{
    int C = 0, B = 0 , A = 0,  N = 0 ;
}side ;
bool odd(int x){
    return x&1 ;
}
bool valid(int x, int L){
    return (x >=0 && x <= L);
}


int main(){
    int n ;
    int C = 0,  B = 0,  A = 0, N = 0 ;
    vector<int> cs, bs, as, ns ;
    char cl[maxn] , ac[maxn] ;
    // memset(cl,0,sizeof cl) ;
    // memset(ac,0,sizeof ac) ;
    scanf("%d\n%s\n%s",&n, cl, ac) ;



    cs.clear() ; bs.clear() ; as.clear() ; ns.clear() ;
    forn(i,0,n){
        //cout << cl[i] << sp << ac[i] << el ;
        if (cl[i]=='1' && ac[i]=='1'){

            B++ ;bs.pb(i+1) ;
        }
        else if (cl[i] == '1'){
            C++ ; cs.pb(i+1) ;
        }
        else if (ac[i] == '1') {
            A++ ; as.pb(i+1) ;
        }
        else {
            N++ ; ns.pb(i+1) ;
        }
    }

    side left , right ;
    if (abs(C-A) > B){
        printf("-1\n") ;
        return 0 ;
    }
    if (odd(A) && odd(B) && odd(C) && odd(N)){
        left.B++ ; left.N++ ; N-- ; B-- ;
        right.A++ ; right.C++ ; A-- ; C-- ;
    }
    if (odd(A) && odd(B)){
        left.B++ ; right.A++ ; B-- ; A-- ;
    }
    if (odd(A) && odd(C)){
        left.C++ ; right.A++ ; A-- ; C-- ;
    }
    if (odd(A) && odd(N)){
        if (A < C){
            right.A++ ; left.N++ ;
        }
        else{
            left.A++ ; right.N++ ;
        }
        A-- ; N-- ;
    }

    if (odd(B) && odd(C)){
        left.C++ ; right.B++ ; B-- ; C-- ;
    }
    if (odd(B) && odd(N)){
        left.B++ ; right.N++ ; N-- ; B-- ;
    }
    if (odd(C) && odd(N)){
        right.C++ ; left.N++ ; C-- ; N-- ;
    }
    left.C += C ; C = 0 ;
    right.A += A ; A = 0 ;
    if (left.C + left.B < right.A+right.B){
        left.B += right.A - left.C ;
        B -= right.A - left.C ;
    }
    else if (left.C+left.B > right.A+right.B){
        right.B += left.C - right.A ;
        B -= left.C - right.A ;
    }
    left.B += B/2 ; right.B += B/2 ; B = 0  ;
    left.N += N/2 ; right.N += N/2 ; N = 0 ;
    // cout << left.C << sp << left.B << sp << left.A << sp << left.N << el ;
    vector<int> ans ;
    if (left.C > cs.size() || left.B > bs.size() || left.A > as.size() || left.N > ns.size()){
        printf("-1\n");
        return 0 ;
    }
    forn(i,0,left.C) ans.pb(cs[i]) ;

    forn(i,0,left.B) ans.pb(bs[i]) ;

    forn(i,0,left.A) ans.pb(as[i]) ;

    forn(i,0,left.N) ans.pb(ns[i]) ;

    for(auto it: ans){
        printf("%d ", it) ;
    }
    printf("\n") ;
    return 0 ;


}
































//}
