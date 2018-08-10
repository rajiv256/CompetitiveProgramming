    #include <vector>
    #include <list>
    #include <map>
    #include <set>
    #include <queue>
    #include <deque>
    #include <stack>
    #include <bitset>
    #include <algorithm>
    #include <functional>
    #include <numeric>          
    #include <utility>
    #include <sstream>
    #include <iostream>
    #include <iomanip>
    #include <cstdio>
    #include <cmath>
    #include <cstdlib>
    #include <ctime>

    #define PI 3.14159265358
    #define xx first
    #define yy second
    #define mp make_pair
    using namespace std;


    class PackingShapes {
    public:
        long double pow(long double x , int a){
            if (a == 0) return 1 ;
            long double temp = pow(x,a/2) ;
            if (a&1) return x*temp*temp ;
            else return temp*temp ;
        }
        long double rad(long double ang){
            return ang*(PI/180.0) ;
        }
        bool pred(int L, int B, int l, int b){
            long double rhs = (L*L+B*B-l*l-b*b)/(4*l*b) ;
            long double c = rhs*rhs ;
            long double det = 1-4.0*c ;
            if (det < 0) return false ;
            long double rdet = sqrt(det) ;
            bool b1 = ((1+rdet)/2.0<=1 || ((1-rdet)/2.0>=0 && (1-rdet)/2.0<=1)) ;
            return b1 ;
        }
    	bool check(string sh, int L , int B){
    		istringstream iss(sh) ;
    		vector<string> toks(3,"") ;
            int i = 0 ;
            do {
                iss >> toks[i++] ;
            }
            while (iss) ;
    		stringstream ss(toks[1]) ;
    		if (toks[0]=="CIRCLE"){
    			int r ; ss >> r ;
    			if (2*r <= B) return true ;
    			else return false ;
    		}

    		if (toks[0]=="RECTANGLE"){
    			int l , b ;
                ss >> l ;
                stringstream ss1(toks[2]) ;
                ss1 >> b ;
                int t1 = max(l,b) ; int t2 = min(l,b) ;
                l = t1 ; b = t2 ;
                if (l <= L && b<=B) return true ;
                if (pred(L,B,l,b)){
                    return true ;
                }
                return false ;

            }
            return false ;
    	}
    	vector <string> tryToFit(int L, int B, vector <string> S) {
            vector<string> v ;
            for(int i = 0 ; i < S.size() ; i++){
                if (check(S[i],L,B)){
                    v.push_back("YES") ;
                }
                else{
                    v.push_back("NO") ;
                }
            }
            return v ;
        }

    };

template<class T>
void printv(vector<T> v){
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i] << " " ;
    }
    cout << endl ;
}


int main(){
    PackingShapes ps = PackingShapes() ;
    vector<string> inp = {"RECTANGLE 90 25"} ;
    vector<string> ans = ps.tryToFit(82,81,inp) ;
    printv<string>(ans) ;
}
