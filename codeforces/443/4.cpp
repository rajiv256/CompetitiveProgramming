/* 
        Code written by rajiv. 
        God speed!
*/
#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define sclf(x) scanf("%lf",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100005
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 
typedef pair<int,int> pii ; 

using Pair = std::pair<ll, ll>;


long long GetSize(const std::deque<Pair> &a) {
  return std::accumulate(a.begin(), a.end(), 0,
                         [](long long s, const Pair &x)
                         {return s + x.second;});
}


int main(){ 
    ios_base::sync_with_stdio(false) ; 
    cin.tie(nullptr) ; 
    cout.tie(nullptr) ; 

    ll n,m, k ; 
    cin >> n >> k >> m ; 
    ll x ; 
    deque<pair<ll,ll> > dq ; 
    forn(i,0,n){
        cin >> x ; 
        if (dq.empty() || dq.back().xx != x){
            dq.push_back(mp(x,1)) ; 
        }
        else{
            ++dq.back().yy ; 
            
            if ((dq.back().yy%=k)==0){
                dq.pop_back() ; 
            } 
        }
    } 

    ll Y = GetSize(dq) ; 
   // cout<<Y<<el ; 

    while (dq.size()>1 && dq.front().xx==dq.back().xx){
        if ((dq.front().yy = (dq.front().yy+dq.back().yy)%k)==0){
            dq.pop_front() ; 
        }
        dq.pop_back() ; 
    }

    ll X = GetSize(dq); 

    if (dq.size()==0){
        cout << 0 << el ; 
    }
    if (dq.size()==1){
        ll e = (dq.front().yy*m)%k ; 
        if (e == 0){
            cout << 0 << el ; 
        }
        else{
            e = e+Y-X ; 
            cout << e << el ;    
        }
    }
    if (dq.size()>1){
        cout << (m-1)*X + Y << el ; 
    }

    return 0 ; 


}