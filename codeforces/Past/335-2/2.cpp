#include <iostream>
#include <vector>
#include <streambuf>
#include <string>
#include <algorithm>
#include <utility>
#include <sstream>

using namespace std;
#define forn(i,n) for(int i = 0 ; i < n ; i++)

pair<int,int> add(char c){
	if (c == 'U'){
		return (make_pair(-1,0));
	}
	if (c == 'D'){
		return (make_pair(1,0));
	}
	if (c == 'L'){
		return (make_pair(0,-1));
	}
	if (c == 'R'){
		return (make_pair(1,0));
	}
}
bool inLimits(int x , int y , int upperx , int uppery){
	if (x == 0 || y == 0 || x > upperx || y > uppery){
		return false ; 
	}
	return true ; 
}

int main() {
	int x , y , xi , yi ; 
	cin >> x >> y >> xi >> yi ; 
	




}