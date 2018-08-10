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
 
int main(){
    int t ; sci(t) ; 
    while (t--){
        string a , b ; 
        cin >> a >> b ;
        
        if (a.size()==1){
            if (a[0] != b[0]){
                puts("Unlucky Chef"); 
                
            }
            else{
                puts("Lucky Chef"); 
                cout << "0\n" ;  
            }
            continue ; 
        }
        
        ll cz=0 , co = 0 ,wz=0 , wo=0; 
        forn(i,a.size()){
            if ((a[i]=='0') && (b[i]=='0')){
                cz += 1; 
            }
            if ((a[i]!='0') && (b[i]=='0')){
                wo += 1; 
            }
            if ((a[i]=='0') && (b[i]!='0')){
                wz += 1; 
            }
            if ((a[i]!='0') && (b[i]!='0')){
                co += 1; 
            }
        }
        if (wz==wo){
            puts("Lucky Chef") ; 
            printf("%lld\n",wo) ; 
            continue; 
        }
        if (wz < wo){
            if (cz+wz==0){
                puts("Unlucky Chef") ; 
                continue ; 
            }
            puts("Lucky Chef"); 
            ll cnt = wo; 
            printf("%lld\n",cnt) ; 
            continue ; 
        }
        if (wo < wz){
            ll cnt = 0 ; 
            if (wz==1){
                if (co>0){
                    puts("Lucky Chef") ; 
                    printf("1\n"); 
                    continue ; 
                }
                else if (cz > 1){
                    puts("Lucky Chef"); 
                    printf("1\n") ; 
                    continue ; 
                }
                else if (cz<=1){
                    puts("Unlucky Chef") ; 
                    continue ; 
                }
            }
            cnt = 0 ; 
            cnt += wo ; 
            wz -= wo ; 
            cnt += wz/2 ; 
            if (wz%2==1){
                cnt += 1; 
            }
            puts("Lucky Chef") ; 
            printf("%lld\n",cnt) ; 
            continue ; 
        }
    }
} 
