#include <bits/stdc++.h> 
using namespace std ; 

#define ll long long 
#define el endl 
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100003 
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()

//////////////////
int main(){
	int64_t b , d , s ; cin >> b >> d >> s ; 
	int64_t ans = 4e18; 
	if ((b==1&&d==0&&s==0)||(b==0&&d==1&&s==0)||(b==0&&d==0&&s==1) || ((b==1&&d==1&&s==0) ||(b==0&&d==1&&s==1)||(b==1&&d==0&&s==1))){
		cout <<"0\n" ; 
		return 0 ; 
	}
	int64_t ar[8] = {0,0,1,0,2,1,1,0} ; 
	int64_t de[8] = {0,2,1,1,0,1,0,0} ; 
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			int64_t x = b-(i&1)-(j&1) ; 
			int64_t y = d-((i&2)>>1)-((j&2)>>1) ; 
			int64_t z = s-((i&4)>>2)-((j&4)>>2) ; 
			if (x <0 || y <0 || z<0){
				continue ; 
			}
			//cout << x << sp << y << sp << z << sp <<ar[i] << sp <<de[j] << el ; 
			ans = min(ans,3*max(x,max(y,z))-(x+y+z)+ar[i]+de[j]) ; 
		}
	}
	cout << ans << el ;  
}