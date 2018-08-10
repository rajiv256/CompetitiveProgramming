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
typedef vector<vector<pair<int,int> > > vvp ;

#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> > 
#define MOD 1000000007
#define MXN 100005
#define sp " " 
#define el "\n"
#define ll long long int 
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x) 
#define mysqrt(n) (int)(sqrt(n))
#define printv(v,sz) forn(i,sz){cout<<v[i]<<sp;}cout<<el 

int L[13] ; 

ll pow(ll a , ll b){
    if (b == 0){
        return 1 ; 
    }
    return a*pow(a,b-1) ; 
}




long long sum(long long N){
    if(N/10==0) return N*(N+1)/2;
    int i=0;
    long long n=N;
    while(n/10!=0){
        i++;
        n/=10;
    }
    int p=pow(10,i);
    return ((n*45*i*p/10)+ n*(n-1)*p/2+ n*(N%p+1) + sum(N%p));
}

int main(){
    int a , b ; 
    cin >> a >> b ; 
    while (a != -1 && b != -1){
       ll ans = sum(b)-sum(a-1) ;
       cout << ans << el ; 
       cin >> a >> b ;  
    }
}