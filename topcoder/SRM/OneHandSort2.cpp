
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>


using namespace std ;

#define xx first
#define yy second
#define ll long long
#define el (char)0x0A
#define sp " "
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define MOD 1e9+7

class OneHandSort2 {
	public:
	int minMoves(int N, vector <int> tp, int a, int b) {
		ll t[N] ; 

		set<int> tset ; 
		set<int> negtset ; 
		for(int i = 0 ; i < N ; i++){
			negtset.insert(i) ; 
		}

		for(int i = 0 ; i < tp.size() ; i++){
			t[i] = tp[i] ;
			negtset.erase(t[i]) ;  
		}
		
		cout << el ; 

		int x ; 
		ll aa = a , bb = b ; 
		for(int i = tp.size(); i < N ; i++){
			int tmp = (((ll)t[i-1]*aa)%N + bb)%N ; 
			auto it = negtset.lower_bound(tmp); 

			if (it != negtset.end()){
				x = *it ; 
				t[i] = x ; 
				negtset.erase(*it) ; 
			}

			else{
				it = negtset.lower_bound(0) ; 
				x = *it ; 
				t[i] = x ; 
				negtset.erase(*it) ; 
			}
			

		}
		int rt[N] ; 
		for(int i = 0 ; i < N ; i++){
			rt[t[i]] = i ; 
		}
		
		int idx = 0 ; int ans = 0 ; 
		while (idx < N){
			if (t[idx] == idx){
				idx++ ; continue;
			}
			int endloopidx = t[idx] ;
			int currempty = idx ; 
			int loc = 1;
			while (currempty != endloopidx){
				loc++ ; 
				int tmp = rt[currempty] ;
				t[currempty] = currempty ; 
				rt[currempty] = currempty ; 
				currempty = tmp ; 
			}
			t[endloopidx] = endloopidx ; 
			rt[endloopidx] = endloopidx ; 
			ans += loc+ 1; 
		}
		return ans ; 
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing OneHandSort2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1555519357;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		OneHandSort2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 500000;
				int targetPrefix[] = {0};
				int a = 0 ;
				int b = 0;
				_expected = 3132;
				_received = _obj.minMoves(N, vector <int>(targetPrefix, targetPrefix+sizeof(targetPrefix)/sizeof(int)), a, b); break;
			}
			case 1:
			{
				int N = 4;
				int targetPrefix[] = {2, 3, 0, 1};
				int a = 0;
				int b = 0;
				_expected = 6;
				_received = _obj.minMoves(N, vector <int>(targetPrefix, targetPrefix+sizeof(targetPrefix)/sizeof(int)), a, b); break;
			}
			case 2:
			{
				int N = 10;
				int targetPrefix[] = {3, 7};
				int a = 1664525;
				int b = 1013904223;
				_expected = 11;
				_received = _obj.minMoves(N, vector <int>(targetPrefix, targetPrefix+sizeof(targetPrefix)/sizeof(int)), a, b); break;
			}
			case 3:
			{
				int N = 10;
				int targetPrefix[] = {5, 9, 8, 7, 6, 0, 3};
				int a = 0;
				int b = 1;
				_expected = 13;
				_received = _obj.minMoves(N, vector <int>(targetPrefix, targetPrefix+sizeof(targetPrefix)/sizeof(int)), a, b); break;
			}
			/*case 4:
			{
				int N = ;
				int targetPrefix[] = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.minMoves(N, vector <int>(targetPrefix, targetPrefix+sizeof(targetPrefix)/sizeof(int)), a, b); break;
			}*/
			/*case 5:
			{
				int N = ;
				int targetPrefix[] = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.minMoves(N, vector <int>(targetPrefix, targetPrefix+sizeof(targetPrefix)/sizeof(int)), a, b); break;
			}*/
			/*case 6:
			{
				int N = ;
				int targetPrefix[] = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.minMoves(N, vector <int>(targetPrefix, targetPrefix+sizeof(targetPrefix)/sizeof(int)), a, b); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
