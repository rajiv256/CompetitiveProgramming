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
 
 
struct st
{
	int l,b;
} ar[100000];
 
struct stt
{
	int l,b;
} arr[100000];
 
int bb[100000];
 
bool operator <(st a, st b)
{
	if(a.l==b.l) return a.b<b.b; return a.l<b.l;
}
 
bool operator <(stt a, stt b)
{
	if(a.b==b.b) return a.l<b.l; return a.b<b.b;
}
 
int main()
{
	for(int i=0;i<100000;i++) bb[i]=1;
	int ntc; scanf("%d",&ntc);
	while(ntc--)
	{  
		int n,m; sci(n); sci(m);
		bb[0]=1;
		ll x , y ; 
		for(int i=0;i<n;i++) 
		{
			scanf("%lld%lld",&x,&y) ; 
			ar[i].l=x;ar[i].b=y;
			arr[i].l=ar[i].l;arr[i].b=ar[i].b;	
		}
	long long area=0;
	long long l; long long b;
		sort(ar,ar+n);
		sort(arr,arr+n);
		if(m==n) m--;
		int tt=m;
		
		for(int i=0;i<=m  ;++i)
		{
			
			l=ar[i].l;
			b=arr[tt].b;
			long long atmp=l*b;
			if(atmp>area) area=atmp;
			stt num; num.l=l; num.b=ar[i].b; 
			int pos=upper_bound(arr,arr+n,num)-arr-1;
			
			if(pos>tt) --tt;
			else bb[pos]=0;
			while(bb[tt]==0) 
			{
			bb[tt]=1 ;--tt;
			}
			
		}
		
		printf("%lld\n",area);
		
		
	}
}
 