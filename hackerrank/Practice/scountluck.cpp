#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>


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
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp " " 
#define el "\n"
#define ll long long int 
#define sci(x) scanf("%d",&x)

int main(){
    int n ,k ; 
    sci(n) ; sci(k) ; 
    vi v(n) ; 
    forn(i,n){
        sci(v[i]) ; 
    }
    sort(all(v)) ;
    int cnt = 0 ;  
    forn(i,n){
        int n1  = v[i] ; 
        int n2 = k - v[i] ; 
        if (binary_search(all(v),n2)){
            pair<vector<int>::iterator,vector<int>::iterator> p = equal_range(all(v),n2); 
            cnt += p.second-p.first ; 
        }
    }
    cout << cnt << el ; 
    return 0 ; 
}