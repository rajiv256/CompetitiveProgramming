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

int main(){
    int n , a , b , c , d ;
    sci(n) ; sci(a) ; sci(b) ; sci(c) ; sci(d) ;
    int arr[4] ;
    arr[0] = a+b ; arr[1] = a+c ; arr[2] = b+d ; arr[3] = d+c ;
    int maxi = max(arr[0],max(arr[1],max(arr[2],arr[3]))) ;
    ll cnt = 0 ;

    //cout << maxi << sp << arr[0] << sp << arr[1] << sp << arr[2] << sp << arr[3] << el ;

        for(int j = 1 ; j <= n ; j++){
            if ((maxi+j - arr[0] <= n) && (maxi+j-arr[1] <= n) && (maxi+j-arr[2] <= n) && (maxi+j-arr[3] <= n)){
                cnt += n ;
            }
        }



    cout << cnt << el ;
    return 0 ;

}