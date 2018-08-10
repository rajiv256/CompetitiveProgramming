#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define pii pair<int,int>
#define INF 1000000000
#define sp " "
#define el "\n"
#define lld long long int
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define sci(x) scanf("%d",&x)
#define mp make_pair
#define ll long long

int status(char c){
	if (c>='0' && c <='9'){
		return 1 ; 
	}
	if (c>='A' && c <='Z'){
		return 2 ; 
	}
	return 0 ; 
}
string ls4(int x){
	string s  = "" ; int filter = 1 ; 
	for(int i = 0 ; i < 4 ; i++){
		if (x&filter){
			s += "1" ;
		}
		else{
			s += "0" ; 
		}
		filter = filter*2 ; 
	}
	string rev = "" ; int it = 3  ; 
	while (it >= 0){
		rev += s[it--] ;
	} 
	return rev ; 
}
char str2hexa(string s){
	//cout << s << el; 
	int ret = 0 ; int x = 1 ;   
	for(int i = 3; i >= 0 ; i--){
		ret += x*(s[i]-'0') ; 
		x *= 2; 
	}	
	//cout << ret << el ; 
	if (ret <= 9){
		char c = '0'+ret ;  
		return c ; 
	}
	else{
		ret -= 10 ; 
		char c = 'A'+ret ; 
		return c ;  
	}
}



string hexa[25] ; 


void fill(string x, string& bx ){
	forn(i,x.size()){
		if (status(x[i])==1){
			bx += ls4(x[i]-'0') ; 
		}
		else{
			bx += ls4(x[i]-'A'+10) ; 
		}
	}
}

void balance(string& x , string& y  , string& z){
	int len1 = x.size() ; int len2 = y.size() ; int len3 = z.size() ; 
	if (len1 >= len2 && len1 >= len3){
		int a = (len1-len2)/4 ; 
		while (a--){
			y = "0000"+y ;
		}
		a = (len1-len3)/4 ; 
		while (a--){
			z = "0000"+z ; 
		}
		return ; 
	}
	if (len2 >= len1 && len2 >= len3){
		 return balance(y,x,z) ; 
	}
	if (len3 >= len1 && len3 >= len2){
		return balance(z,x,y) ; 
	}

}





int main(){
	int q ; sci(q) ;
	forn(i,16){
		hexa[i] = ls4(i) ; 
	}
	while (q--){
		int k ; sci(k) ; 
		string a ; string b ; string c ; 
		cin >> a >> b >> c ; 
		string ba ; string bb ; string bc ; 
		fill(a,ba) ; fill(b,bb) ; fill(c,bc) ; 
		
		 
		balance(ba,bb,bc) ; 

		bool mark[bc.size()] ; 

		int flip = 0 ; 
		forn(i,bc.size()){
			
			if (bc[i]=='0'){
				
				if (ba[i]=='0'){
					 
					if (bb[i]=='0'){
						continue ; 
					}
					else{
						 
						flip += 1 ; 
						mark[i] = true ; 
						bb[i]= '0' ; 
						continue ; 
					}
				}
				else{	
					ba[i] = '0' ; 
					flip += 1 ; 
					mark[i] = true ; 
					if (bb[i]!='0'){
						flip += 1 ;
						bb[i] = '0' ; 
						continue ; 
					}
					continue ; 
				}
			}
			else{
				if (ba[i]=='1' || bb[i]=='1'){
					continue  ; 
				}
				else{
					flip += 1; 
					bb[i] = '1' ;
					mark[i] = true ;
					continue ;  
				}
			}
		}
		
		if (flip > k){
			printf ("-1\n") ; 
			continue ; 
		}
		
		while (flip < k){
			forn(i,bc.size()){
				/* You are such a bitch */
				if (flip == k){
					break ; 
				}
				if (bc[i]=='1'){
					if ((ba[i]=='1') && (bb[i]=='0')){
						if (flip+2 <= k){
							ba[i]='0' ; bb[i]='1' ; 
							flip += 2 ; 
							continue ; 
						}
					}
					if ((ba[i]=='1') && (bb[i]=='1')){
						flip += 1 ; 
						ba[i]= '0' ; 
						continue ; 
					}
				}
			}

			break ; 
		}
		
		
		int it = 0 ; 
		string ans1 = "" ; string ans2 = "" ; 
		while (it < ba.size()){
			string w = "" ; 
			forn(i,4){
				w += ba[i+it]  ; 
			}	
			char c = str2hexa(w) ; 
			ans1 += c ; 
			
			it += 4 ; 
		}
		it  = 0 ; 
		while (it < bb.size()){
			string w = "" ; 
			forn(i,4){
				w += bb[i+it]  ; 
			}	
			char c = str2hexa(w) ; 
			ans2 += c ; 
			it += 4 ; 
		}		
		it = 0 ; 
		while ((ans1[it]=='0') && (it <ans1.size()-1)){
			it++ ; 
		}
		for(;it<ans1.size();it++){
			cout << ans1[it] ; 
		}
		cout << el ;
		it = 0 ; 
		while ((ans2[it]=='0') && (it < ans2.size()-1)){
			it++ ; 
		}
		for(;it<ans2.size(); it++){
			cout << ans2[it] ; 
		}
		cout << el ; 






	}




	return 0 ; 


}