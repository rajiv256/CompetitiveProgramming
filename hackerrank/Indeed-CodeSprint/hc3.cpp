#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef vector<int> vi ; 

void ph(vi hash){
	//cout << "\n---------------------------------------\n" ; 
	cout << "printing the hash...\n" ; 
	for (int i = 0 ; i < hash.size(); i++){
		cout << i << " : " << hash[i] << endl ; 
	}
	//cout << "\n---------------------------------------\n" ; 
}
void pm(map<int,int> m ){
	cout << "printing the map...\n" ; 
	for (map<int,int>::iterator it = m.begin() ; it != m.end() ; it++){
		cout << (*it).first << " : " << (*it).second << endl  ; 
	}
	//cout << "\n-------------------------------------------\n" ; 
}


int main() {

	map<int,int> asc ; 
	map<int,int> cnt ;

	int m , n , q ; 
	cin >> m >> n >> q ; 
    vector<int> hash(n+1,0);
	int i = 1 ; int temp ; 
	for (int j = 1 ; j <= m ; j++){
		cnt[j] = 0 ; 
	}
	while (i <= n ){
		cin >> temp ; temp += 1; 
		asc[i] = temp ; 
		cnt[temp]++ ;  
         
		i+=1 ;
	}
	//pm(cnt) ; 
	for(map<int,int> :: iterator it = cnt.begin() ; it!= cnt.end() ; it++){
		//cout << (*it).second << " pn\n" ; 
		hash[(*it).second] += 1 ; 
	}
	//ph(hash) ; 
	//ph(hash) ; 
	while (q--){
		int fl ; 
		cin >> fl ; 
		if (fl == 2){
			int count = 0 ; int p ; cin >> p ;   
			for (int i = 0 ; i < p ; i++){
                count += hash[i] ;  
            }
			cout << count << endl ; 
		}
		if (fl == 1){
			int a , b ; 
			cin >> a >> b ; 
			a += 1 ; b+= 1 ;
           /* cout << "\n--------------------\n" ; 
           	ph(hash) ; 
           	pm(asc) ; 
           	pm(cnt) ; 
           	cout << a << " actor to scene " << b << endl ; 
*/			hash[cnt[asc[a]]]--; 
            cnt[asc[a]]-- ; 
            hash[cnt[asc[a]]]++;
            
            asc[a] = b ;
            hash[cnt[b]]-- ; 
            cnt[b]++ ; 
            hash[cnt[b]]++ ; 
			/*ph(hash) ; 
			pm(asc) ; 
			pm(cnt) ; 
			cout << "\n--------------------------\n" ; 
*/		}
	}
	return 0 ; 
}

