#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

#define INF 1000000 ; 
using namespace std; 

//typedef pair < pair<int,int>,int > Tup3 ;  

struct Tup3 {
	double t1 ; 
	double t2 ; 
	double t3 ; 

	
	bool operator< (const Tup3& t) const 
	{
		if (((double)t1)/t2 > ((double)t.t1)/t.t2){
			return true ;
		}
		if (((double)t1)/t2 == ((double)t.t1)/t.t2 && t3 < t.t3)
			return true ; 

		return false ; 
	}
	bool operator== (const Tup3& t) const
	{
		if (t1 == t.t1 && t2 == t.t2 && t3 == t.t3 )
			return true ; 
		if (t2 == 0 && t.t2 == 0){
			if ((double)t3/t1 == (double)t.t3/t.t1)
				return true ; 
		}
		else {
			if ((double)t3/t1 == (double)t.t3/t.t1 && ((double)t2)/t1 == (double)t.t2/t.t1)
				return true ;
		}
		return false ; 
	}
};
Tup3 t ; 
/*int gcd(int a , int b){
	if (a == b){
		return a ; 
	}
	if (a < b ){
		return gcd(b,a);
	}
	if (b == 0 )
		return  a ; 
	return gcd(b, a%b) ; 
}

int gcd3(int a , int b , int c){
	int temp = gcd(a,b) ; 
	return gcd(temp,c) ; 
}*/

double slope (Tup3 t){
	
	if (t.t2 == 0){
		return INF ;
	}
	if (t.t1 == 0){
		return 0 ;
	}
	return t.t1 ; 
 

	/*if (t.t2 == 0 && t.t1 < 0)
		return -INF ; 
	if (t.t2 == 0 && t.t1 > 0) return INF ; 
	
	return ((double)t.t1)/t.t2 ; */
}



int main (){
	
	int T ; 
	cin >> T ; 
	while (T--){
		int n ; 
		cin >> n ;
		set<Tup3> s ;
		/*s.resize(n) ;
		int ind = 0 ; */
		while (n--){
			double a ,b , c ; 
			cin >> a ; cin >> b ; cin >> c ; 
			
			
			t.t1 = a ; t.t2 = b ; t.t3 = c ; 
			if (a == 0 ){
				t.t2 = 1 ; t.t3 = c/b ; 
			}
			if (b == 0 ){
				t.t1 = 1 ; t.t3 = c/a ; 
			}
			if (a!=0 && b!=0){
				t.t1 = a/b ; t.t2 = 1 ; t.t3 = c/b ; 
			}
			s.insert(t) ;   
			
		}
		/*int ii ;
		Tup3 dup = s[0] ; 
		for (ii = 1 ; ii < s.size() ; ii++){
			if (dup.t1 == s[ii].t1 && dup.t2 == s[ii].t2 && dup.t3 == s[ii].t3){
				s.erase(s.begin()+	ii);
				dup = s[ii] ; 
				continue ; 
			}
		}
		sort(s.begin(),s.end()) ;*/ 
		int max = 1 ; int count = 1 ; double slop = slope(*s.begin()) ; int temp  ; 
		int i ; 
		for (set<Tup3>::iterator it = s.begin() ; it != s.end() ; it++){
			/*cout <<max <<" $$ "<<count<<"\n" ; 
			cout << s[i].t1<<"  "<<s[i].t2 <<"  "<< s[i].t3<<"\n" ; 
			cout <<slop << " ()() "<<slope(s[i])<<"\n" ; 
			*/
			//cout <<(*it).t1<<" "<<(*it).t2<<" "<<(*it).t3<<"\n" ;
			
			if (slop == slope(*it)){
				if (it == s.begin()){
					count = 1 ;
					max = 1 ; 
					//cout << max << "  "<<count<<"\n" ; 
					continue ; 
				}
				
				else {
					count += 1 ; 
					if (max < count)
						max = count ; 
					//cout << max << "  "<<count<<"\n" ; 
					continue ; 
				}

			}
			else {
				//cout << count <<"xxx\n" ;
				if (max < count){
					max = count ; 
				}
				count = 1  ;
				slop = slope(*it) ; 
				//cout << max << "  "<<count<<"\n" ; 
				continue ; 
			}

		}
		if (max < count)
			max = count ; 
		cout << max <<"\n" ; 
	}



	return 0 ; 
}