/* Resilience is the greatest of all virtues */
/* Code by rajiv */

 // tags : BFS
 // We need to maintain two queues essentially.
 // 1. To check if the node is already completed.
 // 2. To check if the node is present in the queue before adding it to the queue. (This might not be needed in some cases, When the graph is very dense, this might come in handy as the first time you add the node will be the minimum depth of that node. )

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
 #include <iterator>

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
 #define MAXN 100005
 #define INF (int)1E10+1
 #define MOD (int)1E9+7
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 class SmartWordToy {
 public:
    vector<string> combs(vector<string>& v){
        VS ret ;
        //cout << v[0] << sp << v[1] << sp << v[2] << sp << v[3] << el ;
        for(int i0 = 0 ; i0 < v[0].size() ; i0++){
            for(int i1 = 0 ; i1 < v[1].size() ; i1++){
                for(int i2 = 0 ; i2 < v[2].size() ; i2++){
                    for(int i3 = 0 ; i3 < v[3].size() ; i3++){
                        string s = "aaaa" ;
                        s[0] = v[0][i0] ; s[1] = v[1][i1] ; s[2] = v[2][i2] ; s[3]= v[3][i3] ;
                        ret.pb(s) ;
                    }
                }
            }
        }
        return ret ;
    }
    int hash1(string s){   // Wrong answer maybe because of collisions.
        int M = 991793 ;
        int p = 953 ;
        int M2 = 991793 ;
        int p2 = 739 ;
        ll ans1 = (ll)s[0]+1  ;
        ll ans2  = (ll)s[0] ;
        for(int i = 1 ; i < s.size() ; i++){
            ans1 = (ans1*p)%M + (int)s[i] ;
            ans2 = (ans2*p2)%M2 + (int)s[i] ;
        }
        return ((ans1+2)+(ans2+1))%929983  ;

    }
    int bfs(string s, string en , VS& nopes){
        bool mInq[26][26][26][26] ;  // in queue
        bool mVis[26][26][26][26] ;  // is visited
        memset(mInq,false,sizeof(mInq)) ;
        memset(mVis,false,sizeof(mVis)) ;

        queue<pair<string,int> > q ;
        q.push(mp(s,0)) ;
        while (!q.empty()){

            pair<string,int> p = q.front() ;
            q.pop() ;

            string s = p.xx ;
            int d = p.yy ;

            if (binary_search(all(nopes),s)){
                if (s == en){return -1 ;}
                continue ;
            }


            if (s == en){
                return d ;
            }
            if (mVis[s[0]-'a'][s[1]-'a'][s[2]-'a'][s[3]-'a']==true){
                continue ;
            }
            mVis[s[0]-'a'][s[1]-'a'][s[2]-'a'][s[3]-'a'] = true ;


            string newstr = s ;
            int inc[2] = {-1,1} ;
            for(int i = 0 ; i < 4 ; i++){
                for(int j = 0 ; j < 2 ; j++){
                    newstr = s ;
                    newstr[i] = 'a'+(((s[i]-'a')+inc[j]+26)%26) ;
                    if (!mInq[newstr[0]-'a'][newstr[1]-'a'][newstr[2]-'a'][newstr[3]-'a'] && !mVis[newstr[0]-'a'][newstr[1]-'a'][newstr[2]-'a'][newstr[3]-'a']){
                        q.push(mp(newstr,d+1)) ;
                        mInq[newstr[0]-'a'][newstr[1]-'a'][newstr[2]-'a'][newstr[3]-'a'] = true ;
                    }
                }
            }
        }
        return -1 ;
    }


 	int minPresses(string start, string finish, vector <string> forbid) {
        set<string> nopeset ;

        cout << forbid.size() << el;
        for(int i = 0 ; i < forbid.size() ; i++){
            istringstream iss(forbid[i]) ;
            vector<string> res((istream_iterator<string>(iss)),istream_iterator<string>()) ;
            vector<string> res1 = combs(res) ;
            for(auto it : res1){
            	nopeset.insert(it) ;
            }

        }
        vector<string> nopes = vector<string>(all(nopeset)) ;

        sort(all(nopes)) ;
        int ret = bfs(start,finish,nopes) ;
        return ret ;
 	}
 };


 int main(){
     ios_base::sync_with_stdio(false) ;
     cin.tie(nullptr) ;

    string p0;
	string p1;
	vector <string> p2;
	int p3;


	// ----- test 0 -----
	p0 = "aaaa";
	p1 = "mmnn";
	string t2[] =  {"a a a z","a a z a","a z a a","z a a a","a z z z","z a z z","z z a z","z z z a"};
	p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    class SmartWordToy swt = SmartWordToy() ;
    int ans = swt.minPresses(p0,p1,p2) ;
    cout << ans << el ;
 }
