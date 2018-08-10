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

using namespace std;

#define ll long long
#define el "\n"

class OrAndSumEasy {
public:
	string isPossible(long long O, long long S) {
        ll A = 0 , B = 0 ; int ch = 0 ;
        for(int bit = 0 ; bit < 63 ; bit++){
            int ob = (O&(1LL<<bit))>>bit ;
            int sb = (S&(1LL<<bit))>>bit ;
			cout << bit << el ;
            if (ob==1){
                if (sb == 0){
                    if (ch == 0){
                        A += (1LL<<bit) ; B += 1LL<<bit ;
                        ch = 1 ;
                    }
                    else{
                        A += (1LL<<bit) ;
                        ch = 1 ;
                    }
                }
                if (sb == 1){
                    if (ch == 0){
                        A += 1<<bit ; ch = 0 ;
                    }
                    if (ch == 1){
                        A += 1LL<<bit ; B += 1LL<<bit ; ch = 1 ;
                    }
                }
            }
            else if (ob == 0){
                if (sb == 0){
                    if (ch == 0){
                        ch = 0 ;
                    }
                    else{
                        return "Impossible" ;
                    }
                }
                if (sb == 1){
                    if (ch == 0){
                        return "Impossible" ;
                    }
                    if (ch == 1){
                        ch = 0 ;
                    }
                }
            }

        }
        cout << A << " " << B << endl ;
        return "Possible" ;

	}
};

int main(){
    OrAndSumEasy oe = OrAndSumEasy() ;
    cout << oe.isPossible(12464276008574679,12464277678038876) << el ;
}
