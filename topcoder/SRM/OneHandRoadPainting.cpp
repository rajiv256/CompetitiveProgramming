
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
class OneHandRoadPainting {
	public:
	long long fastest(vector <int> dStart, vector <int> dEnd, int paintPerBrush) {
		
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
		cout << "Testing OneHandRoadPainting (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1556120618;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		OneHandRoadPainting _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dStart[] = {3, 7};
				int dEnd[] = {4, 9};
				int paintPerBrush = 1;
				_expected = 42LL;
				_received = _obj.fastest(vector <int>(dStart, dStart+sizeof(dStart)/sizeof(int)), vector <int>(dEnd, dEnd+sizeof(dEnd)/sizeof(int)), paintPerBrush); break;
			}
			case 1:
			{
				int dStart[] = {3, 7};
				int dEnd[] = {4, 9};
				int paintPerBrush = 5;
				_expected = 18LL;
				_received = _obj.fastest(vector <int>(dStart, dStart+sizeof(dStart)/sizeof(int)), vector <int>(dEnd, dEnd+sizeof(dEnd)/sizeof(int)), paintPerBrush); break;
			}
			case 2:
			{
				int dStart[] = {1, 10, 20};
				int dEnd[] = {4, 13, 22};
				int paintPerBrush = 2;
				_expected = 98LL;
				_received = _obj.fastest(vector <int>(dStart, dStart+sizeof(dStart)/sizeof(int)), vector <int>(dEnd, dEnd+sizeof(dEnd)/sizeof(int)), paintPerBrush); break;
			}
			/*case 3:
			{
				int dStart[] = ;
				int dEnd[] = ;
				int paintPerBrush = ;
				_expected = LL;
				_received = _obj.fastest(vector <int>(dStart, dStart+sizeof(dStart)/sizeof(int)), vector <int>(dEnd, dEnd+sizeof(dEnd)/sizeof(int)), paintPerBrush); break;
			}*/
			/*case 4:
			{
				int dStart[] = ;
				int dEnd[] = ;
				int paintPerBrush = ;
				_expected = LL;
				_received = _obj.fastest(vector <int>(dStart, dStart+sizeof(dStart)/sizeof(int)), vector <int>(dEnd, dEnd+sizeof(dEnd)/sizeof(int)), paintPerBrush); break;
			}*/
			/*case 5:
			{
				int dStart[] = ;
				int dEnd[] = ;
				int paintPerBrush = ;
				_expected = LL;
				_received = _obj.fastest(vector <int>(dStart, dStart+sizeof(dStart)/sizeof(int)), vector <int>(dEnd, dEnd+sizeof(dEnd)/sizeof(int)), paintPerBrush); break;
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
