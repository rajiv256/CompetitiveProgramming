/* Resilience is the greatest of all virtues
Code by rajiv

Tags : Matrix Exponentiation , medium , Letters
Link : https://www.hackerearth.com/problem/algorithm/pk-and-interesting-language/description/

Recurrence : dp[N+1][next_letter] += All letters as last_letter {dp[N][last_letter]*Possible[last_letter][next_letter]}

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
#define abs(x) ((x<=0)?(-x):(x))
#define CASET  int t;cin>>t;while(t--)
#define FORN(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define MAXN 100005
#define INF 10000000010
#define MOD 1000000007
#define last_set_bit(x) log2((x)&(-x))
#define add(x,y) (x)=((x)+(y))%MOD
#define PI 3.141592653589793

typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;


void multiply(ll A[26][26], ll B[26][26]){
    const int ROWS= 26 ;
    const int COLS = 26 ;
    const int COLS2 = 26 ;
    ll P[ROWS][COLS2] ;
    FORN(i,0,ROWS){
        FORN(j,0,COLS2){
            P[i][j] = 0 ;
            FORN(k,0,COLS){
                P[i][j] = (P[i][j]+A[i][k]*B[k][j])%MOD ;
            }
        }
    }
    FORN(i,0,ROWS){
        FORN(j,0,COLS2){
            A[i][j] = P[i][j] ;
        }
    }
}
ll M[26][26] ;
void power(ll A[26][26], ll x){
    if (x <= 1 ) return ;
    power(A,x/2) ;
    multiply(A,A) ;
    if (x&1){
        multiply(A,M) ;
    }
}


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    memset(M,0,sizeof(M)) ;
    ll A[26][26] ;
    FORN(i,0,26){
        FORN(j,0,26){
            cin >> M[i][j] ;
            A[i][j] = M[i][j] ;
        }
    }
    CASET {
        char c  ; ll L ;
        memcpy(A,M,sizeof M) ;
        cin >> c >> L ;
        if (L == 1){
            cout <<  1 << el ;
            continue ;
        }
        power(A,L-1) ;

        ll ans = 0 ;
        FORN(i,0,26){
            ans += A[i][c-'a'] ;
            ans %= MOD ;
        }
        cout << ans << el;

    }


}
