#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;

<<<<<<< HEAD

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
=======
#define forn(i,n) for(int i = 0; i < n ; i++)
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el endl
#define ll long long
>>>>>>> 5b6b8ee31913384d18236b6fa9d75bd1ee4c63f5
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
<<<<<<< HEAD
#define sci(x) scanf("%d",&x)
#define mp make_pair
#define ll long long

int L[1003][1003] ; 
 
int dp(int st , int en , int sz,string s[]){
	if (st > en){
		return INF ; 
	}
	if (st==en){
		if (L[st][en]!= INF)
			return L[st][en]; 
		if (s[st]=="aa" || s[st]=="bb" || s[st].size()==1){
			L[st][en] = 0 ; 
			return 0 ; 
		}
		else{  
			L[st][en] =1 ; 
			return 1; 
		}
	}
	if (L[st][en] != INF){
		return L[st][en] ; 
	}
	string x = s[st] ; string y = s[en] ; 
	if (x==y || (x=="ab" && y=="ba") || (x=="ba" && y=="ab")){
		L[st+1][en-1]  = dp(st+1,en-1,sz,s); 
	}
	L[st+1][en] = dp(st+1,en,sz,s) ; 
	L[st][en-1] = dp(st,en-1,sz,s) ;  

	return min(L[st][en],min(1+L[st+1][en],1+L[st][en-1])) ; 
}
=======
#define mp make_pair
#define MXN 100003
#define MOD 1000000007
#define gc getchar_unlocked	
#define sci(x) scanf("%d",&x) 
int L[1003][1003] ; 

bool check(string s1 , string s2){
	if (s1.size()!=s2.size()){
		return false; 
	}
	if (s1.size()==1){
		if (s1==s2){
			return true ; 
		}
		return false ; 
	}
	if (s1[0]==s2[1] && s2[1]==s1[0]){
		return true ; 
	}
	return false ; 
}

int solve(int st , int en , string s[], int n){
	

	if (st==en){
		if (s[st].size()==1 || s[st]=="aa" || s[st]=="bb"){
			return 0 ; 
		}
		else{
			return 1 ; 
		}
	}
	if (st+1 ==en){
		string x = s[st] ; string y = s[en] ; 
		if ((x.size()==1 && x==y) || (x=="aa"&&y=="aa") || (x=="bb"&&y=="bb")||(x=="aa"&&y=="bb")||(x=="ab"&&y=="ba")||(x=="bb"&&y=="aa")||(x=="ba"&&y=="ab")){
			return 0 ; 
		}
		if ((x=="bb"&&y=="b")||(x=="aa"&&y=="a")||(x=="a"&&y=="aa")||(x=="b"&&y=="bb")){
			return 0 ; 
		}
		L[st+1][en]  = solve(st+1,en,s,n) ; 
		L[st][en-1] = solve(st,en-1,s,n) ; 
		//cout << L[st+1][en] << sp << L[st][en-1] << el ; 
		return min(1+L[st+1][en],1+L[st][en-1]) ; 
	}
	if (L[st][en] < INF){
		return L[st][en] ; 
	}
	string x = s[st] ; string y = s[en] ; 
	int ans = n ; 
	if (x.size()==y.size()){
		if (x.size()==2){
			if (check(x,y)){
				L[st+1][en-1] = solve(st+1,en-1,s,n); 
				ans = min(ans,L[st+1][en-1]) ; 
			}
			//else{
				L[st+1][en] = solve(st+1,en,s,n) ; 
				L[st][en-1] = solve(st,en-1,s,n) ; 
				ans = min(ans,min(1+L[st+1][en],1+L[st][en-1])) ; 
			//}
		}
		if (x.size()==1){
			if (x==y){
				L[st+1][en-1] = solve(st+1,en-1,s,n) ;
				//cout << L[st+1][en-1] << el ; 
				ans = min(ans,L[st+1][en-1]) ;  
			}
			L[st+1][en] = solve(st+1,en,s,n) ; 
			L[st][en-1] = solve(st,en-1,s,n) ; 
			ans = min(ans,min(1+L[st+1][en],1+L[st][en-1])) ;	
		}
	}

	else{
		if (x.size() < y.size()){
			string temp = x ; temp += s[st+1] ; 
			if (check(temp,y)){
				L[st+2][en-1] = solve(st+2,en-1,s,n) ; 
				ans = min(ans,L[st+2][en-1]) ; 
			}
			L[st+1][en] = solve(st+1,en,s,n) ; 
			L[st][en-1] = solve(st,en-1,s,n) ; 
			ans = min(ans,min(1+L[st+1][en],1+L[st][en-1])) ;
		}
		else{
			string temp = s[en-1] ; temp += s[en] ; 
			if (check(x,temp)){
				L[st][en-2] = solve(st,en-2,s,n) ; 
				ans = min(ans,L[st][en-2]); 
			}
			L[st+1][en] = solve(st+1,en,s,n) ; 
			L[st][en-1] = solve(st,en-1,s,n) ; 
			ans = min(ans,min(1+L[st+1][en],1+L[st][en-1])) ;
		}
	}
>>>>>>> 5b6b8ee31913384d18236b6fa9d75bd1ee4c63f5




<<<<<<< HEAD


int main(){
	ios::sync_with_stdio(false) ; 
	cin.tie(0) ; 

	int t ; sci(t) ; 
	while (t--){
		int n ; sci(n) ; 
		string s[n] ; 
=======
	return ans ; 

}





int main(){
	int t; sci(t) ; 
	ios::sync_with_stdio(false) ; 
	cin.tie(0) ; 

	while (t--){
		int n; sci(n) ; 
		string s[50] ; 
>>>>>>> 5b6b8ee31913384d18236b6fa9d75bd1ee4c63f5
		forn(i,n){
			cin >> s[i] ; 
		}
		forn(i,n){
			forn(j,n){
				L[i][j] = INF ; 
<<<<<<< HEAD
			}
		}
		for(int i = 0  ; i < n ; i++){
			L[i][n-1] = dp(i,n-1,n,s) ; 
		}
		int ans = n ; 
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				cout << L[i][j] << sp ; 
				ans = min(ans,L[i][j]) ; 
			}
			cout << L[i]
		}
		printf("%d\n", ans) ; 

	}
	
=======
				if (i==j){
				    if (s[i].size()==1){
				        L[i][j] = 0 ; 
				    }
				    if (s[i]=="aa" || s[i]=="bb"){
				        L[i][j]= 0 ; 
				    }
				    if (s[i]=="ab" || s[i]=="ba"){
				        L[i][j] = 1 ; 
				    }
				}
			}
		}
		L[0][n-1] = solve(0,n-1,s,n) ; 

		
		printf("%d\n", L[0][n-1]);


	}
>>>>>>> 5b6b8ee31913384d18236b6fa9d75bd1ee4c63f5
}
