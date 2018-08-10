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

#define forn(i,n) for(int i = 0; i < n ; i++)
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el endl
#define ll long long
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
//#define sci(x) scanf("%d",&x)
#define MXN 100003
#define gc getchar_unlocked	
void sci(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}


vi v ; int lis = 1; 
int maxnum = 1 ; 

void printv(vi& a){
	forn(i,a.size()){
		cout <<a[i] <<sp ;  
	}
	cout << el ;
}

vi solve(vi&tern, int pow){
	int idx = tern.size()-pow-1 ; vi ret ; 
	int m = tern[idx] ; 
	//cout << pow << " @@ " << el ; 
	if (pow==0){
		if (m==0) 
			return ret; 
		if (m==1){
			ret.pb(maxnum++) ; 
		}
		if (m==2){
			ret.pb(maxnum+1) ; ret.pb(maxnum) ; maxnum += 2 ; 
		}
		
		for(int i = 1 ; i < lis ; i++){
			ret.pb(maxnum++) ; 
		}
		//printv(ret) ; 
		return ret ; 
	}
	int llis = 0 ; 
	if (m==0){
		return ret ; 
	}
	if (m==2){
		ret.pb(maxnum+1) ; ret.pb(maxnum) ; 
		maxnum +=2 ;
		llis +=1 ; 
	}
	
	for(int i = 0 ; i < pow ; i++){
		ret.pb(maxnum+2) ; ret.pb(maxnum+1) ; ret.pb(maxnum) ; 
		maxnum += 3;
		llis++ ; 
	}
	if (llis < lis){
		for(int i=llis ; i < lis ; i++){
			ret.pb(maxnum++); 
		}
	}
	if (lis < llis){
		lis = llis ; 
	}
	//printv(ret) ; 
	return ret ; 
}













int main(){
	int t ; sci(t) ; 
	while (t--){
		int k ; sci(k) ; 
		vi tern ; 
		int temp = k ; 
		while (temp!=0){
			tern.pb(temp%3) ; 
			temp /= 3 ; 
		}
		vi ans ; 
		reverse(all(tern)) ; 
		for(int i = 0 ; i < tern.size() ; i++){
			vi v1 = solve(tern,tern.size()-i-1) ; 
			forn(j,v1.size()){
				ans.pb(v1[j]) ; 
			}
			forn(j,v.size()){
				ans.pb(v[j]) ; 
			}
			v = ans ; 
			ans.clear() ; 
		}
		cout << v.size() << el ; 
		printv(v) ; 
		
		
		
		
	}
}
