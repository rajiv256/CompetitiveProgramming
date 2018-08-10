// Implemetation, Greedy. 
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


int main(){
    int m , s; sci(m) ; sci(s); 
    int a1[m] ; 
    int a2[m] ; 
    memset(a1,0,sizeof(a1)) ; 
    memset(a2,0,sizeof(a2)) ; 
    if (m == 1 && s == 0){
        cout << "0 0" << el ; 
        return 0 ; 
    }
    if (s < 1 || s > 9*m){
        cout << "-1 -1" << el ; 
        return 0 ; 
    }
    
    int sum1 = s ; int sum2 = s ; 
    forn(i,m){
        if (sum1 <= 0){
            continue ; 
        }
        if (sum1 >9){
            sum1 -= 9 ; 
            a1[i] = 9 ; 
        }
        else if (sum1 <= 9){
            a1[i] = sum1 ;
            sum1 = 0 ; 
             
        }
    }
    sum2 -= 1 ; a2[0] = 1 ; 
    for(int i = m-1 ; i>= 0 ; i--){
        if (sum2 <= 0){
            continue ; 
        }
        if (sum2<= 9){
            a2[i]+= sum2 ;
            sum2 = 0 ; 
        }
        else if (sum2 > 9){
            sum2 -= 9 ; 
            a2[i] = 9 ;  
        }
    }   
    forn(i,m){
        cout << a2[i]  ; 
    } 
    cout << sp ;
    forn(i,m){
        cout << a1[i] ; 
    }
    cout << el ; 
    return 0 ; 
     
}