#include <bits/stdc++.h> 


using namespace std ; 

#define REP(i,st,en) for(int i=st;i<en;i++)
#define sp " "
#define el endl 

int r , c ,n  ; 

int a[8][200][200] ; 
bool mark[200][200] ; 
void print(int x){
	REP(i,0,r){
		REP(j,0,c){
			if (a[x][i][j] >=0){
				cout << 'O' ; 
			}
			else 
				cout << '.' ; 
			//cout << a[x][i][j] << sp ; 
		}
		cout << el ; 
	}
}
bool valid(int i , int j){
	if (i>=0 && i <r && j>=0 && j<c)
		return true ; 
	return false ; 
}
void detonate(int x){
	REP(i,0,r){
		REP(j,0,c){
			a[x][i][j] = a[x-1][i][j] +1 ;
		}
	}
	memset(mark,false,sizeof(mark)) ; 
	REP(i,0,r){
		REP(j,0,c){
			if (a[x][i][j]==3){
				mark[i][j] = true ;  
				if (valid(i+1,j)) mark[i+1][j] = true ; 
				if (valid(i-1,j)) mark[i-1][j] = true ; 
				if (valid(i,j+1)) mark[i][j+1] = true ; 
				if (valid(i,j-1)) mark[i][j-1] = true ; 
				
			}
		}
	}
	REP(i,0,r){
		REP(j,0,c){
			if (mark[i][j]){
				a[x][i][j] = -1 ; 
			}
		}
	}

	
}


int main(){
	ios_base::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	cin >> r >> c >> n ; 
	char ch ;

	for(int i = 0 ; i < 200 ; i++){
		for(int j = 0 ; j < 200 ; j++){
			a[0][i][j] = -1 ; 
		}
	}

	REP(i,0,r){
		REP(j,0,c){
			 cin >> ch ;
			 if (ch =='O') 
			 	a[0][i][j] = 0 ;  
		}
	}
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			if (a[0][i][j] == 0){
				a[1][i][j] = 1 ;
			}
			else
				a[1][i][j] = a[0][i][j] ;
		}
	}
	
	for(int i = 2 ; i <= 7 ; i++){
		detonate(i) ;
	}
	if (n > 4)
	for(int i = 1 ; i <= 4 ; i++){
		if ((n-i)%4 == 0){
			print(i) ; 
			break ; 
		}
	}
	else{
		print(n) ; 
	} 


}