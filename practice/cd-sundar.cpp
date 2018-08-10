#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<climits>
#include<cassert>
#include<time.h>
using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define ss second
#define ff first
#define vi vector<int>
#define vl vector<ll>
#define s(n) scanf("%d",&n)
#define ll long long
#define mp make_pair
#define PII pair <int ,int >
#define PLL pair<ll,ll>
#define inf 1000*1000*1000+5
#define v(a,size,value) vi a(size,value)
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define tri pair < int , PII >
#define TRI(a,b,c) mp(a,mp(b,c))
#define xx ff
#define yy ss.ff
#define zz ss.ss
#define in(n) n = inp()
#define vii vector < PII >
#define vll vector< PLL >
#define viii vector < tri >
#define vs vector<string>
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define ok if(debug)
#define trace1(x) ok cerr << #x << ": " << x << endl;
#define trace2(x, y) ok cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)    ok      cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)  ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                << #d << ": " << d << endl;
#define trace5(a, b, c, d, e) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                     << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                    << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
ll MOD = int(1e9) + 7;

int debug = 0;
const int N = int(1e5) + 5 , LN = 18;
using namespace std;
int siz[N];
int marked[N] , level[N] , pa[LN][N] , par[N];
vi nei[N];
int subtreesize = 0;
void dfs1(int u , int v = -1, int lev = 1)
{
    int i;
    level[u] = lev;
    pa[0][u] = v;
    rep(i,sz(nei[u]))
        if(nei[u][i] != v)
            dfs1(nei[u][i],u,lev+1);
}
void precompute() //memset pa to -1 in main
{
    int i,j;
    dfs1(1);
    for(i = 1; i < LN;i++)
    {
        for(j = 0; j < N; j++)
        {
            if(pa[i-1][j] != -1)pa[i][j] = pa[i-1][pa[i-1][j]];
        }
    }
}
int lca(int u, int v)
{
    if(level[u] < level[v])swap(u,v);
    int diff = (level[u] - level[v]),i;
    rep(i,LN) if((diff>>i)&1) u = pa[i][u];
    if( u == v)return u;
    for(i = LN - 1; i >= 0;i--)
        if(pa[i][u] != pa[i][v])
        {
            u = pa[i][u];
            v = pa[i][v];
        }
    return pa[0][u];
}
int dist(int u , int v)
{
    return level[u] + level[v] - 2*level[lca(u,v)];
}

void dfs2(int u , int v = -1)
{
    siz[u] = 1;
    int i;
    rep(i,sz(nei[u]))
    {
        if(nei[u][i] != v && !marked[nei[u][i]])
        {
            dfs2(nei[u][i],u);
            siz[u] += siz[nei[u][i]];
        }
    }
}
int centroid(int node,int parent)
{
    int i;
    rep(i,sz(nei[node]))
    {
        if(!marked[nei[node][i]] && siz[nei[node][i]] > subtreesize && nei[node][i] != parent)
            return centroid(nei[node][i],node);
    }
    return node;
}
void decompose(int node , int parent)
{
    trace2(node,parent);
    subtreesize = 0;
    dfs2(node);
    subtreesize = siz[node]/2;
    int i;
    int centre = centroid(node,parent);
    par[centre] = parent;
    marked[centre] = 1;
    rep(i,sz(nei[centre]))
    {
        if(!marked[nei[centre][i]])
            decompose(nei[centre][i] , centre);
    }
}
int D[N];
void color(int x)
{
    int y = x;
    while(y != 0)
    {
        trace1(y);
        D[y] = min(D[y] , dist(x,y));
        y = par[y];
        trace5(y,x,dist(x,y),lca(x,y),D[y])
    }
}
int query(int x)
{
    int y = x;
    int ret = D[y];
    while(y != 0)
    {
        ret = min(ret, D[y] + dist(y,x));
        y = par[y];
    }
    return ret;
}
int main()
{
      int i,j,n,t,m;
      ios::sync_with_stdio(false);
    memset(D,63,sizeof(D));
    cin>>n>>m;
    rep(i,n-1)
    {
        int a,b;
        cin>>a>>b;
        nei[a].pb(b);
        nei[b].pb(a);
    }

    decompose(1,0);
    precompute();
    color(1);
    rep(i,m)
    {
        int v;
        cin>>t>>v;
        if(t == 1)
        {
            color(v);
        }
        else
        {
            cout<<query(v)<<endl;
        }
    }
}
