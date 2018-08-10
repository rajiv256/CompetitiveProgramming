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
 const int N = 100050 ;
 typedef struct node {
     char c ;
     struct node* left ;
     struct node* right ;
     int minp, minm , maxp , maxm ;
     node(char c , struct node* l , struct node* r, int val){
         c = c ;
         l = left ;
         r = right ;
         minp = maxp = minm = maxm = val ; 
     }
 }node ;
 string s ;
 node* dandc(int lo, int hi,int level){
     if (lo == hi){
         return new node(s[lo],NULL,NULL,s[lo]-'0') ;
     }

     for(int i = lo ; i <= hi ; i++){
         if (s[i]=='(') level++ ;
         if (s[i]==')') level-- ;
         if (s[i]=='?' && level==1) {
             node* left = dandc(lo,i-1,0) ;
             node* right = dandc(i+1,hi,0) ;
             node* curr = new node('?',left,right,-1) ;
             return curr ;
         }
     }
     return NULL ;
 }

 void solve()









 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    node* root = dandc(0,s.size()-1,0) ;
 }
