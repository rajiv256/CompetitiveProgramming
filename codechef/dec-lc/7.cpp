/*
 		Resilience is the greatest of all virtues.
 		Code by rajiv
 */
 #include <iostream>
 #include <cstring>
 #include <vector>
 #include <map>
 #include <set>
 #include <stack>
 #include <queue>
 #include <deque>
 #include <sstream>
 #include <iomanip>
 #include <cassert>
 #include <sys/time.h>
 #include <algorithm>
 #include <bitset>
 #include <cmath>
 #include <functional>
 #include <cmath>

 using namespace std ;

 #define xx first
 #define yy second
 #define ll long long
 #define ld long double
 #define el (char)0x0A
 #define sp " "
 #define pb push_back
 #define mp make_pair
 #define all(x) (x).begin(),(x).end()
 #define clr(x) memset((x),0,sizeof(x))
 #define uint unsigned int
 #define abs(x) ((x<=0)?(-x):(x))
 #define CASET  int t;cin>>t;while(t--)
 #define FORN(i,x,y) for(int i=x;i<y;i++)
 #define MAXN 100005
 #define INF 10000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 #define PDD pair<double,double>

 const int SZ = 1000050 ;
 PDD C1[SZ] ;
 PDD C2[SZ] ;

 PDD pivot ;

 typedef struct line{
     double a , b , c ;
 }line ;
 double slope(PDD p1, PDD p2){
     if (p2.xx == p1.xx){
         return INF ;
     }
     return ((p2.yy-p1.yy)/(p2.xx-p1.xx));
 }
 line twopform(PDD p1, PDD p2){
     double sl = slope(p1,p2) ;
     line ans ;
     if (sl == INF){
         ans.a = 1 ; ans.c = -p1.xx ; ans.b = 0 ;
         return ans ;
     }
     if (sl == 0){
         ans.a = 0 ; ans.b = 1 ; ans.c = -p1.yy ;
         return ans ;
     }
     ans.a = -sl ; ans.b = 1 ; ans.c = -p1.yy + sl*p1.xx ;
     return ans ;
 }

 double orientation(const PDD& piv, const PDD& p1, const PDD& p2){
     double a1 = p1.xx-piv.xx ; double b1 = p1.yy-piv.yy ;
     double a2 = p2.xx-piv.xx ; double b2 = p2.yy-piv.yy ;
     return (a1*b2-a2*b1) ;
 }

 bool cmp(const PDD& p1, const PDD& p2){
     if (orientation(pivot,p1,p2)>=0){
         return true  ;
     }
     return false ;
 }
 int pval(line l, PDD p){
     return (l.a*p.xx + l.b*p.yy+l.c) ;
 }
 int ndel(line l, vector<PDD>& rp, vector<PDD>&  bp){
     int gt[2] ; int lt[2] ;  int et[2] ;
     clr(gt) ; clr(lt) ; clr(et) ;
     for(int i = 0 ; i < rp.size() ; i++){
         if (pval(l,rp[i])>0){
             gt[0]++ ;
         }
         else if (pval(l,rp[i])<0){
             lt[0]++ ;
         }
         else et[0]++ ;
     }
     for(int i = 0 ; i < bp.size() ; i++){
         if (pval(l,bp[i])>0){
             gt[1]++ ;
         }
         else if (pval(l,bp[i])<0){
             lt[1]++ ;
         }
         else et[1]++ ;
     }

     return min(lt[0]+gt[1],lt[1]+gt[0]) ;
 }

