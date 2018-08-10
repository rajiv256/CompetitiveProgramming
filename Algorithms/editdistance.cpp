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
#define INF 10000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()

int L[2003][2003] ; 

int dp(int i1 , int i2 , string s1 , string s2){

	if (i1== 0){
		return i2 ; 
	}
	if (i2 == 0){
		return i1 ; 
	}


	if (L[i1][i2] != -1){
		return L[i1][i2] ; 
	}
	L[i1-1][i2] = dp(i1-1,i2,s1,s2) ;  // delete
	L[i1][i2-1] = dp(i1,i2-1,s1,s2) ;  //insert 
	L[i1-1][i2-1] = dp(i1-1,i2-1,s1,s2) ; //replace
	int temp = min(1+L[i1-1][i2],1+L[i1][i2-1]) ;
	if (s1[i1]==s2[i2]){
		return min(temp,L[i1-1][i2-1]) ; 
	}
	else{
		return min(temp,1+L[i1-1][i2-1]) ; 
	}


}




int main(){
	int t ; cin >> t ; 
	while (t--){
		forn(i,0,2003){
			forn(j,0,2003){
				L[i][j] = -1 ; 
			}
		}

		string s1 ,s2 ; cin >> s1 >> s2 ; 
		s1 = "@"+s1 ; 
		s2 = "@"+s2 ; 
		L[s1.size()-1][s2.size()-1] = dp(s1.size()-1,s2.size()-1,s1,s2) ; 
		cout << L[s1.size()-1][s2.size()-1] << el ; 
	}
}