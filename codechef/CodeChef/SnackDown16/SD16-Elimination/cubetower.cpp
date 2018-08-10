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


typedef struct node {
	
	string s ; 
	void init() {
		s = "@" ; 
	}
	void merge(node n1 , node n2){
		s = n1.s+n2.s ;  
	}
}node;

node stree[3*MXN] ; 

void build(int low , int high , int src){
	if (low==high){
		stree[src].init() ; 
		return ; 
	}
	if (low > high){
		return ; 
	}
	int mid = (low+high)/2 ; 
	build(low,mid,2*src) ; 
	build(mid+1,high,2*src+1) ; 
	return ; 
}


void update(int low , int high , int idx ,int src, char c){
	//cout << low << sp << high << sp << src << el ; 
	if (low>idx || high<idx){
		return ; 
	}
	if (low==high && low==idx){
		string temp = "" ; temp += c ; 
		string x = stree[src].s ; 
		stree[src].s = temp+x ;
		//cout << src << sp << stree[src].s << el; 
		return ; 
	}
	int mid = (low+high)/2 ; 
	update(low,mid,idx,2*src,c) ; 
	update(mid+1,high,idx,2*src+1,c) ; 
	stree[src].merge(stree[2*src],stree[2*src+1]) ; 
	return ; 

}

node query(int low , int high , int left , int right , int src){
	//cout << low << sp << high << el ; 
	if (left<=low && right>=high){
		return stree[src] ; 
	}
	if (low>right || high<left){
		node n ; 
		return n ; 
	}
	int mid = (low+high)/2 ; 
	
	node n1 = query(low,mid,left,right,2*src) ; 
	node n2 = query(mid+1,high,left,right,2*src+1) ; 
	node ret ; 
	ret.merge(n1,n2) ; 
	return ret ; 
}

int main(){
	int n , m , q ; sci(n) ; sci(m) ; sci(q) ; 
	string strings[m] ; 
	forn(i,m){
		string str   ; cin >> str ; strings[i] = str ; 
	}
	int fl , l , r , x , p ; char c ; 
	build(0,n-1,1) ; 
	while (q--){
		sci(fl) ; 
		if (fl==0){
			cin >> x >> c ;  x-- ; 
			update(0,n-1,x,1,c) ; 
		}
		if (fl == 1){
			cin >> l >> r >> p ; l-- ; r-- ;  
			int ret = 0 ; 
			node ans = query(0,n-1,l,r,1) ; 
			
			string s = ans.s ; 
			//cout << s << el ; 
			vi v ; 
			int found = s.find('@') ; 
			while (found != string::npos){
				v.pb(found) ; 
				found = s.find('@',found+1) ; 
			}
			int st = 0 ; 
			forn(i,v.size()){
				found = s.find(strings[p-1],st) ; 
				if (found !=string::npos){
					if (found < v[i]	){
						ret += 1; 
					}
				}
				st = v[i] ; 
			}
			cout << ret << el ; 
			 
		}
		if (fl == 2){
			cin >> l >> r >> p ; l-- ; r-- ; p-- ;  
			int ret = 0 ; 
			node ans = query(0,n-1,l,r,1) ; 
			string s = ans.s ; 
			int found = s.find(strings[p],0) ; 
			while (found != string::npos){
				ret += 1; 
				found = s.find(strings[p],found+1) ; 
			}
			cout << ret << el ; 
		}

	}
}

