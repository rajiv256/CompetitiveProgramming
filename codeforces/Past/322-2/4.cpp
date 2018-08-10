#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <cmath>

using namespace std; 
typedef vector<int> vi ; 

#define forn(i,n) for (int i = 0 ;i < n ; i++)
#define vp vector<pair<int,int> >


void print (int x1,int y1,pair<int,int> f ,int x2,int y2,pair<int,int> s ,int x3,int y3,pair<int,int> t,int side){
		vector<char> vc(side,'~') ; 
		vector<vector<char> >  L (side,vc) ; 
		//cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl ; 
		
		//cout << f.first << " " << f.second << " " << s.first << " " << s.second << " " << t.first << " " << t.second << endl ; 
		for (int i = 0 ; i < f.second ; i++){
			for (int j = 0 ; j < f.first ; j++){
				L[i+x1][j+y1] = 'A' ; 
			}
		}
		//cout << "A done\n" ; 
		for (int i = 0 ; i < s.second ; i++){
			for (int j = 0  ; j < s.first ; j++){
				L[i+x2][j+y2] = 'B' ; 
			}
		}
		//cout << "B done\n" ; 
		//cout << t.second << " " << t.first << endl ; 
		for (int i = 0; i < t.second ; i++){
			for (int j = 0 ; j < t.first ; j++){
				L[i+x3][j+y3] = 'C' ; 
			}
		}
		//cout << "C done\n" ; 
		cout << side << endl ; 
		for (int i = 0 ; i < side ; i++){
			for (int j = 0 ; j < side ; j++){
				cout << L[i][j] ; 
			}
			cout << endl ; 
		}


	}



int main() {
	int x1 , y1 , x2 , y2 , x3 , y3 ; 
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ; 
	double area = x1*y1 + x2*y2 + x3* y3 ; 
	if (sqrt(area) > int(sqrt(area))){
		//cout << sqrt(area) << " " << int(sqrt(area)) ;  
		cout << "-1\n" ; 
		return 0 ; 
	}
	vp s1 ; vp s2 ; 
	s1.resize(3) ; s2.resize(3) ; 
	s1[0] = make_pair(x1,y1) ;
	s1[1] = make_pair(x2,y2) ; 
	s1[2] = make_pair(x3,y3) ; 

	s2[0] = make_pair(y1,x1) ; 
	s2[1] = make_pair(y2,x2) ; 
	s2[2] = make_pair(y3,x3) ; 



	int side = int(sqrt(area)) ;  
	int length = side ;
	int width = side ; 

	vp first ; vp second ; vp third ; 
	first.resize(2); second.resize(2) ; third.resize(2) ; 
	first[0] = s1[0] ; first[1] = s2[0] ; 
	second[0] = s1[1] ; second[1] = s2[1] ; 
	third[0] = s1[2] ; third[1] = s2[2] ;   


	



	for (int i = 0 ; i < 2 ; i++){
		for (int j = 0 ; j < 2 ; j++){
			for (int k = 0 ; k < 2 ; k++){
				int afl = first[i].first  ; 
				int afw = first[i].second ;
				/*cout << first[i].first << " " << first[i].second << endl ;
								cout << second[j].first << " " << second[j].second << endl ; 
								cout << third[k].first << " " << third[k].second<< endl ; 
*/
				if (afl < length){
					
					if (afl+second[j].first <= length){
						 
						if (afl + second[j].first == length && second[j].second == length){
							if (afw + third[k].second == width && third[k].first + second[j].first == length){
								print(0,0,first[i],0,first[i].first,second[j],first[i].second,0,third[k],length) ; 
								return 0 ;  
							}
						   
						}
						if (afl + second[j].first == length && second[j].second == afw){
								
								if (third[k].first == length && third[k].second == width-first[i].second){
									print (0,0,first[i],0,first[i].first,second[j],first[i].second,0,third[k],length) ; 
									return 0 ; 
								}
							}

						else {
							if (afl + second[j].first + third[k].first == length){
								print(0,0,first[i],0,first[i].first,second[j],0,first[i].first+second[j].first,third[k],length) ;
								return 0 ;
							}
							else{
								continue ;
							}
						}
					}

				}
				if (afl == length){
					int remWdth = width - afw ; 
					if (second[j].second + third[k].second == remWdth){
						print (0,0,first[i],first[i].second,0,second[j],first[i].second+second[j].second,0,third[k],width) ; 
						return 0 ; 
					} 
					else if (second[j].second == remWdth && third[k].second == remWdth && second[j].first + third[k].first == length){
						print (0,0,first[i],first[i].second,0,second[j],first[i].second,second[j].first,third[k],length) ; 
						return 0 ; 
					}
				} 
			}
		}
	}
	cout << "-1\n" ; 
		
}
