#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace std ; 

int main()  {
	int n ; cin >> n ; 
	vector<int> result ; 
	result.resize(n) ; 
	int i = 0 ; 
	while (i < n){
		cin >> result[i] ; 
		i++ ; 
	}
	i = 0 ; int posses = 0 , missed = 0, max = -1 , count = 0 , dirs = 0; int flag = 0 ;
	vector<int> miss ;  
	do {
	//	cout << posses<<" "<<i <<endl ;
		if (posses == n){
			cout << dirs<<"\n" ; 
			return 0 ;
		}
		if (i >= result.size() && count != n){
			int j ; int maxIndex = -1 ; 
			dirs ++ ;
			for (j = result.size()-1 ; j >= 0 ; j--){
				if (posses >= result[j] && result[j] != -1){
					result[j] = -1 ; 
					maxIndex = j ;
					count++ ; 
					posses ++ ;
					if (posses == n){
						cout << dirs<<"\n" ; 
						return 0 ;
					}	 
				}
			}
		//	cout << maxIndex <<"  $$\n" ; 
			i = maxIndex ; 
			if (posses == n){
				cout << dirs<<"\n" ; 
				return 0 ;
			}
			dirs++ ; 
			continue ;
		}

		if (result[i] == -1){
			i++ ; 
			continue ;
		}
		if (posses >= result[i] && result[i] != -1 ){
			posses += 1 ; 
			count++ ; 
			result[i] = -1;
			i++ ; 
			if (posses == n){
				cout << dirs<<"\n" ; 
				return 0 ;
			}
			continue ; 
		}
		if (posses < result[i]){
			i++ ; 
			continue ;
		}






	}while (posses != n);

	cout << dirs <<"\n" ; 
	return 0 ; 





}