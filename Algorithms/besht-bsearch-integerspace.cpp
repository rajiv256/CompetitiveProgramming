// Tags : binary-search, topcoder, properties of an array
// SRM 277 Div2 C


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ll long long
using namespace std;


class UnionOfIntervals {
public:
	int nthElement(vector <int> lB, vector <int> uB, int n) {

       	if (n == 0){
       		return lB[0] ;
       	}

        ll lo = (ll)-2E9-1 ; ll hi = (ll)2E9+1 ; ll mid=0 ;
        while (lo < hi){
            mid = lo+(hi-lo)/2 ;

			// gt ==> No.of elements mid is strictly greater than.
			// gte ==> No.of elements mid is greater than or equal to.
            ll gt = 0 ; ll gte = 0 ;
			for(int i = 0 ; i < lB.size() ; i++){
				int sz = uB[i]-lB[i]+1 ;
				if (mid >= uB[i]){
					gt += sz-(int)(mid==uB[i]) ;
					gte+= sz ;
				}
				if (mid >= lB[i] && mid < uB[i]){
					gt += mid-lB[i] ;
					gte += mid-lB[i]+1 ;
				}
			}
			// There should be atleast "n" elements which are strictly less than mid or greater than "n" elements which are >= mid.
			// Then only mid can be in the index (n).
			if (gt <= n && gte>n){
				return mid ;
			}
			// If mid is greater than more than "n" elements, then obviously the element at "nth" index will be strictly less than mid.
			else if (gt > n){
				hi = mid-1 ;
			}
			// If mid is greater than or equal to less than "n" elements, It cannot be in the Nth index. Therefore.
			// Ex : 1 1 2 2 2  3 3 4 4 4. Find the element at the 5th index.
			// As we can see if mid is 2, then gte=5 until the last 2. However "3" is our required answer.
			else if (gte <= n){
				lo = mid+1 ;
			}
        }
		return lo ;
	}

};
int main(){

	vector <int> p0;
	vector <int> p1;
	int p2;
	int p3;

	int t0[] = {19999999};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {20000000};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	p3 = 6;
	UnionOfIntervals uoi = UnionOfIntervals() ;
	int x = uoi.nthElement(p0,p1,0) ; // Should return 19999999
	cout << x << endl ;
}
