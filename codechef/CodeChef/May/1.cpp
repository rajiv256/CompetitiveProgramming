#include <bits/stdc++.h>
using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mi ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pi pair<int,int>
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el "\n"
#define ll long long
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x)
#define MXN 1000003
#define gc getchar_unlocked

int main(){
    int t ; sci(t) ;
    while (t--){
        int n ; sci(n) ; string s ; cin >> s ;
        int score = 0 ;
        for(int i = 0 ; i < n ; i++){
            string s1 ; cin >> s1 ;

            if (s1.find("WON")!=std::string::npos){
                score += 300 ;
                int rank ; cin >> rank ;
                score += max(0,20-(rank)) ;
            }
            if (s1.find("TOP")!=string::npos){
                score += 300 ;
            }
            if (s1.find("BUG")!=string::npos){
                int sev ; cin >> sev ;
                score += (sev) ;
            }
            if (s1.find("HOST")!=string::npos){
                score += 50 ;
            }
        }
        int ans ;
        if (s == "NON_INDIAN"){
            ans = score/400 ;
        }
        else{
            ans = score/200 ;
        }
        cout << ans << el ;
    }

}