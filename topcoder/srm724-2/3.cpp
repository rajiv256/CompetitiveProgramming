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
#define pb push_back
#define el "\n"
#define sp " "

class UnfinishedTournamentEasy {
public:
	double maximal(vector <string> G) {
        int n = G.size() ;
        char a[n][n] ;
        char b[n][n] ;
        for(int r = 0 ; r < n ; r++){
            for(int c = 0 ; c < n ; c++){
                a[r][c] = G[r][c] ;
                b[r][c] = a[r][c] ;
            }
        }
        double ans = 0.0 ;
        double curmean = 0.0 ;
        vector<double> R ;
        for(int i = 0 ; i < n ; i++){
            double wins = 0 ; double cnt = 0 ;
            for(int j = 0 ; j < n ; j++){
                if (a[i][j]=='W'){
                    wins += 1 ; cnt += 1 ;
                }
                if (a[i][j] == 'L') cnt += 1 ;
            }
            if (cnt == 0){
                R.pb(0) ;
            }
            else{
                R.pb(wins/cnt) ;
            }
        }
        for(int i = 0 ; i < n ; i++){
            curmean += R[i] ;
        }
        curmean /= n ;
        cout << curmean << el ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if (b[i][j] == '?'){
                    if (R[i] >= R[j]){
                        b[i][j] = 'W' ;
                        b[j][i] = 'L' ;
                    }
                    else{
                        b[i][j] = 'L' ;
                        b[j][i] = 'W' ;
                    }
                }
            }
        }
        vector<double> R1;
        for(int i = 0 ; i < n ; i++){
            double wins = 0 ; double cnt = 0 ;
            for(int j = 0 ; j < n ; j++){
                if (b[i][j]=='W'){
                    wins += 1 ; cnt += 1 ;
                }
                if (b[i][j] == 'L') cnt += 1 ;
            }
            if (cnt == 0){
                R1.pb(0) ;
            }
            else{
                R1.pb(wins/cnt) ;
            }
        }
        double mean = 0.0 ;
        for(int i = 0 ; i < R1.size() ; i++){
            mean += R1[i] ;
        }
        mean /= n ;
        double var = 0 ;
        for(int i = 0 ; i < n ; i++){
            var += (mean-R1[i])*(mean-R1[i]) ;
        }
        var /= n ;
        return var ;

	}
};

int main() {
	bool all_right;
	all_right = true;

	vector <string> p0;
	double p1;
    string t0[] = {"-WWL","L-WW","LL-?","WL?-"};
	p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));

    UnfinishedTournamentEasy uf = UnfinishedTournamentEasy() ;
    cout << uf.maximal(p0) << el ;

}
