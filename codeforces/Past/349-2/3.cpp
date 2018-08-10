#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mi ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pi pair<int,int>
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define INF 1000000
#define LIM 1000000000
#define PI 3.141592653589793
#define sp " "
#define el "\n"
#define ll long long
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x)
#define MXN 1000003
#define gc getchar_unlocked

int dp[10009][2] ; 
set<string> ss ;

int solve(string s , int idx , int num){
	if (dp[idx][num] != -1){
		return dp[idx][num] ; 
	}
	if (num==0){
		dp[idx+2][0] = solve(s,idx+2,0) ; 
		dp[idx+2][1] = solve(s,idx+2,1) ; 
		if (!(dp[idx+2][0]|dp[idx+2][1])){
			return 0  ; 
		}
		else{
			
			if ((s[idx]==s[idx+2]) & (s[idx+1]==s[idx+3])){
				return dp[idx+2][1] ; 
			}
			else{
				//cout << idx << el ; 
				//string x = "" ; x += s[idx] ; x += s[idx+1] ; 
				//ss.insert(x) ; 
				return 1 ; 
			}
		}
	}
	else{
		dp[idx+3][0] = solve(s,idx+3,0) ; 
		dp[idx+3][1] = solve(s,idx+3,1) ; 
		if (!(dp[idx+3][0]|dp[idx+3][1])){
					return 0  ; 
		}
		else{
			
			if ((s[idx]==s[idx+3]) & (s[idx+1]==s[idx+4]) &(s[idx+2]==s[idx+5])){
				return dp[idx+3][0] ;  
			}
			else{
				//cout << idx << el ; 
				//string x = "" ; x += s[idx] ; x += s[idx+1] ; x += s[idx+2] ; 
				//ss.insert(x) ; 
				return 1 ; 
			}
		}
	}
}



int main(){
	string s="" ; cin >> s ; 
	forn(i,10009){ 
		forn(j,2){
			dp[i][j] = -1 ; 
		}
	}
	dp[s.size()-2][0] = 1 ; 
	dp[s.size()-1][0] = 0 ;
	dp[s.size()-2][1] = 0 ; 
	dp[s.size()-1][1] = 0 ;
	
	dp[s.size()-3][1] = 1 ;
	dp[s.size()-3][0] = 0 ;
	dp[s.size()-2][1] = 0 ;
	dp[s.size()-1][1] = 0 ; 
	dp[s.size()-1][0] = 0 ; 
				
	for(int i = 5 ; i < s.size() ; i++){
		dp[i][0] = solve(s,i,0) ; 
		dp[i][1] = solve(s,i,1) ; 
	}
	for(int i = 5 ; i <s.size(); i++){
		forn(j,2){
			if (dp[i][j] == 1){
				if (j == 0){
					string x = "" ; x += s[i] ; x+=s[i+1] ; 
					ss.insert(x) ; 
				}
				if (j == 1){
					string x = "" ; x += s[i] ; x += s[i+1] ; x += s[i+2] ; 
					ss.insert(x) ; 
				}
			}
		}
	}
	
	cout << ss.size() << el ; 
	for(set<string>::iterator it = ss.begin() ; it != ss.end() ; it++){
		cout << (*it) << el ; 
	}
	//cout << el ; 
	return 0 ; 
	
	
	
	
}
