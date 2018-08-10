#include <iostream>
#include <algorithm>
#include <vector> 
#include <utility>

using namespace std ; 


int main() {

	vector<double> times(5,0.0) ;
	

	vector<int> wrongs(5,0) ; 
	 

	vector<double> scores(5,0.0) ;
	
	int hs , hu ; 

	int i = 0 ; 
	for (i = 0 ; i < 5 ; i++){
		scores[i] = (500.0)*(i+1) ; 
		cin >> times[i] ; 
	}
	for (i = 0 ; i < 5 ; i++){
		cin >> wrongs[i] ; 
	}
	cin >> hs ; 
	cin >> hu ; 

	double score = 0 ; 
	for (i = 0 ; i < 5 ; i++){

		score += max(((double)0.3*scores[i]),(double)(1.0 - (double)(times[i]/250.0))*scores[i] - 50.0 * wrongs[i]); 


	}
	int s = (int) score ;  
	s += hs*100 - hu*50 ; 
	cout << s << "\n" ; 
	return 0 ; 
}