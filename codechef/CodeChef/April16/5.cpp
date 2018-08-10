#include <bits/stdc++.h>

using namespace std ; 

#define ll long long 
#define sp " " 
#define el endl 
#define sci(x) scanf("%d",&x)
#define MAXN 100009 
#define MOD 1000000007

ll a[MAXN] ;
ll BIT[MAXN] ; 
int n , m ; 
ll ans = 0 ; 

void update(int idx , ll val){
    
    while (idx <= n){
        BIT[idx] += val ; 
        idx += (idx&-idx) ; 
    }
}

ll query(int idx){
    ll sum = 0 ; 
    while (idx >0){
        sum += BIT[idx] ;
        sum %= MOD ;  
        idx -= (idx&-idx) ; 
    }
    return sum ; 
}



ll fib(ll n){
    
    if (n == 1){
        return 1 ; 
    }
    if (n == 0){
        return 0 ; 
    }
    if (n == 2){
        return 2 ; 
    }
    ll k = n/2 ; 
    if (n&2){
        ll k1 = fib(k-1) ; ll k2 = fib(k+1) ; ll k3 = fib(k) ; 
        return (((k1*k3)%MOD + (k2*k3)%MOD)%MOD) ;  
    }
    else{
        ll k1 = fib(k) ; ll k2 = fib(k-1) ; 
        return (((k1*k1)%MOD + (k2*k2)%MOD)%MOD) ; 
    }
}




int main(){
    sci(n) ; sci(m) ; 
    for(int i = 0 ; i < n ; i++){
        scanf("%lld",&a[i]) ;  
    }
    memset(BIT,0,sizeof(BIT)) ; 
    for(int i = 0 ; i < n ; i++){
        update(i+1,a[i]) ; 
    }
    char c ; int  x , y ; 
    for(int i = 0 ; i < m ; i++){
        cin >> c >> x >> y ; 
         
        if (c=='C'){
            update(x,y) ; 
            a[x-1] = y ; 
        }
       
        if (c=='Q'){
            ans = 0 ; 
            calc(x,y) ; 
        }
    }
    return 0 ; 
    
    
}