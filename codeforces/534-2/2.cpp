
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
#define FORN(i,x,y) for(int i=x;i<y;i++)
#define MAXN 100005
#define INF 10000000010
#define MOD 1000000007
#define last_set_bit(x) log2((x)&(-x))
#define add(x,y) (x)=((x)+(y))%MOD
#define PI 3.141592653589793

bool valid(int idx , string s){
    if (idx < 0 || idx >= s.size()) return false ;
    return true ;
}

int solve(string s){

    if (s.size() == 1) return 0 ;
    s = "#" + s ;
    int beg = 0 ;int end = 1 ; int pairs = 0 ;
    while (beg < s.size()){

        if (!valid(beg, s) || !valid(end, s)) break ;
        while (end < s.size() && s[beg] == s[end]){
            end++ ;
        }
        end-- ;
        if (end == beg) {
            beg++ ;
            end = beg ;
            continue ;
        }
        int cnt = end-beg+1 ;
        if (cnt %2 == 0){
            pairs += cnt / 2 ;
            string str = s;
            s = str.substr(0,beg) + str.substr(end+1) ;
            beg-- ;
            end = beg ;
        }
        else{
            pairs += cnt / 2 ;
            string str = s ;
            s = str.substr(0, beg) + str.substr(end) ;
            end = beg+1 ;
        }

    }
    return pairs ;
}
int main(){
    string s; cin >> s ;

    int ans = solve(s) ;

    if (ans % 2 == 0){
        cout << "No\n" ;
    }
    else cout << "Yes\n" ;
    return 0 ;
}
