/*
Public test cases passed. Wrong answer.
*/


#include <iostream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <bits/stdc++.h> 
 
 
using namespace std ;
 
#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp ' '
#define el '\n'
#define ll long long 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define pb push_back
#define MXN 100003 
#define MOD 1000000007
#define prntv(v) forn(i,v.size()){//cout<<v[i]<<sp;}//cout<<el
#define mp(a,b) make_pair(a,b)
#define fi(x) x.first
#define se(x) x.second 
#define sci(x) scanf("%d",&x)
#define pii pair<int,int>
#define ff first 
#define ss second 
#define mem(x,n) memset(x,n,sizeof(x))  

typedef vector<int> vi ; 
typedef vector<char> vc ;
typedef vector<pair<int,int> > vpii ;
typedef vector<pair<ll,ll> > vpll ;
typedef vector<pair<int,pair<int,int> > > vpp ; 
typedef vector<bool> vb ;
typedef set<int> si ; 
typedef map<int,int> mii ; 
typedef map<int,vector<int> > miv ; 
typedef unsigned long long ull ; 

int x , a , b , c ,ans = 0 ; 

mii ma ; mii mb ; mii mc ; 

void reada(vi& A ){
	int temp = a ; 
	while (temp != 0 ){
		ma[temp%10] += 1 ; 
		A.pb(temp%10) ; 
		temp /= 10 ; 
	}
}
void readb(vi& B){
	int temp = b ; 
	while (temp != 0){
		mb[temp%10] += 1 ;
		B.pb(temp%10) ;  
		temp /= 10 ; 
	}
}
void readc(vi& C){
	int temp = c ; 
	while (temp != 0){
		mc[temp%10]+= 1 ;
		C.pb(temp%10) ;  
		temp /= 10 ; 
	}
}

void solve(int idx ,vi& A , vi& B , vi& C, int ca,vvi& sum , vvi& carry){
	if (C.size() > max(A.size(),B.size())+1){
		ans = 0 ; 
		return ; 
	}
	if (idx == C.size()){
		ans += 1 ; 
		return ; 
	}
	//int fl = 0 ; 
	if (idx < min(A.size(),B.size())) {
		for (int i = 0 ; i < x ; i++){
			for (int j = 0 ; j < x ; j++){
				
				if ((i+j+ca)%x == C[idx]){
					
					if (ma[i] != 0 && mb[j] != 0){
						////cout << idx << sp << i << sp << j << el ;
				 		
						ca = (i+j+ca)/x  ; 
						ma[i] -= 1 ; mb[j] -= 1 ; 
						solve(idx+1,A,B,C,ca,sum,carry) ; 
						ma[i] += 1 ; mb[j] += 1 ; 
					}
				}
			}
		}
	}
	
	else if (idx < max(A.size(),B.size())){
		int maxi = max(A.size(),B.size()) ; 
		if (A.size() > B.size()){
			int tmp ; 
			for (mii :: iterator it = ma.begin() ; it != ma.end() ; it++){
				if ((*it).ss > 0){
					tmp = (*it).ff ; 
					if ((tmp+ca)%x == C[idx]){
						ma[tmp] -- ; 
						ca = (tmp+ca)/x ; 
						solve(idx+1,A,B,C,ca,sum,carry) ; 
						ma[tmp]++ ; 
					}
				}


			}
		}
		else if (B.size() > A.size()){
			int tmp ; 
			for (mii :: iterator it = mb.begin() ; it != mb.end() ; it++){
				if ((*it).ss > 0){
					tmp = (*it).ff ; 
					if ((tmp+ca)%x == C[idx]){
						mb[tmp] -- ; 
						ca = (tmp+ca)/x ; 
						solve(idx+1,A,B,C,ca,sum,carry) ; 
						mb[tmp]++ ; 
					}
				}
			}
		}
		
	}
	else if (idx == max(A.size(),B.size())){
		if (C[idx] == ca){
			solve(idx+1,A,B,C,0,sum,carry) ; 
		}
	}

	return ; 
}





int main(){
	int t ; sci(t) ; 
	while (t--){
		sci(x) ; sci(a) ; sci(b) ; sci(c) ; 
		
		ma.clear() ; mb.clear() ; mc.clear() ; 
		vi A , B , C ; 
		reada(A) ; readb(B) ; readc(C)  ; 
		vi v ; vvi sum(x,v) ; vvi carry(x,v) ; 
		forn(i,x){
			forn(j,x){
				sum[i].pb((i+j)%x) ; 
				carry[i].pb((i+j)/x) ; 
			}
		}
		
		ans = 0 ; 
 
		solve(0,A,B,C,0,sum,carry) ; 
		 
		cout << ans << el ; 
		
	}
}