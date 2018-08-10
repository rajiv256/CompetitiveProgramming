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
#define prntv(v) forn(i,v.size()){cout<<v[i]<<sp;}cout<<el
#define mp(a,b) make_pair(a,b)
#define fi(x) x.first
#define se(x) x.second 
#define sci(x) scanf("%d",&x)
#define pii pair<int,int>
#define ff first 
#define ss second 
 
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


int n , w ; 

int stree[MXN] ; 
int A[MXN] ; 

void update(int ss , int se , int qidx , int val , int sidx){
	//cout << ss << sp << se << el ; 
	if (qidx < ss || qidx > se )
		return ; 

	stree[sidx] += val ; 
	if (se != ss){
		int mid = (ss + se)/2 ;  
		update(ss,mid,qidx,val,2*sidx+1) ; 
		update(mid+1,se,qidx,val,2*sidx+2);
	}
}

int query(int ss , int se , int qs ,int qe , int sidx){
	if (ss >= qs  && se <= qe){
		return stree[sidx] ; 
	}
	if (se < qs || ss > qe){
		return 0 ; 
	}
	int mid = (ss + se)/2 ; 
	return (query(ss,mid,qs,qe,2*sidx+1)+query(mid+1,se,qs,qe,2*sidx+2)) ; 
}



int main(){
	int t ; sci(t) ; 
	while (t--){
		memset(A,0,sizeof(A)) ; 
		memset(stree,0,sizeof(stree)) ; 
		sci(n) ; sci(w) ; 
		int x ; 
		int N = 2*n-1 ; 
		forn(i,n){
			sci(x) ;
			A[i] = x ;
			update(0,n-1,i,x,0) ;  
		}
		int q ; sci(q) ; 
		while (q--){
			int ind , color ; 
			sci(ind) ; sci(color) ; 
			ind-- ; 
			int diff = color - A[ind] ; 
			A[ind] = color ; 
			
			update(0,n-1,ind,diff,0) ; 
			
			int res = 0 ; 
			forn(i,n){
				if (i+w-1 < n){
					int k = query(0,n-1,i,i+w-1,0) ; 
					//cout << i << sp << i+w-1 << sp << k << sp << " fleur de lis" << el ; 
					//cout << k << el ; 
					int fl = 0 ;
					forn(u,w){
						if (k != w*A[i+u]){
							fl = 1 ; 
							break ; 
						}
					}
					if (fl == 0){
						res += 1 ; 
					}
				}
			}
			cout << res << el ; 
			
		}	
	}
	return 0 ; 
}