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
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el endl
#define ll long long
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define MXN 100003
#define MOD 1000000007
#define gc getchar_unlocked	
 
 
void sci(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
 
typedef struct node {
	int rem0 ; 
    int rem1 ; 
    int rem2 ; 
	
	void merge(node n1,node n2){
        rem0 = n1.rem0 + n2.rem0 ;
        rem1 = n1.rem1 + n2.rem1 ;
        rem2 = n1.rem2 + n2.rem2 ;
 
    }	
    void rotate(){
        int temp = rem0 ; 
        rem0 = rem2 ; 
        rem2 = rem1 ; 
        rem1 = temp ; 
    }
    void drotate(){
        int temp = rem0 ; 
        rem0 = rem1 ; 
        rem1 = rem2 ; 
        rem2 = temp ; 
    }
}node ; 
 
node stree[4*MXN] ; 
int lazy[4*MXN] ; 
int a[MXN] ; 
 
 
void build(int st , int en , int s){
    //cout << st << sp << en << el  ; 
    if (st > en){
        return  ; 
    }
    if (st==en){
        if (a[st]%3==0){
            stree[s].rem0 = 1 ; 
            stree[s].rem1 = 0 ; 
            stree[s].rem2 = 0 ; 
        }
        if (a[st]%3==1){
            stree[s].rem0 = 0 ; 
            stree[s].rem1 = 1 ; 
            stree[s].rem2 = 0 ; 
        }
        if (a[st]%3==2){
            stree[s].rem0 = 0 ; 
            stree[s].rem1 = 0 ; 
            stree[s].rem2 = 1 ; 
        } 
        return ; 
    }
    int mid = (st+en)/2 ; 
    build (st, mid,2*s) ; 
    build(mid+1,en, 2*s+1) ; 
    stree[s].merge(stree[2*s],stree[2*s+1]) ; 
}
void update(int st , int en , int l , int r , int s){
    
    if (lazy[s] != 0){
        if (st != en){
                lazy[2*s] += lazy[s] ; lazy[2*s] %= 3 ; 
                lazy[2*s+1] += lazy[s] ; lazy[2*s+1] %= 3 ; 
        }
        if (lazy[s]==1){
            stree[s].rotate() ; 
        }
        if (lazy[s]==2){
            stree[s].drotate() ; 
        }
        lazy[s] = 0  ; 
 
    }
 
 
 
    if ((st > r) || (en < l)){
        return ; 
    }
    
    if ((st >= l) && (en <= r)){
 
        stree[s].rotate() ; 
        if (st != en){
            lazy[2*s] = (lazy[2*s]+1)%3 ; 
            lazy[2*s+1]= (lazy[2*s+1]+1)%3 ; 
        }
 
        return ; 
    }
    int mid = (st+en)/2 ;
 
    update(st,mid,l,r,2*s) ; 
    update(mid+1,en ,l,r,2*s+1) ; 
    stree[s].merge(stree[2*s], stree[2*s+1]) ; 
    return ; 
}
 
node query(int st , int en , int l , int r , int s){
    
    if (lazy[s] != 0){
        if (st != en){
                lazy[2*s] += lazy[s] ; lazy[2*s] %= 3 ; 
                lazy[2*s+1] += lazy[s] ; lazy[2*s+1] %= 3 ; 
            }
             
        if (lazy[s]==1){
            stree[s].rotate() ; 
        }
        if (lazy[s]==2){
            stree[s].drotate() ; 
        }
        lazy[s] = 0  ;
    }
 
 
    if ((st > r) || (en < l)){
        node n ; n.rem0 = 0 ; n.rem1 = 0; n.rem2 = 0 ; 
        //cout << st << sp << en << sp << n.rem0 << el ; 
        return  n ;  
    }
    
    if ((st >= l) && (en <= r)){
        return stree[s] ; 
    }
    int mid = (st+en)/2 ; 
    
 
    node n1  = query(st, mid , l , r, 2*s) ; 
    node n2 =  query(mid+1, en , l , r, 2*s+1) ; 
    node ret ;  
    ret.merge(n1,n2) ; 
    return ret ; 
}
 
int main(){
    int n , q ; sci(n) ; sci(q) ; 
    memset(a,0,sizeof(a)) ; 
    memset(stree,0,sizeof(stree)) ; 
    memset(lazy,0,sizeof(lazy)) ; 
    build (0,n-1,1) ; 
 
    int fl , A , B ; 
    while (q--){
        
        sci(fl) ; sci(A) ; sci(B) ; 
        if (fl){
            node ans = query(0,n-1,A,B,1) ; 
            cout << ans.rem0 << el; 
        }
        else{
            update(0,n-1,A,B,1) ; 
        }
    }
}
 
 
 