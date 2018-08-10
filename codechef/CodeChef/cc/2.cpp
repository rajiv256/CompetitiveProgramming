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
    while(t--){
        int h , m ; 
        sci(h) ; sci(m) ;
        int cnt = 0 ;  
        for(int i = 1 ; i <= 9 ; i++){
           if (i < h && i < m){
               cnt += 1;  
           }
           if (i < h && i*11 < m){
               cnt += 1 ; 
           }
           if (i*11 < h && i*11 < m){
               cnt += 1 ; 
           } 
           if (i*11 < h && i < m){
               cnt += 1 ; 
           }
        }
        cnt += 1 ;  
        cout << cnt << el ; 
    }
}