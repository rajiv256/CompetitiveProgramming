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
#define ll long long

using namespace std;


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    int t ; cin >> t ;
    while (t--){
        ll N , C ; cin >> N >> C ;
        ll X[N] ;
        //memset(X,0,sizeof(X)) ;
        for(int i = 0 ; i < N ; i++){
            cin >> X[i] ;
        }
        sort(X,X+N) ;
        ll lo = 0 ;
        ll hi = (int)1E9 ;
        while (lo < hi){
            ll mid =lo + (hi-lo+1)/2 ;
            ll nocc = 1 ;
            ll currpos = X[0] ;
            for(int i = 1 ; i < N ; i++){
                if (X[i]-currpos >= mid){
                    currpos = X[i] ;
                    ++nocc ;
                }
            }
            if (nocc < C){
                hi = mid-1 ;
            }
            else{
                lo = mid ;
            }
        }
        cout << lo << endl ;
    }
    return 0 ;
}
