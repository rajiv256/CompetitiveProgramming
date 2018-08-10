#include<bits/stdc++.h>
using namespace std;

int main(){
	int t ; cin >> t ;
	while (t--){
	int n ; cin >> n ;
	if (n == 1){
		cout << "Kitty\n" ;
		continue ;
	}
	if (n&1){
		cout << "Katty\n" ;
	}
	else{
		cout << "Kitty\n" ;
	}
	}
	return 0 ;
}
