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
#define ull unsigned long long
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
//#define sci(x) scanf("%d",&x)
#define MXN 100003
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
ull pow(ull a , ull b){
    if(b==0){
        return 1 ;  
    }
    ull temp = pow(a,b/2) ;
    if (b%2==0){
         
        return temp*temp ;
    }
    return a*temp*temp ; 
    
}


ull a[24] ; 
ull digits[24] ; 

int main(){
    int t ; sci(t) ;
    a[1] = 5 ; a[2] = 20 ; 
    for(int i = 3 ; i < 24  ; i++){
        a[i]= a[i-1]*5 ; 
    }
     
    a[0] = 0 ; 
    while (t--){
        ull  k ; cin >> k ; 
        int nd = 0 ; 
        ull num = 0 ;
        forn(i,24){
            digits[i] = 7 ;
        }
        
        while (num < k){
            num += a[nd] ;
            //cout << num <<sp << k << el ; 
            //cout << nd << el ; 
            nd++ ; 
        }
        //cout << "came here" << el;
        int fl = 0 ; 
        if (num==k){
            nd-- ; 
            forn(i,nd){
                cout << "8" ; 
            }
            cout << el ;
            continue ; 
        }
        
        else{
            nd-- ; 
            num -= a[nd] ; 
            //cout << k << sp << num << el; 
            ull rem = k-num ; 
            if (nd==1){
            	cout << 2*(rem-1) << el ; 
            	continue ; 
            }
            ull temp = pow(5,nd) ; 

            //cout << rem << sp << nd << el ; 
            for(int dig = 0 ; dig < nd ; dig++){
                 temp /= 5 ; 
            	for(int number = 0 ; number <= 8 ; number+=2){
                    if (dig==0 && number==0 && nd!=1){
                        continue ; 
                    }
                    
                    if (rem > temp){
                        rem -= temp ; 
                        continue ; 
                    }
                    if (rem == temp){
                        digits[dig] = number ; 
                        for(int i = dig+1 ; i < nd ; i++){
                            digits[i] = 8 ; 
                        }
                        fl = 1  ; 
                        break ; 
                    }
                    if (rem < temp){
                    	digits[dig] = number ; 
                        break ; 
                    }
                }
                if (fl==1){
                    break ; 
                }
            }
        }
        forn(i,nd){
            cout <<digits[i] ; 
        }
        cout << el ; 
           
    }
}



















