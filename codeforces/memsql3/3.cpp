/*
        Code written by rajiv.
        God speed!
*/
#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define sclf(x) scanf("%lf",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100005
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ;
typedef pair<int,int> pii ;

int n , S ;
ll s[MXN] ;
ll a[MXN] ;
ll b[MXN] ;
vector<ll> VA ;
vector<ll> VB ;
bool cmp1(int i , int j){
	return (a[i]-b[i]>a[j]-b[j]) ;
}
bool cmp2(int i, int j){
	return -cmp1(i,j) ;
}
ll get(vector<ll>& v, int idx){

	if (idx <0   || idx >= v.size()){
		return 0 ;
	}
	return v[idx] ;
}
ll get(ll v[], int idx){
	if (idx < 0 || idx >= n){
		return 0 ;
	}
	return v[idx] ;
}
void assign(vector<ll>& v, int idx, ll val){
	if(idx>=0 || idx < v.size()){
		v[idx] = val ;
	}
	return ;
}


int main(){
	cin.tie(0) ;
	ios_base::sync_with_stdio(false)  ;

	cin >> n >> S ;
	memset(s,0,sizeof(s)) ;
	memset(a,0,sizeof(s)) ;
	memset(b,0,sizeof(s)) ;

	forn(i,0,n){
		cin >> s[i] >> a[i] >> b[i]  ;
		if (a[i]>b[i]){
			VA.pb(i) ;
		}
		else{
			VB.pb(i) ;
		}
	}
	sort(all(VA),cmp1) ;
	sort(all(VB),cmp2) ;

	ll H = 0 ;
	ll nA = 0 ; ll nB = 0 ; int currA = 0 ; int currB = 0 ;
	for(int i = 0 ; i < VA.size() ; i++){
		int idx = VA[i] ;
		currA += s[idx] ;

		if (currA >= S){
			nA += currA-(currA%S) ;
			currA %= S ;
		}
	}
	for(int i = 0 ; i < VB.size() ; i++){
		int idx = VB[i] ;
		currB += s[idx] ;

		if (currB >= S){
			nB += currB-(currB%S) ;
			currB %= S ;
		}
	}
	ll arem = (VA.size()==0)?0:s[VA[0]] ; ll  brem = (VB.size()==0)?0:s[VB[0]]; ll rA =nA , rB = nB ;
	int astop = 0 ; int bstop = 0  ;
	//cout << nA << sp << nB << el ;
	for(int i = 0 ; i < VA.size() ; i++){
		rA -= s[VA[i]] ;
		if (rA <=0){
			astop = i ;
			arem = -rA ;
			break ;
		}
	}
	for(int i= 0 ; i < VB.size() ; i++){
		rB -= s[VB[i]] ;
		if (rB <= 0){
			bstop = i ;
			brem = -rB ;
			break ;
		}
	}
	//cout << "here" << el ;
	//cout << astop << sp << arem << sp << bstop << sp << brem << el;
	for(int i = 0 ; i < astop ; i++){
		H += s[VA[i]]*a[VA[i]] ;
	}
	for(int i = 0 ; i < bstop ; i++){
		H += s[VB[i]]*b[VB[i]] ;
	}
	H += max(0LL,(get(s,get(VA,astop))-arem)*get(a,get(VA,astop))) ;
	H += max(0LL,(get(s,get(VB,bstop))-brem)*get(b,get(VB,bstop))) ;

	ll totrem = arem+brem ;
	for(int i = astop+1 ; i < VA.size() ; i++){
		totrem += s[VA[i]];
	}
	for(int i = bstop+1 ; i < VB.size() ; i++){
		totrem += s[VB[i]] ;
	}

	if (totrem <= S){
		ll ifA = 0;
		ll ifB = 0;
		ifA += max(0LL,arem*get(a,get(VA,astop))) ;
		ifB += max(0LL,arem*get(b,get(VA,astop))) ;
		ifA += max(0LL,brem*get(a,get(VB,bstop))) ;
		ifB += max(0LL,brem*get(b,get(VB,bstop))) ;
 		for(int i = astop+1 ; i < VA.size() ; i++){
			ifA += s[VA[i]]*a[VA[i]] ;
			ifB += s[VA[i]]*b[VA[i]] ;
		}
		for(int i = bstop+1 ; i < VB.size() ; i++){
			ifA += s[VB[i]]*a[VB[i]] ;
			ifB += s[VB[i]]*b[VB[i]] ;
		}
		H += max(ifA,ifB) ;
	}
	else{
		H = 0 ;
		for(int i = 0 ; i < VA.size() ; i++){
			H += s[VA[i]]*a[VA[i]] ;
		}
		for(int i = 0 ; i < VB.size() ; i++){
			H += s[VB[i]]*b[VB[i]] ;
		}
	}
	cout << H << el ;




}
