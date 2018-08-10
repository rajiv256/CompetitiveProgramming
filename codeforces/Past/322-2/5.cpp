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


int main() {
	int e ,s ,n,m ; cin >> e >> s >> n >> m ; 
	vp orig ; orig.resize(n) ; 
	forn(i,n){
		int a , b ; cin >> a >> b ; 
		orig[i].first = b ; 
		orig[i].second = a ; 
	}
	vi start ; start.resize(m) ; 
	forn(i,m) {
		cin >> start[i] ; 
	}
	
	forn(i,m) {
		int pos = start[i] ; int tot = s ; int tot1 = 0 ; int tot2 = 0 ; int tot3 = s ; 
		vp stats ; stats.resize(n) ; 
		forn(j,n){
			stats[j].first = orig[j].first ;
			stats[j].second = orig[j].second ;  
		}
		if (e < pos){
			e = -e ; 
			pos = -pos ; 
			forn(j,n){
				stats[j].first = -orig[j].first ;
				stats[j].second = -orig[j].second ;  
			}	

		}

		//cout << pos << endl ; 

		if ( e >= pos ) {
			int used1 = 0, used2 = 0  ; 
			
			sort(stats.begin(),stats.end()) ; 
			int min = 0 ; 
			
			if (e -pos <= s){
				cout << "0 0\n" ; 
				continue ;
			}


			forn(j,n){
				////cout << tot1 << " " << tot2 << " " << tot3 << endl ;
				if (stats[j].first < pos){
					continue ;
				}
				
				int dist = stats[j].first - pos ; 
				//cout << "dist : "<<dist << "  tot3 : " << tot3 << endl ;  
				if (dist <= tot3){
					tot3 -= dist ; 
					dist = 0 ; 
					
					//cout << "dist : "<<dist << "  tot3 : " << tot3 << endl ;  
					
				}
				else {
					dist -= tot3 ; 
					tot3 = 0 ; 
					//cout << "dist : "<<dist << "  tot2 : " << tot2 << endl ;  
					
					if (dist <= tot2){
						tot2 -= dist ;
						used2 += dist ;  
						dist = 0 ;
						//cout << "dist : "<<dist << "  tot2 : " << tot2 << endl ; 
					}
					else{
						dist -= tot2 ; 
						used2 += tot2 ; 
						tot2 = 0 ; 
						if (dist <= tot1){
							tot1 -= dist ;
							used1 += dist ;  
							dist = 0 ; 
						}
						else if (dist > 0){
							cout << "-1 -1\n" ; 
							break ; 
						}
					}

				}
				if (stats[j].second == 3){
					tot3 = s ; 
					tot1 = 0 ; 
					tot2 = 0 ; 
				}
				if (stats[j].second == 2){
					//cout << "came to station 2\n" ; 
					tot2 = s - tot3 ; 
					tot1 = 0 ;
					//cout << tot1 << " " << tot2 << " " << tot3 << endl ; 	
				}
				if (stats[j].second == 1){
					tot1 = s-tot3-tot2 ; 
				}
				pos = stats[j].first ; 
				if (j == n-1 || (j < n-1 && stats[j+1].first >= e)){
					
					int fdist = e - stats[j].first ; 
					//cout << fdist << " " << used1 << " "<< used2 << " "<< endl ; 
					if (fdist <= tot3){
						cout << used1 << " " << used2 << endl ;
						break ;   
					}
					else {
						fdist -= tot3 ; 
						tot3 = 0 ; 
						if (fdist <= tot2){
							used2 += fdist ; 

							cout << used1 << " " <<used2 << endl ;
							break ; 
						}
						else {
							fdist -= tot2 ; 
							used2 += tot2 ; 
							tot2 = 0 ;
							if (fdist <= tot1){
								used1 += fdist ; 
								cout << used1 << " " << used2 << endl ; 
								break ; 
							}
							else if (fdist > 0){
								cout << "-1 -1\n" ; 
								break; 
							}
						}
					}
				}

			}	
		}
			
	}

	return 0 ; 	



}