int convexHull(vector<PDD>& points, PDD C[]){
     if (points.size() <= 2){
         return 0;
     }
     pivot = points[0] ;
     int pidx = 0  ;
     for(int i = 1 ; i < points.size() ; i++){
        if (pivot.yy>points[i].yy || (pivot.yy == points[i].yy && pivot.xx > points[i].xx)) {
            pivot = points[i] ;
            pidx = i ;
        }
     }
     swap(points[0],points[pidx]) ;
     pivot = points[0] ;
     sort(points.begin()+1,points.end(),cmp) ;

     C[0] = points[0] ;
     C[1] = points[1] ;
     C[2] = points[2] ;
     int sz = 3 ;
     for(int i = 3 ; i < points.size() ; i++){
         while (sz >=2 && orientation(C[sz-2],C[sz-1],points[i])<=0){
             sz-- ;
         }
         C[sz] = points[i] ;
         sz++ ;
     }
     return sz ;
 }
 PDD poi(line l1, line l2){
     PDD p ;
     if ((l1.a*l2.b - l2.a*l1.b) == 0){
         return mp(INF,INF) ;
     }
     p.xx = (l1.b*l2.c - l2.b*l1.c)/(l1.a*l2.b - l2.a*l1.b) ;
     p.yy = (l2.a*l1.c - l1.a*l2.c)/(l1.a*l2.b - l2.a*l1.b) ;
     return p ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    CASET{
        int N , M ;
        cin >> N  >> M ;
        vector<PDD > rp , bp ;
        PDD rmid , bmid ;
        double x , y ;
        int ans = 1E9+10 ;
        FORN(i,0,N){
            cin >> x >> y ;
            rp.pb(mp(x,y)) ;
            rmid.xx += x ;
            rmid.yy += y ;
        }
        FORN(i,0,M){
            cin >> x >>y ;
            bp.pb(mp(x,y)) ;
            bmid.xx += x ;
            bmid.yy += y ;
        }
        rmid.xx /= N ; rmid.yy /= N ;
        bmid.xx /= M ; bmid.yy /= M ;
        if (rmid == bmid){
            ans = min(ans,(int)rp.size()/2 + (int)bp.size()/2) ;
        }
        else{
            line l = twopform(rmid,bmid) ;
            ans = min(ans,ndel(l,rp,bp)) ;
        }
        for(int i = 0 ; i < rp.size() ; i++){
            for(int j = i+1 ; j < rp.size() ; j++){
                line l = twopform(rp[i],rp[j]) ;
                ans = min(ans,ndel(l,rp,bp)) ;
            }
        }
        for(int i = 0 ; i < bp.size() ; i++){
            for(int j = i+1 ; j < bp.size() ; j++){
                line l = twopform(bp[i],bp[j]) ;
                ans = min(ans,ndel(l,rp,bp)) ;
            }
        }
        for(int i = 0 ; i < rp.size() ; i++){
            for(int j = 0 ; j < bp.size() ; j++){
                line l = twopform(rp[i],bp[j]) ;
                ans = min(ans,ndel(l,rp,bp)) ;
            }
        }
        cout << ans << el ;
        // line mpline = twopform(rmid,bmid) ;
        // ans = ndel(mpline,rp,bp) ;
        // int sz1 = convexHull(rp,C1) ;
        // int sz2 = convexHull(bp,C2) ;
        // vector<PDD> pois ;
        // for(int i = 0 ; i < sz1 ; i++){
        //     for(int j = 0 ; j < sz2 ; j++){
        //         PDD isec = poi(twopform(C1[i],C1[(i+1)%sz1]),twopform(C2[j],C2[(j+1)%sz2])) ;
        //         if (isec.xx == INF && isec.yy == INF){   // This means either the lines are parallel or doesn't intersect at all
        //             // Calculate for this line the number of points to remove.
        //             continue ;
        //         }
        //         pois.pb(isec) ;
        //     }
        // }
        //
        // for(int i = 0 ; i < pois.size() ; i++){
        //     for(int j = i+1 ; j < pois.size() ; j++){
        //         line l = twopform(pois[i],pois[j]) ;
        //         ans = min(ans,ndel(l,rp,bp)) ;
        //     }
        // }
        //
        // cout << ans << el ;

    }


 }
