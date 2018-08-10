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

 typedef struct Node {
     int cnt ;
     struct Node* left ;
     struct Node* right ;
 }Node ;

 Node* newNode(){
     Node* node = (Node*)malloc(sizeof(Node)) ;
     node->cnt = 0 ; node->left = NULL ; node->right = NULL ;
     return node ;
 }

 Node* root ;

 void addNode(int x){
     Node* troot = root ;
     for(int i = 30 ; i >= 0 ; i--){

         int bit =(x&(1<<i))>>i ;
         if (bit){
             if (troot->right == NULL){
                 troot->right = newNode()  ;
             }
             troot->right->cnt += 1 ;
             troot = troot->right ;
         }
         else{
             if (troot->left == NULL){
                 troot->left = newNode()  ;
             }
             troot->left->cnt += 1 ;
             troot = troot->left ;
         }
     }
 }
 int getP(int a){
     int p = 0 ;
     Node* ptr = root ;
     for(int i = 30 ; i >= 0 ; i--){

         int abit = (a&(1<<i))>>i ;
         //cout << i  << sp << abit << el ;
         if (abit == 1){
             if (ptr->right != NULL && ptr->right->cnt!=0){
                 p |= (1<<i) ;
                 ptr->right->cnt-- ;
                 ptr = ptr->right ;

             }
             else{
                 ptr->left->cnt--  ;
                 ptr = ptr->left ;
             }
         }
         if (abit == 0){
             //cout << "here" << el  ;
             if (ptr->left!= NULL && ptr->left->cnt != 0){
                 //cout << "but not here" << el ;
                 ptr->left->cnt-- ;
                 ptr = ptr->left ;
             }
             else{
                 //cout << "here??? :O" << el ;
                 p |= (1<<i) ;
                 ptr->right->cnt-- ;
                 ptr = ptr->right ;
             }
         }
     }
     return p ;
 }


 const int N = 4*MAXN ;
 int A[N] ;
 int P[N] ;


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n ; cin >> n ;
    root = newNode() ;

    for(int i = 0 ; i < n ; i++){
        cin >> A[i]  ;
    }


    for(int i = 0 ; i < n ; i++){
        cin >> P[i] ;
        addNode(P[i])  ;
    }


    for(int i = 0 ; i < n ; i++){
        int ans = (A[i]^(getP(A[i]))) ;
        cout << ans  << " " ;
    }
    cout << el ;
    return 0 ;

 }
