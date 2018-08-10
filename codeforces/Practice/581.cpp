// i am rajiv
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

int a[100005] ; 


int main(){
    int n , k ; 
    memset(a,0,sizeof(a)) ; 
    sci(n) ; sci(k) ; 
    forn(i,n){
        sci(a[i]) ; 
    }
    int diff[n] ; 
    forn(i,n){
        diff[i] = 10-(a[i]%10) ; 
    }
    sort(diff,diff+n) ; 
    int sum = 0 ; 
    forn(i,n){
        sum += a[i]/10 ; 
    }
    forn(i,n){
        if (diff[i] == 10){
            break ; 
        }
        k -= diff[i] ; 
        if (k < 0){
            break ; 
        }
        sum += 1; 
    }
    int presum = 0 ; 
    forn(i,n){
        if (a[i]%10 == 0)
            presum += a[i] ; 
        else  
            presum += (a[i]/10+1)*10 ; 
    }
    
    while(presum < 100*n && k > 0){
        presum += 10 ; k -= 10 ; 
        if (presum > 100*n){
            break ; 
        }
        if (k < 0){
            break ; 
        }
        sum += 1 ; 
    }
    
    cout << sum << el ; 
    return 0  ;
}