#include <bits/stdc++.h> 

using namespace std ;

typedef vector<int> vi ; 
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ; 
typedef vector<pair<int,pair<int,int> > > vpp ; 
typedef vector<bool> vb ;
typedef set<int> si ; 
typedef map<int,int> mii ; 
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

int main(){
    map<int,int> mp ; 
    int n , m ; sci(n) ; sci(m) ; 
    int a ; 
    forn(i,n){
        sci(a) ; mp[a] = 1 ; 
    }
    
    int sum = m ; int num = 1 ; int cnt = 0 ; vi v ; 
    while (sum > 0 && num <= 1000000000){
        if (mp[num] == 0){
            if (sum < num){
                break ; 
            }
            else{
                sum -= num ;
                v.pb(num) ; 
                num += 1 ; 
                continue ; 
            }
        }
        else{
            num += 1 ; 
        }
    }
    cout << v.size() << el ; 
    if (sum > 0 && v.size()!=0){
        for(int i = sum ; i > 0 ; i--){
            if (mp[v[v.size()-1]+i] == 0){
                v[v.size()-1] += i ; 
                break ; 
            }
        }
    }
    forn(i,v.size()){
        cout << v[i] << sp ; 
    }
    return 0 ; 
}