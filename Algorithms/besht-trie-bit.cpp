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
 #define SZ(C) sizeof(C)/sizeof(C.at(0))
 #define all(x) (x).begin(),(x).end()
 #define clr(x) memset((x),0,sizeof(x))
 #define uint unsigned int
 #define abs(x) ((x<=0)?(-x):(x))
 #define MAXN 100005
 #define INF (int)1E10+1
 #define MOD (int)1E9+7
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

struct Node {
    int cnt ;
    Node* next[2] ;

    Node() {
        cnt  = 0 ;
        next[1] = NULL ; next[0] = NULL ;
    }
};

void addI(Node* head, int num, int toAdd){

    // Fixing the number of bits to consider will simplify the problem and remove any possibe errors.
    // Basically all leaf nodes will be at the same depth.
    for(int i = 28 ; i >= 0 ; i--){
        int bit = (num>>i)&1 ;
        if (head->next[bit]==NULL){
            head->next[bit] = new Node() ;
        }
        head = head->next[bit] ;
        head->cnt += toAdd ;
    }
    return ;
}

ll query(Node* head, int P, int L){       // Should we use Li or Li-1 since it should always be  greater
    ll ret = 0 ;

    for(int i = 28 ; i >= 0 ; i--){
        if (head == NULL){
            return ret ;
        }
        bool pbit = (P>>i)&1 ;
        bool lbit = (L>>i)&1 ;

        if (lbit){
            if (pbit){
                ret += (head->next[1]==NULL)?0:head->next[1]->cnt ;
                head = head->next[0] ;
            }
            else{
                 ret += (head->next[0]==NULL)?0:head->next[0]->cnt ;
                head = head->next[1] ;
            }
        }
        else{
            head = head->next[pbit] ;
        }
    }
    return ret ;
}

int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int q ; cin >> q ;
    int type,p, l ;
    Node* head = new Node() ;
    while (q--){
        cin >> type ;

        if (type == 1){
            cin >> p ;
            addI(head,p,1) ;
        }
        if (type == 2){
            cin >> p ;
            addI(head,p,-1) ;
        }
        if (type==3){
            cin >> p >> l  ;
            ll ans = query(head,p,l) ;
            cout << ans << el ;
        }
    }
}
