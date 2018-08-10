/*
 * 2.cpp
 *
 *  Created on: 11-Jun-2016
 *      Author: rajiv
 */
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

bool isValid(int idx, int n){
	if ((idx < 0) || (idx >=n)){
		return false ; 
	}
	return true ; 
}



int main(){
	int n , a ; sci(n) ; sci(a) ; 
	a--  ; 
	int arr[n] ; 
	forn(i,n){
		sci(arr[i]) ; 
	}
	int it1 = a-1 ; int it2 = a+1 ; 
	int ans = 0 ; 
	if (arr[a]==1)
		ans = 1; 
	//cout << ans << el ; 
	while (isValid(it1,n) || isValid(it2,n)){
		
		if (!isValid(it1,n) && (arr[it2]==1)){
			 
			ans++ ; 
		}
		else if (!isValid(it2,n) && (arr[it1]==1)){
			//cout << "fuck!!" << el ; 
			ans++ ; 
		}
		else if ((isValid(it1,n) && isValid(it2,n))&& (arr[it1] != arr[it2])){
			//cout << "fuck1!!" << el ;	
			
		}
		else if ((isValid(it1,n) && isValid(it2,n))&& (arr[it1]==arr[it2]) && arr[it1]==1){
			//cout << "fuck2!!" << el ;
			ans+=2 ; 
		}
		//cout << it1 << sp << it2 <<sp<< ans << el ; 
		it1-- ; it2++ ; 
	}
	printf("%d\n",ans) ; 
	return 0 ; 
}

























