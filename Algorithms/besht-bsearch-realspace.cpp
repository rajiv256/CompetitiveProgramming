// BINARY SEARCH + COMPOUND INTEREST + FIND MONTHLY INTEREST RATE
// SRM 258 Div1 A
// Max number of iterations required for a real number binary search is 100.
// The value should be around 1E-12 of the required value.

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
#define el "\n"
#define forn(i,x,y) for(int i = x ; i < y ; i++)
using namespace std;


class AutoLoan {
public:
    long double  pow(long double  a , int x){
        if (x == 0) return 1.0  ;
        if (x == 1) return a    ;
        long double  t = pow(a,x/2) ;
        return (t*t)*(pow(a,x&1)) ;
    }
    long double  pred(long double  p, long double  mir, long double  mp,long double  t){
        forn(i,0,t){
            p *= 1+mir ;
            p -= mp ;
        }
        return p ;
    }
    long double  bsearch(long double  p, long double  mp, long double  t, long double  st, long double  en, int nt){
       long double  mir = (st)+(en-st)/2.0 ;

     	if (nt == 100){
     		return mir ;
     	}
        if (st > en){
            return 1e-12;
        }

        long double  val = pred(p,mir,mp,t) ;

        if (abs(val)<=1e-12){
            return mir ;
        }
        else if (val<0){
            return bsearch(p,mp,t,mir,en,nt+1) ;
        }
        else if (val >1e-12){
            return bsearch(p,mp,t,st,mir,nt+1) ;
        }
        return 1e-12 ;

    }
    long double  interestRate(long double  price, long double  monthlyPayment, int loanTerm) {
        return 1200.000*bsearch(price,monthlyPayment,loanTerm,0.0,1.0,0) ;
	}
};
int main(){

    AutoLoan al = AutoLoan() ;
    cout << 1200*al.interestRate(2000,510,4) << el ;

}
