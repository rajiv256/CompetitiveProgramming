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

 int BIT[3030][3030] ;
 int a[1500][1500] ;
 void update(int x, int y, int val){
     x++ ; y++ ;
     for(int i = x ; i < 3030 ; i += (i&-i)){
         for(int j = y; j < 3030  ; j += (j&-j)){
            BIT[i][j] += 1 ;
            BIT[i][j] %= 2 ;
         }
     }
 }
 int query(int x , int y ){
     int sum = 0 ;
     x++ ; y++ ;
     for(int i = x ; i > 0 ; i-=(i&-i)){
         for(int j = y ; j > 0 ; j -= (j&-j)){
             sum += BIT[x][y] ;
         }
     }
     return sum%2 ;
 }
 void update2(int x1, int y1, int x2, int y2){
     update(x1,y1,1) ;
     update(x2+1,y1,1) ;
     update(x1,y1+1,1) ;
     update(x2+1,y2+1,1) ;
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    memset(a,0,sizeof a) ;
    memset(BIT,0,sizeof BIT) ;
    int n ; cin >> n ;
    int arr[n] ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if (arr[i] > arr[j]){
                a[i][j] = 1 ;
                update(i,i,1) ;
            }
        }
    }
    int m ; cin >> m ;
    while (m--){
        int l , r ; cin >> l >> r ;
        l-- ; r-- ;
        update2(l,l,r,r) ;
        int ans = query(n-1,n-1) ;
        if (ans == 0) cout << "even" << el ;
        else cout << "odd" << el ;
    }

 }
