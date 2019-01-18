/* I solemnly swear that I am upto no good. */
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
 #define MAXN 100005
 #define INF (int)1E10+1
 #define MOD (int)1E9+7
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 // Note : Add '$' to the pat.
 // F[0] and F[1] = 0 : as we won't get any proper prefixes and suffixes for s[0..i-1] until the length is 3. 
 // F[i] : Index in the pattern to go to if the match fails at i-th index. This is also equal to the length of the 
 //        proper-prefix that is also a suffix of the substring pat[0..i-1] inclusive. 
 //       
 int F[20*MAXN] ;
 void build_failure_function(string pat){
     F[0] = 0 ; F[1] = 0 ;

     for(int i = 2 ; i < pat.size() ; i++){
         int j = F[i-1] ;
         if (pat[i-1] == pat[j]){
             F[i] = j+1 ;
         }
         else{
             while (j > 0){
                 j = F[j] ;
                 if (pat[i-1] == pat[j]){
                     F[i] = j+1 ;
                     break ;
                 }
             }
         }
     }
 }
 bool KMP(string s , string pat){
     if (s.size()==0 || pat.size()==0){
         return false ;
     }
     int i = 0 ; int j = 0 ;
     while (i < s.size()){
         if (s[i]==pat[j]){
             i++ ; j++ ;
             if (j == pat.size()) return true ;
         }
         else{
             int temp = j ;
             j = F[j] ;
             while (j > 0){
                 if (s[i]==pat[j]){
                     i++ ; j++ ; break ;
                 }
                 j = F[j] ;
             }
             if (j == 0){
                 i = i-temp+max(1,F[temp]) ;
             }
         }

     }
     return false ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    memset(F,0,sizeof(F)) ;
    string pat ; cin >> pat  ;
    if (pat.size()<=2){
        cout << "Just a legend" << el ;
        return 0 ;
    }

    pat += '$' ;

    build_failure_function(pat) ;
    int len = F[pat.size()-1] ;

    string req = pat.substr(0,len) ;
    pat.erase(pat.begin()) ;
    pat.erase(pat.end()-2) ;

    int fl = 0 ;

    while (req.size()!=0 || len > 0){
        if (KMP(pat,req)){
            fl = 1 ;
            cout << req << el ;
            break ;
        }
        memset(F,0,sizeof(F)) ;
        req += '$';
        build_failure_function(req) ;
        len = F[req.size()-1] ;
        req = req.substr(0,len);
    }
    if (fl == 0){
        cout << "Just a legend" << el ;
    }




    return 0 ;
 }
