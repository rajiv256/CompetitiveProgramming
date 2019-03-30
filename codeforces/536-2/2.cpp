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
#define MAXN 100005
#define mp make_pair
#define ll long long

using namespace std ;

ll rem[MAXN], cost[MAXN]  ;
ll ndishes[MAXN] , dish[MAXN] ;

int main(){
    int n , m ; cin >> n >> m ;
    for(int i = 0 ; i < n ; i++){
        cin >> rem[i] ;
    }
    for(int i = 0 ; i < n ; i++){
        cin >> cost[i] ;
    }
    for(int i = 0 ; i < m ; i++){
        cin >> dish[i] >> ndishes[i] ;
    }

    priority_queue<pair<int,int> , vector<pair<int,int> > > pq ;
    for(int i = 0 ; i < n ; i++){
        pq.push(mp(-cost[i], i)) ;
    }
    for(int j = 0 ; j < m ; j++){
        ll tj = dish[j] ; tj-- ;
        ll dj = ndishes[j] ;

        if (dj  <= rem[tj]){
            ll ans  = 0  ;
            rem[tj] -= dj ;
            ans += dj*cost[tj] ;
            cout << ans << endl ;
            dj = 0 ;
        }
        else{
            ll ans = 0 ;
            dj -= rem[tj] ;
            ans += rem[tj]*cost[tj] ;
            rem[tj] = 0 ;

            while (!pq.empty() && dj != 0){
                pair<int,int> p = pq.top() ;
                while(!pq.empty() && rem[p.second]==0){
                    pq.pop() ;
                    p = pq.top() ;
                }
                if (pq.empty()){
                    break ;
                }
                p = pq.top() ;
                if (dj <= rem[p.second]){
                    rem[p.second] -= dj ;
                    ans += dj*(-p.first) ;
                    dj = 0 ;
                    break ;
                }
                else{
                    dj -= rem[p.second] ;
                    ans += rem[p.second]*(-p.first) ;
                    rem[p.second] = 0 ;
                    pq.pop() ;

                }

            }
            if (dj != 0){
                cout << 0 << endl ;
            }
            else{
                cout << ans << endl ;
            }
        }
    }



}
