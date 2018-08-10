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
 #define abs(x) ((x<=0)?(-x):(x))
 #define CASET  int t;cin>>t;while(t--)
 #define FORN(i,x,y) for(int i=x;i<y;i++)
 #define MAXN 100005
 #define INF 10000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    set<int> zeros, ones ;

    string s;
    getline(cin,s) ;

    FORN(i,0,s.size()){
        if (s[i]=='0'){
            zeros.insert(i) ;
        }
        else{
            ones.insert(i) ;
        }
    }

    int fl = 1 ;
    vector<vector<int> > ans(s.size(),VI()) ;
    int iter = 0 ;
    while (iter < 250000){
        if (zeros.begin()==zeros.end()){
            break ;
        }

        int st , en ;
        st = en = *zeros.begin() ;
        zeros.erase(zeros.begin()) ;
        ans[iter].pb(st) ;
        while (ones.lower_bound(en+1)!=ones.end() && zeros.lower_bound((*ones.lower_bound(en+1))+1)!=zeros.end()){
            int delone = *ones.lower_bound(en+1) ;
            int delzero = *zeros.lower_bound((*ones.lower_bound(en+1))+1) ;
            ans[iter].pb(*ones.lower_bound(en+1)) ;
            ans[iter].pb(*zeros.lower_bound((*ones.lower_bound(en+1))+1)) ;
            en = *zeros.lower_bound((*ones.lower_bound(en+1))+1) ;
            zeros.erase(delzero) ;
            ones.erase(delone) ;
        }
        iter++ ;
    }
    int cnt = 0 ;
    for(auto v : ans){
        cnt += v.size() ;
    }
    if (cnt != s.size()){
        cout << "-1" << el ;
        return 0 ;
    }
    else{
        int sz = 0 ;
        for(auto v : ans){
            if (v.size()!=0) sz++ ;
        }
        cout <<sz << el ;
        for(auto v : ans){
            if (v.size()==0) continue ;
            cout << v.size() << sp ;
            for(auto it : v){
                cout << it+1 << sp ;
            }
            cout << el ;
        }
    }
    return 0 ;
 }
