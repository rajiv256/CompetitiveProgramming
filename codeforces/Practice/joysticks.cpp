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
    int a , b ; 
    cin >> a >> b ; 
    int a1 = max(a,b) ; 
    int a2 = min(a,b) ; 
    
    int fl = 0 ; int totmin1 = 0 ;  
        while (true){
            
            if (a1 <= 1 && a2 <= 1){
                break ; 
            }
            else if (a1 <= 1 && a2 > 1){
                fl = 0 ; 
                a1 += 1 ; 
                a2 -= 2 ; 
                totmin1 += 1 ; 
                if (a2 == 0){
                    break ; 
                }
                continue ; 
                     
            }
            else if (a1 > 1 && a2 <= 1){
                fl = 1 ; 
                a1 -= 2 ; a2 += 1 ; 
                totmin1 += 1 ;
                if (a1 == 0){
                    break  ; 
                } 
                continue ; 
            }   
            else{
                int t1 = a1 , t2 = a2 ; 
                a1 = max(t1,t2) ; 
                a2 = min(t1,t2) ; 
                a1 -= 2 ; 
                a2 += 1 ; 
                totmin1 += 1 ; 
                if (a1 == 0){
                    break ; 
                }
                continue ;
            }
        }    
    
    cout << totmin1 << el ; 
    return 0 ; 
    
    
}