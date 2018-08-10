#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a , b ; 
	cin >> a >> b ; 
	int res = a-b ; 
	if (res %10 == 0){
		res += 1 ; 
	}
	else if (res %10 == 1){
		res += 1 ; 
	}
	else {
		res -= 1 ; 
	}
	cout << res << endl ; 
	return 0 ;  
}
