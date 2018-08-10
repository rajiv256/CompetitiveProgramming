/* http://codeforces.com/contest/869/problem/E
   2D BIT
   -> Range update and Point query
   - Pair is used to account for randomisation.(read the problem and solution)
*/
/*
        Code written by rajiv.
        God speed!
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <sys/time.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <cmath>
#include <iterator>
#include <ctime>
using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define sclf(x) scanf("%lf",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100005
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ;


pair<ll,ll> BIT[2507][2507] ;

int N , M , Q ;

pair<ll,ll> query(int x, int y){
	pair<ll,ll> val = mp(0,0) ;
	for(int i = x; i > 0 ; i-=(i&-i)){

		for(int j = y ; j > 0 ; j-=(j&-j)){
			val.xx += BIT[i][j].xx ;
			val.yy += BIT[i][j].yy ;
		}

	}
	return val ;
}

void update(int x , int y , pair<ll,ll> val){
	for(int i = x ; i <= 2504 ; i+=(i&-i)){
		for(int j = y ; j <= 2504 ; j += (j&-j)){
			BIT[i][j].xx += val.xx ;
			BIT[i][j].yy += val.yy ;
		}
	}
	return ;
}


void update2DBIT(int x1 , int y1, int x2, int y2, pair<ll,ll> val){

	pair<ll,ll> mval = mp(-val.xx,-val.yy) ;
	update(x1,y1,val) ;
	update(x2+1,y1,mval) ;
	update(x1,y2+1,mval) ;
	update(x2+1,y2+1,val) ;
}

int main(){
	srand(time(NULL)) ;

	cin.tie(0) ;
	ios_base::sync_with_stdio(false) ;

	cin >> N >> M >> Q ;
	memset(BIT,0,sizeof(BIT)) ;

	int t , x1 , y1, x2, y2 ;
	map<pair<int,pair<int,pair<int,int> > >,pair<ll,ll> > m ;
	while (Q--){
		cin >> t >> x1 >> y1 >> x2 >> y2 ;


		if (t == 1){
			// Using rand() instead of 1 because, the values of the cells in two non-overlapping rectangles should be different and if we keep the // value as 1 then the answer could be that we can travel between two cells in two non-overlapping rectangles. s
			m[mp(x1,mp(y1,mp(x2,y2)))] = mp(rand()%10000009,rand()%10000009) ;

			update2DBIT(x1,y1,x2,y2,m[mp(x1,mp(y1,mp(x2,y2)))] ) ;
		}
		if (t == 2){

			pair<ll,ll> val = m[mp(x1,mp(y1,mp(x2,y2)))] ;
			pair<ll,ll> mval = mp(-val.xx,-val.yy) ;

			update2DBIT(x1,y1,x2,y2,mval ) ;


		}
		if (t == 3){
			// Since this is a point query range update.
			pair<ll,ll> ans1 = query(x1,y1) ;
			pair<ll,ll> ans2 = query(x2,y2) ;
			//cout <<"just killed a man! "<< ans1.xx << sp << ans1.xx << sp << ans2.xx << sp << ans2.yy << el ;
			if (ans1.xx==ans2.xx && ans1.yy==ans2.yy){
				cout << "Yes" << el ;
			}
			else{
				cout << "No" << el ;
			}
		}

	}
}
