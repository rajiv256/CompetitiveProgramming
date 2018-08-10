#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <string>


using namespace std ; 
string toString(char c){
	string aa ; aa.append(1,c);  
	return aa ; 
}





int main() {
	int t ; cin >> t ; 
	char c ; 
	string res = "" ; 
	 
	
	while (t--){
		stack<string> var ; stack<char> op ; 
		string s ; cin >> s ; 
		int i ; 
		for ( i = 0 ; i < s.size() ; i++){
			c = s[i] ;
			if (c == '\n')
				break ; 
			//cout << c << endl;  
			if (c == '+')
			op.push('+') ;

			if (c == '-')
				op.push('-') ; 
			if (c == '*')
				op.push('*') ; 
			if (c == '/')
				op.push('/') ; 
			if (c == '^')
				op.push('^') ;
			if (c == '(')
				op.push('(') ;
			if (c == ')'){
				char oop = op.top() ;
				op.pop();  
				while (oop != '('){
					string v1 = var.top() ;
					var.pop() ;  	
					string v2 = var.top() ;
					cout << v2 << endl; 
					var.pop() ;  
					v2 += v1 ; 
					v2 += oop ; 
					var.push(v2) ; 
					oop = op.top() ; 
					op.pop() ;  

				}
			} 	
			if (c >= 'a' && c <= 'z'){
				var.push(toString(c)) ; 
			} 


		}
		cout << var.top() << "\n" ; 
 		
	}
	




}

/*
def get2(n,l1,l2,lens):
	#print n
	t1 = n/(10**(lens-1))
	t2 = n % 10 
	#print t1,t2 
	if (t1 == t2) :
		l1.append(t1)
		l2.insert(0,t2) 
		n = n % (10**(lens-1))
		n = n / 10 
		return n ; 
	if (t1 > t2):
		t2 = t1 
		l1.append(t1)
		l2.insert(0,t1)
		#print l1,l2	
		n = n % (10**(lens-1))
		n = n / 10 
		return n ;
	if (t1 < t2):
		n = n + 10 - t2 
		#print n 
		return (get2(n,l1,l2,lens)) ; 

*/