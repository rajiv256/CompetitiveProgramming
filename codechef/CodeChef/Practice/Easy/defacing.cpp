#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>

using namespace std; 

typedef vector<int> vi ; 
typedef vector<bool> vb ; 
#define forn(i,n) for(int i = 0 ; i < n ; i++) 
#define lld long long int 

map<int,vector<int> > m ; 

// finds the number of digits in a number. 
int noDigits(int n){
	int cnt = 0 ; 
	while (n != 0){
		cnt++ ; 
		n /= 10 ; 
	}
	return cnt ; 
}

// fill the digits from "n" into v . 
void fillDigits(vi& v , lld n){
	for (int i = v.size()-1 ; i>= 0 ; i--){
		v[i] = n %10 ; 
		n /= 10 ; 
	}
	return ; 
}

// this is the maximum number in a vector less than or equal to `max`.
int maxle(vi& v , lld max){
	lld res = -1 ; 
	forn(i,v.size()){
		if (v[i] <= max){
			if (res <= v[i])
				res = v[i] ; 
		}
	}
	return res ; 
}


lld getVal(vi& buff , vi& mdv,int i){

	if (i == buff.size()){
		lld val = 0 ; 
		forn(j,buff.size()){
			val = 10*val + buff[j] ; 
		}
		return val ;
	}
	int pr = maxle(m[buff[i]],mdv[i]) ;

	if (pr == -1){
		return -1 ; 
	} 
	if (pr == mdv[i]){
		
		vi buff1 ; buff1.resize(buff.size());  
		vi buff2 ; buff2.resize(buff.size());
		forn(k,buff.size()){
			buff1[k] = buff[k] ; 
			buff2[k] = buff[k] ; 
		}
		
		buff1[i] = mdv[i]-1 ; 
		buff2[i] = mdv[i] ; 
		
		for(int j = i+1 ; j < mdv.size() ; j++){
			//cout<< mdv[j] << endl;
			/*forn(k,buff.size()){
				cout << m[buff1[j]][k] << " "; 
			}
			cout << endl ; 
			*/buff1[j] = m[buff1[j]][m[buff1[j]].size()-1] ; 
		} 
		
		lld val1 = 0 ; 
		forn(k,buff1.size()){
			val1 = 10*val1 + buff1[k] ; 
		}
		//cout << val1 << endl ; 
		lld val2 = getVal(buff2,mdv,i+1) ; 
		
		return (max(val1,val2)) ; 
	}	
	if (pr  < mdv[i]){
		//cout << pr << " should be :(0,4) " << mdv[i] << endl ; 
		vi buff1 = buff ; 
		buff1[i] = pr ; 
		for(int j = i+1 ; j < mdv.size() ; j++){
			buff1[j] = m[buff1[j]][m[buff1[j]].size()-1] ; 
		} 
		lld val1 = 0 ; 
		forn(k,buff1.size()){
			val1 = 10*val1 + buff1[k] ; 
		} 
		return val1 ; 
	}

}





int main() {
	int t ; cin >> t ; 
	
	int x[10] = {0,1,2,3,4,5,6,7,8,9} ; 
	int  x0[2] = {0,8} ; int x1[7] = {0,1,3,4,7,8,9} ; 
	int x2[2] = {2,8} ; int x3[3] = {3,8,9} ; int x4[3] = {4,8,9} ;
	int x5[3] = {5,8,9} ; int x6[2] = {6,8} ; 
	int x7[5] = {0,3,7,8,9} ; int x8[1] = {8} ; 
	int x9[2] = {8,9} ; 

	vector<int> v(x , x+sizeof(x)/sizeof(x[0])) ;
	m[-1] = v ; 
	// segregating the possible numbers from a given number into a map. 
	vector<int> v0(x0 , x0+sizeof(x0)/sizeof(x0[0])) ;
	m[0] =  v0 ; 
	 vector<int> v1(x1 , x1+sizeof(x1)/sizeof(x1[0])) ; 
	m[1] = v1 ; 
	vector<int> v2(x2 , x2+sizeof(x2)/sizeof(x2[0])) ; 
	m[2] = v2 ; 
	vector<int> v3(x3 , x3+sizeof(x3)/sizeof(x3[0])) ; 
	m[3] = v3 ; 
	vector<int> v4(x4 , x4+sizeof(x4)/sizeof(x4[0])) ; 
	m[4] = v4 ; 
	vector<int> v5(x5 , x5+sizeof(x5)/sizeof(x5[0])) ; 
	m[5] = v5 ; 
	vector<int> v6(x6 , x6+sizeof(x6)/sizeof(x6[0])) ; 
	m[6] = v6 ;
	vector<int> v7(x7 , x7+sizeof(x7)/sizeof(x7[0])) ; 
	m[7] = v7 ;
	vector<int> v8(x8 , x8+sizeof(x8)/sizeof(x8[0])) ; 
	m[8] = v8 ; 
	vector<int> v9(x9 , x9+sizeof(x9)/sizeof(x9[0])) ; 
	m[9] = v9 ; 



	while (t--){
		int s , m ; cin >> s >> m ; 
		int sd = noDigits(s) ; 
		int md = noDigits(m) ; 
		if (s == 0){
			sd = 1 ; 
		}
		if (m == 0){
			md = 1 ; 
		}
		vi mdv ; vi sdv ; mdv.resize(md) ; sdv.resize(sd) ; 
		// mdv and sdv are the vectors containing the two numbers. 

		fillDigits(mdv,m) ; fillDigits(sdv,s) ; 
		// In case of s = 0 (or) m ==0 . 
		
		if (m == 0){
			mdv[0] = 0 ; 
		}
		if ( s == 0){
			sdv[0] = 0 ; 
		}
		lld maxi = s ; 
		
		for (int i = 0 ; i <= md-sd ; i++){
			vi buff(md,-1) ; 
			copy(sdv.begin(),sdv.end(),buff.begin()+i) ; 
			
			lld val = getVal(buff,mdv,0) ; 
			if (maxi < val){
				maxi = val ; 
			}
			//cout << val << endl ; 
		}
		cout << maxi << endl ; 

	}
}
