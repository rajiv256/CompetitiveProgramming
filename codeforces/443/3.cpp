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

typedef struct bit {
	int flag ;                     // 0 means pakka 0, 1 means pakka 1 ; 2 means inverted.  -1 ante original no change
}bit ; 

void change(bit a[], int b[], char ch){
	if (ch == '&'){
		for(int i = 0 ; i < 11 ; i++){
			if (b[i]==0){
				a[i].flag = 0 ; 
			}
		}
	}
	if (ch == '|'){
		for(int i = 0 ; i < 11 ; i++){
			if (b[i] ==1){
				a[i].flag = 1; 
			}
		}
	}
	if (ch == '^'){
		for(int i = 0 ; i < 11 ; i++){
			if (b[i]==1){
				if (a[i].flag == 2){
					a[i].flag = -1 ; 
					continue; 
				}
				if (a[i].flag == 0){
					a[i].flag = 1 ; 
					continue ; 
				}
				if (a[i].flag == 1){
					a[i].flag = 0 ; 
					continue ; 
				}
				if (a[i].flag == -1){
					a[i].flag = 2 ; 
					continue; 
				}

			}
		}
	}



}

int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false)  ; 

	int n ; cin >> n ; 
	vector<char> op ; 
	vector<int> nums ;
	char ch; int x ; 
	forn(i,0,n){
		cin >> ch >> x ;
		op.pb(ch) ; 
		nums.pb(x) ;  
	} 
	bit a[11] ; 
	forn(i,0,11){
		a[i].flag = -1 ; 
	} 
	for(int i = 0 ; i < n ; i++){
		ch = op[i] ; 
		int num = nums[i] ; 
		int j = 0 ;
		int b[11] ; memset(b,0,sizeof(b))  ;  
		while (num != 0){
			b[j++] = num%2 ; 
			num /= 2 ; 
		}
		change(a,b,ch) ; 
		
	}
	int And[11] , Or[11], Xor[11] ;
	for(int i = 0 ; i < 11 ; i++){
		if (a[i].flag == 0){
			And[i] = 0 ; 
			Or[i] = 0 ; 
			Xor[i] = 0 ; 
		}
		if (a[i].flag == 1){
			And[i] = 1 ; 
			Or[i] = 1 ; 
			Xor[i] = 0 ; 
		}
		if (a[i].flag == 2){
			And[i] = 1 ; 
			Or[i] = 0 ;
			Xor[i] = 1 ;  
		}
		if (a[i].flag == -1){
			And[i] = 1 ; 
			Or[i] = 0 ; 
			Xor[i] = 0 ; 
		}
	} 

	int A = 0 , O= 0  , X =0  ;
	for(int i = 0 ; i < 10 ; i++){
		A += (1<<i)*(And[i]) ; 
		O += (1<<i)*(Or[i]) ; 
		X += (1<<i)*(Xor[i]) ; 
	} 
	if (A > 1023) A/=2 ; 
	if (O > 1023) O/= 2 ; 
	if (X > 1023) X /= 2 ; 
	cout << "3" << el ; 
	cout << "& " << A << el; 
	cout << "| " << O << el ; 
	cout << "^ " << X << el ; 


	
}






















