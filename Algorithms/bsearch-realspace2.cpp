// BINARY SEARCH + COMPOUND INTEREST + FIND MONTHLY PAYMENT



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

#define ld long double
using namespace std;


class Mortgage {
public:
	long double pred(long double p, long double mp, long double mip, long double t){

		for(int i = 0 ; i < t ; i++){
			p -= mp ;
			p *= 1.0+mip ;
			p = ceil(p) ;
		}
		return p ;

	}
	int monthlyPayment(int loan, int interest, int term) {
		long double lo = 0 ; long double hi = loan+5.0 ;  int nt = 0 ;
		while (lo < hi){
			if (nt == 200){
				break ;
			}
			nt++ ;
			long double mid = lo + (hi-lo)/2 ;
			long double val = pred((ld)loan, mid ,((ld)interest)/(120.0*100.0+1e-12), (ld)term*12.0) ;

			if (abs(val)<=1e-12){
				return ceil(mid) ;
			}
			if (val < 0){
				hi = mid-1e-12 ;
			}
			if (val >1e-12){
				lo = mid+1e-12 ;
			}
		}
		cout << lo << endl ;
		return ceil(lo);
	}
};
