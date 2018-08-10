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
int pow(int a , int b){
    if (b == 0){
        return 1 ; 
    }
    return a*pow(a,b-1)  ; 
}


bool solve(map<int,int>& m,string s1, int n){
     string s = "" ; 
     forn(i,n){
         s += s1[i] ; 
     }
     string dupe = s ; 
     while (true){
        string ss = "" ; 
        if (m[(s[0]-'a')*10+s[1]-'a'] == -1){
            return false ; 
        }
       
        ss += (m[(s[0]-'a')*10+s[1]-'a']+'a') ; 
        for(int i = 2 ; i < s.size() ; i++){
            ss += s[i] ; 
        }
        s = ss ;
        //cout << s << el ;  
        if (s.size() == 1){
            
            break ; 
        }
    }
     
    if(s[0] == 'a'){
        //cout << dupe << el ; 
        return true ; 
    }
    return false ; 
}



int main(){
    
    int n , q ; 
    cin >> n >> q; 
    map<int,int> m ; 
    string s ; string s2 ; 
    forn(i,1000){
        m[i] = -1 ; 
    }
    forn(i,q){
       cin >> s ; cin >> s2 ; 
       m[(s[0]-'a')*10+s[1]-'a'] = s2[0]-'a' ; 
    }
    int count = 0 ; 
    vector<char> v ; 
    v.pb('a') ; v.pb('b') ;v.pb('c') ;v.pb('d') ;v.pb('e') ;v.pb('f') ; 
    forn(i1,6){
        forn(i2,6){
            forn(i3,6){
                forn(i4,6){
                    forn(i5,6){
                        forn(i6,6){
                            string ss = "" ;  
                            ss += v[i1] ;
                            ss += v[i2] ;
                            ss += v[i3] ;  
                            ss += v[i4] ;
                            ss += v[i5] ;
                            ss += v[i6] ;  
                            //cout << ss << el ;                           
                            if (solve(m,ss,n)){
                                count += 1 ; 
                            }
                        }
                    }
                }
            }
        }
    }
    cout << count/pow(6,6-n) << el  ; 
    return 0 ;  
    
}