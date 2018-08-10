#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>

using namespace std ;
 
float dist (pair<int,int> p1 , pair<int,int> p2){

	return ((p1.first -p2.first)*(p1.first -p2.first) + (p1.second-p2.second)*(p1.second-p2.second)) ; 


}



int main() {

	int t ; cin >> t ; 
	while (t--){
		float maxdist = 0 ; 
		int n ; cin >> n ; 
		vector<pair<int,int> > vp ; 
		while (n--){
			pair<int,int> p ; 
			int a , b ; 
			cin >> a >> b ; 
			p = make_pair(a,b) ; 
			for (int i = 0 ;  i < vp.size() ; i++){
				int temp = dist(p,vp[i]) ; 
				if (maxdist < temp)
					maxdist = temp ; 
			}
			vp.push_back(p) ; 
		}
		printf("%.10lf\n",sqrt(maxdist)) ; 

	}
	return 0 ; 




}