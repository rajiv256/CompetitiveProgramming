
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

#define mm 100
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
    int n ; sci(n) ; 
    ll a[n] ; 
    forn(i,n){
       cin >> a[i] ;  
    }
    ll sum = 0 ;
    forn(i,n){
        sum += a[i] ; 
    }
    if (sum == 0){
        ll cnt = 0 ; 
        forn(i,n){
            if (a[i]==0){
                cnt += 1 ; 
            }
            else{
                ll temp = 0 ;
                temp += a[i] ; 
                while(temp != 0){
                    i++ ; 
                    temp += a[i] ; 
                }
                cnt += 1 ;     
            }
        }
        cout << ((cnt)*(cnt-1))/2 - (cnt-1) << el ; 
        return 0 ;  
    }
    ll temp1 = 0 ; int bp1 = -1 ; 
    for(int i = 0 ; i < n-2 ; i++){
        temp1 += a[i] ; 
        if (temp1 == sum/3){
            bp1 = i ; 
            break ;
        }
    }
    if (bp1 == -1){
        cout << "0" << el ; 
        return 0 ; 
    }
    ll temp2 = 0 ; int bp2 = -1 ; 
    for(int i = bp1+1 ; i < n-1 ; i++){
        temp2 += a[i] ; 
        if (temp2 == sum/3){
            bp2 = i ; 
            break ; 
        }
    }
    if (bp2 == -1){
        cout << "0" << el ; 
        return 0 ; 
    }
    ll nz1 = 0 ; ll nz2 = 0 ; 
    for(int i = bp1+1 ; i <= bp2 ; i++){
        if (a[i] != 0){
            break ; 
        }
        nz1++ ; 
    }
    for(int i = bp2+1;i < n ; i++){
        if (a[i] != 0)
            break ;
        nz2++ ;  
    }
    cout << (nz1+1)*(nz2+1) << el ; 
    return 0 ; 
}
