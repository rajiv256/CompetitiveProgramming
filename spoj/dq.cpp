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
int occur[1000009] ; 

typedef struct query{
	int idx ; 
	int l , r ; 
}query;



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
int BLOCK = 1 ; 
bool cmp(query q1 , query q2){
	if (q1.l/BLOCK  != q2.l/BLOCK){
		return (q1.l/BLOCK < q2.l/BLOCK) ; 
	}
	else{
		return (q1.r < q2.r) ; 
	}
}



int main(){
	int n ; sci(n) ;BLOCK = sqrt(n) ;  
	memset(occur,0,sizeof(occur)) ; 
	int a[n]  ; memset(a,0,sizeof(a)) ; 
	forn(i,n){
		sci(a[i]) ; 
	}
	int d ;sci(d) ;  query qs[d] ;  int it = 0 ;
	while (it < d){
		int a , b ; sci(a) ; sci(b) ; a-- ; b-- ;  
		qs[it].l = a ; qs[it].r = b ; qs[it].idx =  it ; 
		it++ ; 
	}
	sort(qs,qs+d,cmp) ; vp ans ; 
	int st = 0 ; int en = 0  ; int curr = 0 ;  
	for(int i = qs[0].l; i <= qs[0].r ; i++){
		if (occur[a[i]]==0){
			curr++ ; 
		}
		occur[a[i]]++ ; 
	}
	
	st = qs[0].l ; en = qs[0].r ;  
	ans.pb(mp(qs[0].idx, curr)) ; 
	
	for(int i = 1 ; i < d ; i++){
		int left = qs[i].l ; int right = qs[i].r ; 
		
		while (st < left){
			
			if (occur[a[st]]==1){
				curr-- ; 
			}
			occur[a[st]]--; 
			st++ ;
			 
		}
		while (st > left){
			st-- ; 
			if (occur[a[st]]==0){
				curr++ ; 
			}
			occur[a[st]]++ ;
			
		}
		while (en < right){
			en++ ; 
			if (occur[a[en]]==0){
				curr++ ; 
			}
			occur[a[en]]++ ;
			
		}
		while (en > right){
			 
			if (occur[a[en]]==1){
				curr-- ; 
			}
			occur[a[en]]-- ;
			en-- ;
		}
		ans.pb(mp(qs[i].idx,curr)) ; 
		
	}
	sort(all(ans)) ; 
	forn(i,ans.size()){
		printf("%d\n",ans[i].yy) ; 
	}
	return 0 ; 
	
}
