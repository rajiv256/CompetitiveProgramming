// https://www.codechef.com/problems/NPLFLF
// Tags : Trie 

#include <iostream>
 #include <string>
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

bool done[MAXN] ;
 struct Node {
     int npe ;
     int nwe ;
     Node* next[26] ;

     Node(){
         npe = 0 ;
         nwe = 0 ;
         for(int i = 0 ; i < 26 ; i++){
             next[i] = NULL ;
         }
     }
 };
multiset<int> mtp[MAXN] ;
 void addWord(Node* head,int pos, string s, int val){
     if (s.empty()){
         head->nwe += val ;
         return ;
     }
     char c = s[0] ;

     if (head->next[c-'a']==NULL){
         head->next[c-'a'] = new Node() ;
     }

     head = head->next[c-'a'] ;
      multiset<int>:: iterator it = mtp[pos+1].find(head->npe) ;
      if (it != mtp[pos+1].end()){
          mtp[pos+1].erase(it) ;
      }
      mtp[pos+1].insert(head->npe+val) ;
      head->npe += val ;
     s.erase(s.begin()) ;
     addWord(head,pos+1,s,val) ;
 }

bool exists(Node* head, string s){
    if (s.empty()) return true ;
    char c = s[0] ;
    if (head->next[c-'a']==NULL || head->next[c-'a']->npe==0){
        return false ;
    }
    s.erase(s.begin()) ;
    return exists(head->next[c-'a'],s);
}

void remove(Node* head, string s){
    addWord(head,0,s,-1) ;
}
int ans = 0 ;

 int main(){
     ios_base::sync_with_stdio(false) ;
     cin.tie(0) ;
     for(int i = 0 ; i < MAXN ; i++) done[i] = false ;
     int q, type, l , k , x , kase=1 ; string s ;
     cin >> q ;
     Node* root = new Node() ;
     VS v(MAXN,"") ;
     while (q--){
         cin >> type ;
         if (type==1){
             cin >> s ; reverse(all(s)) ;
             v[kase] = s ;
             addWord(root,0,s,1) ;
         }
         if (type==2){
             cin >> k >> l ;
             ans = 0 ;
             if (mtp[l].size()==0){
                 cout << "NO\n" ;
             }
             else{
                 multiset<int>::iterator it = mtp[l].end() ;
                 it-- ;
                 if (*it>=k) cout << "YES\n"  ;
                 else cout << "NO\n" ;
             }
         }
         if (type==3){
             cin >> x ;

             if (!done[x]){
                remove(root,v[x]) ;
                done[x] = true ;
             }
         }
         kase++ ;
     }
 }
