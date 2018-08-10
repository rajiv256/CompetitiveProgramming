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
    int n , a , b , T ; 
    cin >> n >> a >> b >> T ; 
    string s ; cin >> s ;
    int fl = 0 ; 
    if (s[0] == 'h'){
        fl = 1 ; 
    }
    
    int p1 = 0 , p2 = 0 ; 
    int t = 0 ; int num = 0 ; 
    p2 = n-1 ; 
    while (num < n  && t < T){
        if (fl == 1){
            while (s[p1]=='h' && num < n && t<T ){
                t += 1 ; 
                num++ ; 
                if (t >= T || num >= n){
                    break ; 
                }
                t += a ; p1++ ; p1 %= n ; 
            }
            if (t >= T || num >= n){
                break ; 
            }
            //cout << num << el ; 
            while (s[p2]=='h' && num < n && t < T){
                t += 1 ; num++ ;
                //cout << s[p2] << sp << t << el ;  
                if (t >= T || num >= n){
                    break ; 
                }
                t += a ; p2-- ; p2 %= n ; 
            }
            if (t >= T || num >= n){
                break ; 
            }
            fl = 0 ; 
            continue ; 
        }
        if (fl == 0){
            while (s[p1]=='w' && t < T && num < n){
                t += b ; 
                if (t >= T){
                    break ; 
                }
                t += 1 ; num++ ; 
                if (t >= T || num >= n){
                    break ; 
                }
                t += a ; p1++ ; p1 %= n ; 
            }
            if (t >= T || num >= n){
                break ; 
            }
            while (s[p2]=='w' && t < T && num < n){
                t += b ; 
                if (t >= T){
                    break ; 
                }
                t += 1 ; num++ ; 
                if (t >= T || num >= n){
                    break ; 
                }
                t += a ; p2-- ; p2 %= n ; 
            }
            if (t >= T || num >= n){
                break ; 
            }
            fl = 1; 
            continue; 
        }
       
    }
     cout << num << el ; 
}