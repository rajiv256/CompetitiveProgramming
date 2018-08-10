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
    int n ;
    cout << "1" << el ;
    cout << "5 1 2 3 4 5" << el ;
    cout << "4 1 2 3 4" << el ;
    cin >> n ;
    if (n == 2){
        cout << "2" << el ;
        cout << "5" << el ;
        return 0 ;
    }
    cout << "1" << el ;
    cout << "5 1 2 3 4 5" << el ;
    cout << "4 1 2 3 5" << el ;
    cin >> n ;
    if (n == 2){
        cout << "2" << el ;
        cout << "4" << el ;
        return 0 ;
    }
    cout << "1" << el ;
    cout << "5 1 2 3 4 5" << el ;
    cout << "4 1 2 4 5" << el ;
    cin >> n ;
    if (n == 2){
        cout << "2" << el ;
        cout << "3" << el ;
        return 0 ;
    }
    cout << "1" << el ;
        cout << "5 1 2 3 4 5" << el ;
        cout << "4 1 3 4 5" << el ;
        cin >> n ;
        if (n == 2){
            cout << "2" << el ;
            cout << "2" << el ;
            return 0 ;
        }
    cout << "1" << el ;
        cout << "5 1 2 3 4 5" << el ;
        cout << "4 2 3 4 5" << el ;
        cin >> n ;
        if (n == 2){
            cout << "2" << el ;
            cout << "1" << el ;
            return 0 ;
    }
    return 0 ;
}