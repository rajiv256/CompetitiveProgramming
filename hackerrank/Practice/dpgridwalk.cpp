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
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp " " 
#define el "\n"
#define ll long long int 
#define sci(x) scanf("%d",&x)

ll L[103][103][103][103][103][103][103][103][103][103] ; 
int pos[13] ; 
int maxD[103] ;  

ll nways(int x0,int x1,int x2,int x3,int x4,int x5,int x6,int x7,int x8,int x9,int nrem){
    if (nrem == 0){
        return 0 ;
    }
    if (x0 < 0 || x0 >= maxD[0] ){
        return 0 ; 
    }
    if (x1 < 0 || x0 >= maxD[1] ){
        return 0 ; 
    }
    if (x2< 0 || x0 >= maxD[2] ){
        return 0 ; 
    }
    if (x3 < 0 || x0 >= maxD[3] ){
        return 0 ; 
    }
    if (x4 < 0 || x0 >= maxD[4]){
        return 0 ; 
    }
    if (x5 < 0 || x0 >= maxD[5] ){
        return 0 ; 
    }
    if (x6 < 0 || x0 >= maxD[6] ){
        return 0 ; 
    }
    if (x7 < 0 || x0 >= maxD[7] ){
        return 0 ; 
    }
    if (x8 < 0 || x0 >= maxD[8] ){
        return 0 ; 
    }
    if (x9 < 0 || x0 >= maxD[9] ){
        return 0 ; 
    }
    if (L[x0][x1][x2][x3][x4][x5][x6][x7][x8][x9] != -1){
        return ((L[x0][x1][x2][[x3][x4][x5][x6][x7][x8][x9]) ; 
    }
    ll res = 0 ; 
    ll x = L[x0+1][x1][x2][x3][x4][x5][x6][x7][x8][x9] = nways(x0+1,x1,x2,x3,x4,x5,x6,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0-1][x1][x2][x3][x4][x5][x6][x7][x8][x9] = nways(x0-1,x1,x2,x3,x4,x5,x6,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1+1][x2][x3][x4][x5][x6][x7][x8][x9] = nways(x0,x1+1,x2,x3,x4,x5,x6,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1-1][x2][x3][x4][x5][x6][x7][x8][x9] = nways(x0,x1-1,x2,x3,x4,x5,x6,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2+1][x3][x4][x5][x6][x7][x8][x9] = nways(x0,x1,x2+1,x3,x4,x5,x6,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2-1][x3][x4][x5][x6][x7][x8][x9] = nways(x0,x1,x2-1,x3,x4,x5,x6,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3+1][x4][x5][x6][x7][x8][x9] = nways(x0,x1,x2,x3+1,x4,x5,x6,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3-1][x4][x5][x6][x7][x8][x9] = nways(x0,x1,x2,x3-1,x4,x5,x6,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3][x4+1][x5][x6][x7][x8][x9] = nways(x0,x1,x2,x3,x4+1,x5,x6,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3][x4-1][x5][x6][x7][x8][x9] = nways(x0,x1,x2,x3,x4-1,x5,x6,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3][x4][x5+1][x6][x7][x8][x9] = nways(x0,x1,x2,x3,x4,x5+1,x6,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3][x4][x5-1][x6][x7][x8][x9] = nways(x0,x1,x2,x3,x4,x5-1,x6,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3][x4][x5][x6+1][x7][x8][x9] = nways(x0,x1,x2,x3,x4,x5,x6+1,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3][x4][x5][x6-1][x7][x8][x9] = nways(x0,x1,x2,x3,x4,x5,x6-1,x7,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3][x4][x5][x6][x7+1][x8][x9] = nways(x0,x1,x2,x3,x4,x5,x6,x7+1,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3][x4][x5][x6][x7-1][x8][x9] = nways(x0,x1,x2,x3,x4,x5,x6,x7-1,x8,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3][x4][x5][x6][x7][x8+1][x9] = nways(x0,x1,x2,x3,x4,x5,x6,x7,x8+1,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3][x4][x5][x6][x7][x8-1][x9] = nways(x0,x1,x2,x3,x4,x5,x6,x7,x8-1,x9,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3][x4][x5][x6][x7][x8][x9+1] = nways(x0,x1,x2,x3,x4,x5,x6,x7,x8,x9+1,nrem-1) ; 
    res += x ; 
     x = L[x0][x1][x2][x3][x4][x5][x6][x7][x8][x9-1] = nways(x0,x1,x2,x3,x4,x5,x6,x7,x8,x9-1,nrem-1) ; 
    res += x ; 
    return res ; 
}



int main(){
    int t ; cin >> t ; 
    while (t--){
        int n , m ; cin >> n >> m  ;
        memset(pos,-1,sizeof(pos)) ; 
        memset(maxD,-1,sizeof(maxD)) ; 
        int x0 = -1 , x1 = -1 , x2 = -1 , x3= -1 , x4 = -1 , x5 = -1 , x6 = -1 , x7 = -1 , x8 = -1 , x9 = -1 ; 
        forn(i,n){
            sci(pos[i]) ;
            pos[i]-- ;  
        }
        forn(i,n){
            sci(maxD[i]) ; 
            maxD[i]-- ;
        }
        x0 = pos[0] ; x1= pos[1] ; x2= pos[2] ; x3=pos[3]; x4=pos[4] ; x5=pos[5] ; x6=pos[6] ; x7=pos[7]; x8=pos[8];
        x9=pos[9] ; 
        ll ans = nways(x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,m); 
        
    }
}