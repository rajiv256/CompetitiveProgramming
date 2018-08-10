#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#define forn(i,n) for (int i = 0 ; i < int (n) ; i++)
using namespace std;
typedef map<int,int> mii ; 
typedef std::vector<int> vi ; 


int main () {

	int n ; cin >> n ; 
	mii p ; mii s ; 
	int i ;  int tem ; vi v(n+1,0) ; 
	
	pair <int,int> pp (0,0) ; 
	vector< pair<int, int> > vp ; 

	for (i = 0 ; i < n ; i++){
		cin >> tem ; 
		p[tem] = i+1 ; 
		v[i+1] = tem ; 
	}
	for (i = 0 ; i < n ; i++){
		cin >> tem ; 
		s[tem] = i+1 ; 
	}
	vi res(n+1,0) ;
	for (i = 1 ; i <= n ; i++){
		res[i] = s[v[i]] ; 
		//cout << res[i] << " " ; 
	}
	//cout << endl ; 
	int index ; int count = 0 ; 
	for (i = n ; i >= 1 ; i--){
		for (int k = 1 ; k <= n ; k++){
			if (res[k] == i)
				index = k ; 
		}
		//cout << index <<"!!!" <<endl ; 
		int j ; 
		for (j = index + 1 ; j <= n ; j++){
			if (res[j] < j){
				//cout << index << " " << j << endl ; 
				p[i] = j ; 
				p[res[j]] = index ; 
				int temp = res[j] ; 
				res[index] = temp ; 
				res[j] = i ; 
				pp.first = index ; pp.second = j ; 
				vp.push_back(pp) ; 
				count += j - index ; 
				index = j ; 
				int o ; 
				for (o = 1 ; o <= n ; o++){
					if (res[o] != o)
						break ;
				}
				if (o == n+1)
					break ;

			}
				
		}
	}
	cout << count << "\n" ; 
	cout << vp.size() << "\n" ; 
	for(i= 1 ; i <vp.size();i++){
		cout << vp[i].first << " " << vp[i].second << endl ; 
	}

	return 0  ; 
}
