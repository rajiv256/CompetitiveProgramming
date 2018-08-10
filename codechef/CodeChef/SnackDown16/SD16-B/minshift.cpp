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
#define MXN 100003
#define MOD 1000000007
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
	int low  ; 
	int high ;
	char minChar ; 
	int idx ; 
	
	void init(int l , int h , char c , int i){
		low = l  ;
		high = h ; 
		minChar = c ; 
		idx = i ; 
	}
	
	void merge(node n1 , node n2){
		if (n1.low==-1){
			init(n2.low,n2.high,n2.minChar,n2.idx) ; 
			return ; 
		}
		if (n2.low == -1){
			init(n1.low,n1.high,n1.minChar,n1.idx); 
			return; 
		}
		low = min(n1.low,n2.low) ; 
		high = max(n2.high,n1.high) ;
		if (n1.minChar == n2.minChar){
			minChar = n1.minChar ; 
			idx = n1.idx ;
		}
		else{
			minChar = min(n1.minChar,n2.minChar) ;
			if (minChar==n1.minChar){
				idx = n1.idx ; 
			}
			else{
				idx = n2.idx ; 
			}
		}
		
	}
	
}node;

node stree[4*MXN+8] ;
string str ; 
void build(int low, int high , int s){
	if (low > high){
		return ; 
	}
	if (low==high){
		stree[s].init(low,high,str[low],low) ; 
		return ; 
	}
	
	int mid = (low+high)/2 ; 
	
	build(low,mid,2*s) ;
	build(mid+1,high,2*s+1); 
	stree[s].merge(stree[2*s],stree[2*s+1]) ; 
	return ; 
}

void update(int low, int high,int s ,int idx , char val){
	if ((idx < low) || (idx > high)){
		return ; 
	}
	if ((low== high) && (low==idx)){
		str[low] = val ; 
		stree[s].minChar = val ; 
		stree[s].idx = idx ; 
		return ; 
	}
	int mid = (low+high)/2 ; 
	if (idx <= mid)
		update(low,mid,2*s,idx,val) ;
	if (idx > mid)
		update(mid+1,high,2*s+1,idx,val) ; 
	stree[s].merge(stree[2*s],stree[2*s+1]) ; 
	return ; 
}

node query(int low, int high , int ql , int qr , int s){
	
	if ((ql>high) || (qr<low)){
		node n ; n.init(-1,-1,'\0',-1) ; 
		return n ; 
	}
	if (ql<=low && qr>=high){
		return stree[s] ; 
	}
	
	int mid= (low+high)/2 ; 
	if (mid >= qr){
		return query(low,mid,ql,qr,2*s) ; 
	}
	else if (mid < ql){
		return query(mid+1,high,ql,qr,2*s+1) ; 
	}
	
	node temp1 = query(low,mid,ql,qr,2*s) ; 
	node temp2 = query(mid+1,high,ql,qr,2*s+1) ; 
	node n ; n.init(0,0,0,0) ;  
	n.merge(temp1,temp2) ; 
	return n ; 
}

int main(){
	
	cin >> str ; 
	memset(stree,0,sizeof(stree)) ; 
	int q ; sci(q) ; int fl ; int l , r , idx  ; char c ;    
	build(0,str.size()-1,1) ; 
	//cout << stree[1].low << sp << stree[1].high <<sp <<stree[1].minChar << sp << stree[1].idx<< el ; 
	while (q--){
		sci(fl) ; 
		if (fl==0){
			sci(idx) ; idx-- ; scanf("%c",&c) ;
			//str[idx] = c ; 
			update(0,str.size()-1,1,idx,c) ; 
		}
		if (fl ==1){
			int qidx ; 
			sci(l) ;sci(r) ; sci(qidx) ; l-- ; r-- ; qidx-- ; 
			node n = query(0,str.size()-1,l,r,1) ; 
			//cout << l << sp << n.idx << sp << qidx << el ; 
			cout << str[l+((n.idx-l+qidx)%(r-l+1))] << el ; 
			
		}
	}
	return 0 ; 
	
	
	
	
	
	
	
}






















































