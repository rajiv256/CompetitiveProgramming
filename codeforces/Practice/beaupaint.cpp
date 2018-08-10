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

int a[1005] ; 
int L[1005] ; 

void lis(int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if (a[j] < a[i]){
                if (L[i] < L[j]+1){
                    L[i] = L[j] + 1 ; 
                }
            }
        }
    }
}




int main(){
    int n ; cin >> n ; 
    memset(a,0,sizeof(a)) ; 
    map<int,int> m ; 
    forn(i,n){
        cin >> a[i] ;
        m[a[i]] += 1 ;  
    }
    sort(a,a+n) ;  int sum = 0 ; 
    while (true){
        int temp = 0 ; 
        for(map<int,int> :: iterator it = m.begin() ; it != m.end() ; it++){
            if ((*it).yy != 0){
                temp += 1; 
                (*it).yy -= 1 ; 
            }
        }
        if (temp == 0){
            break ; 
        }
        sum += temp-1 ; 
    }
    cout << sum << el; 
    return 0 ; 
    
}