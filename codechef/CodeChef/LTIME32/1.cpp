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

using namespace std ;
#include <bits/stdc++.h> 
typedef vector<int> vi ; 
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ; 
typedef vector<pair<int,pair<int,int> > > vpp ; 
typedef vector<bool> vb ;
typedef set<int> si ; 
typedef map<int,int> mi ; 
typedef map<int,vector<int> > miv ; 
typedef unsigned long long ull ; 


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pi pair<int,int> 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define LIM 1000000000
#define MXN 100000
#define MOD 1000000007
#define sp " " 
#define el "\n"
#define ll long long 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define sci(x) scanf("%d",&x)
#define mp(a,b) make_pair(a,b)
#define abs(a) (a>0?a:-a)

double distance(double x1 , double y1 , double x2 , double y2){
	return  sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); 
}

bool equals(double d1 , double d2){
	if (d1 > d2){
		if (d1-d2 < 0.000001)
			return true ;
	}
	else {
		if (d2-d1 < 0.000001)
			return true ; 
	}
	return false ; 
}


int main() {
	int id ; cin >> id ; 
	int T ; sci(T) ; 
	while (T--){
		double x1, y1, x2 , y2 , x3 , y3 ; 
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ; 
		vector<double> dist ; dist.rsz(3) ; 
		dist[0] = distance(x1,y1,x2,y2) ; 
		dist[1] = distance(x2,y2,x3,y3) ; 
		dist[2] = distance(x1,y1,x3,y3) ;
		sort(all(dist)) ; 
		int a = dist[0] ; 
		int b = dist[1] ; 
		int c = dist[2] ; 
		cout << a << sp << b << sp << c << el ; 
		if (id == 1){
			if (equals(a,b) || equals(c,b) || equals(c,a)){
				cout << "Isosceles triangle" << el ; 
				continue ; 
			}
			else {
				cout << "Scalene triangle" << el ; 
			}
		}
		if (id == 2){
			if (equals(a,b) || equals(c,b) || equals(c,a)){
				cout <<"Isoceles " ; 
				if (equals(a*a+b*b ,c*c)){
					cout << "right triangle" << el ; 
				}

				else if (a*a+b*b > c*c){
					cout << "acute triangle" << el ; 
				}
				else {
					cout << "obtuse triangle" << el ; 
				}
			}
			else {
				cout << "Scalene " ; 
				if (equals(a*a+b*b, c*c)){
					cout << "right triangle" << el ; 
				}
				else if (a*a+b*b > c*c){
					cout << "acute triangle" << el ; 
				}
				else {
					cout << "obtuse triangle" << el ; 
				}

			}
		}
	
	}
	return 0 ; 
}