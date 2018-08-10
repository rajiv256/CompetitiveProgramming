#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>

using namespace std ;

typedef vector<int> vi ; 
#define forn(i,n) for (int i = 0 ; i < n ; i++)

int main() {
	int que = 1 ; 
	int day ; int score = 0 ; 
	while (que <= 5){
		cin >> day ; 
		if (day == que){
			score += 100 ; 
			que++ ; 
			continue ;
		} 
		else {
			if (max(0,day-que) == 0){
				que++ ; 
				continue ; 
			}
			else{
				score+= 100-(day-que)*10 ; 
			}
		}
		
		que++ ; 
	}
	cout << score << endl ; 
	return 0 ; 



}
