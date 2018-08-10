#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <set>



using namespace std;
#define forn(i,n) for (int i = 0 ; i < n ; i++)
typedef vector<char> vc ; 





int main() {

	string all = "abcdefghijklmnopqrstuvwxyz" ; 

	int n ; cin >> n ; int t ; cin >> t ;  
	string s1, s2 ; 
	cin >> s1 ; cin >> s2 ; 
	map<char,int> cnt1 ;
	map<char,int> cnt2 ;  
	forn(i,n){
		cnt1[s1[i]]++ ;
		cnt2[s2[i]]++ ;  
	}
	vc comm ; vc ins1 ; vc ins2 ; vc nin ;  

	forn(i,26){
		if (cnt1[all[i]] > 0 && cnt2[all[i]] > 0){
			forn(j,min(cnt1[all[i]],cnt2[all[i]]))
				comm.push_back(all[i]) ; 
		}
		if (cnt1[all[i]] == 0 && cnt2[all[i]] > 0){
			forn(j,cnt2[all[i]])
				ins2.push_back(all[i]);
		}
		if (cnt1[all[i]] > 0 && cnt2[all[i]] == 0){
			forn(j,cnt1[all[i]])
				ins1.push_back(all[i]);
		}
		if (cnt1[all[i]] == 0 && cnt2[all[i]] == 0){
				nin.push_back(all[i]);
		}

	}
	set<char> ss (comm.begin(),comm.end()) ; 
	if (ss.size() > (n-t)){
		cout << "-1\n" ;
		return 0 ; 
	}
	vector<char> res(n,'~') ; 
	if(comm.size() >= n-t ){
		copy(comm.begin() , comm.begin()+n-t,res.begin()) ; 
		if (nin.size() >= t ){
			copy(nin.begin(), nin.begin()+t,res.begin()+n-t);
		}
		else {
			if (t % 2 == 0){
				int el = (nin.size()/2)*2 ; 
				copy(nin.begin(),nin.begin()+el , res.begin()+n-t) ; 
				if (ins1.size() >= (t-el)/2 && ins2.size() >= (t-el)/2){
					copy(ins1.begin(), ins1.begin()+(t-el)/2, res.begin()+n-t+el);
					copy(ins2.begin(), ins2.begin()+(t-el)/2, res.begin()+n-t+el+(t-el)/2);
				}
				else {
					cout << "-1\n" ; 
					return 0 ; 
				}
			}
			else{
				int el ; 
				if (nin.size()%2 == 1){
					el = nin.size() ; 
				}
				else{
					el = nin.size() - 1 ; 
				}
				copy(nin.begin(),nin.begin()+el , res.begin()+n-t) ; 
				if (ins1.size() >= (t-el)/2 && ins2.size() >= (t-el)/2){
					copy(ins1.begin(), ins1.begin()+(t-el)/2, res.begin()+n-t+el);
					copy(ins2.begin(), ins2.begin()+(t-el)/2, res.begin()+n-t+el+(t-el)/2);
				}
				else {
					cout << "-1\n" ; 
					return 0 ; 
				}
			}

		}
	}
	else {
		cout << "-1\n" ; 
		return 0 ;
	}

	forn(i,n){
		cout << res[i] ; 
	}
	cout <<"\n" ; 
	return 0 ; 













}