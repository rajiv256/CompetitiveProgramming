/* Resilience is the corner stone for success. */
// SRM 232 Div1 A
// Trie

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
 #define INF (int)1E9+1
 #define MOD (int)1E9+7
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

struct Node {
    int x, y ;
    struct Node* next[26] ;

    Node(){
        x = INF ;
        y = INF ;
        for(int i = 0 ; i < 26 ; i++){
            next[i] = NULL ;
        }
    }
};

void addWord(Node* head, string s, PII st){

    if (s.empty() || s.size()==0){

        if (mp(head->x,head->y)>st){
            head->x = st.xx ;
            head->y = st.yy ;
        }

        return ;

    }

    char c = s[0];

    if (head->next[c-'A']==NULL){
        head->next[c-'A'] = new Node() ;
    }


    s = s.substr(1,s.size()) ;
    addWord(head->next[c-'A'],s,st) ;
}

pair<int,int> findWord(Node* head, string s){
    if (s.empty()){
        return mp(head->x,head->y) ;
    }
    char c = s[0] ;
    if (head->next[c-'A']==NULL){
        return mp(INF,INF) ;
    }

    s = s.substr(1,s.size()) ;
    return findWord(head->next[c-'A'],s) ;
}

class WordFind {
public:
    bool valid(int x , int y, int X, int Y){
        if (x>=0 && y>=0 && x<X && y<Y) return true ;
        return false ;
    }
	vector <string> findWords(vector <string> grid, vector <string> wordList) {
        Node* root = new Node() ;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){

                string s = "" ; int len = 1 ;
                int x = i ; int y = j ;
                while (valid(x+len-1,y,grid.size(),grid[i].size())){

                    
                    s += grid[x+len-1][y] ;
                    addWord(root,s,mp(x,y)) ;
                    len++ ;
                }

                s = "" ; len = 1 ;
                while(valid(x,y+len-1,grid.size(),grid[i].size())){

                    s += grid[x][y+len-1] ;
                    addWord(root,s,mp(x,y)) ;
                    len++ ;
                }

                s = "" ; len = 1 ;
                while (valid(x+len-1,y+len-1,grid.size(),grid[i].size())){

                    s += grid[x+len-1][y+len-1] ;
                    addWord(root,s,mp(x,y)) ;
                    len++ ;
                }

            }
        }
        vector<string> ans ;
        for(int i = 0 ; i < wordList.size() ; i++){
            string s = wordList[i] ;
            pair<int,int> p = findWord(root,s) ;
            if (p==mp(INF,INF)){
                ans.pb("") ;
            }
            else{
                string fi = to_string(p.xx) ;
                string se = to_string(p.yy ) ;
                ans.pb(""+fi+" "+se) ;
            }
        }
        return ans ;
	}
};


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    WordFind wf = WordFind() ;
    vector<string> grid ;
    grid.pb("TEST") ;grid.pb("BOAT") ;  grid.pb("GOAT") ;
    vector<string> wordList ;
    wordList.pb("GOAT") ; wordList.pb("BOAT") ; wordList.pb("TEST") ;
    vector<string> ans = wf.findWords(grid,wordList) ;

    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << el ;
    }
 }
