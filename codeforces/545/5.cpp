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

using namespace std ;

#define MOD 1000000007

bool is_set(int x , int bit){
    return ((x&(1<<bit)) == (1<<bit)) ;
}


int main(){
    int persons  ; cin >> persons ;
    map<int,vector<int> > m ;
    for(int i = 0 ; i < persons ; i++){
        int no_of_hats ; cin >> no_of_hats ;
        for(int j = 0 ; j < no_of_hats ; j++){
            int hat ; cin >> hat ;
            m[hat].push_back(i) ;
        }
    }

    int dp[m.size()+2][1026] ;
    memset(dp, 0, sizeof dp) ;

    vector<int> hats ;
    for(auto it: m){
        hats.push_back(it.first) ;
    }
    for(int i = 0 ; i < hats.size() ; i++)
    for(int j = 0 ; j < m[hats[i]].size() ; j++){

        dp[i][1<<(m[hats[i]][j])] = 1 ;
    }

    for(int i = 1; i < hats.size() ; i++){


        cout << "hats[i]: " << hats[i] << endl ;
        for(int j = 0 ; j < 8 ; j++){
            cout << dp[i][j] << " " ;
        }
        cout << endl ;
        for(int j = 0 ; j < m[hats[i]].size() ; j++){
            int curr_person = m[hats[i]][j] ;
            cout << "curr_person: " << curr_person << endl ;
            for(int k = 0 ; k < 8 ; k++){
                if (!is_set(k, curr_person) && (k+(1<<curr_person)) < 8){
                    for(int l = 0 ; l < i ; l++){
                        dp[i][k+(1<<curr_person)] = (dp[i][k+(1<<curr_person)] + dp[l][k]) % MOD ;
                    }
                }
            }
        }
        for(int j = 0 ; j < 8 ; j++){
            cout << dp[i][j] << " " ;
        }
        cout << endl ;
        cout << "-------------" << endl ;
    }
    int ans = 0 ;
    for(int i = 0 ; i < hats.size() ; i++){
        ans += dp[i][(1<<persons)-1] ;
    }

    cout << ans << endl ;

}
