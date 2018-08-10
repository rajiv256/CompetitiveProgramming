#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MX = 50 * 1000 + 7;
const int LG = 17;
const ll INF = 1e18;
const int IINF = 1e9;

int gcd(int x, int y) {
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int sp[MX][LG];
int a[MX];
int pw[MX];

bool isdiv(int l, int r, int x) {
    if (x == 0) return true;
    int len = r - l + 1;
    if (sp[l][pw[len]] % x) return false;
    if (sp[r - (1 << pw[len]) + 1][pw[len]] % x) return false;
    return true;
}

ll t[4 * MX];
ll mod[4 * MX];

ll get(int v) {
    return t[v] + mod[v];
}

void push(int v) {
    mod[v + v] += mod[v];
    mod[v + v + 1] += mod[v];
    mod[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, int x) {
    if (r < tl || l > tr) return;
    if (tl >= l && tr <= r) {
        mod[v] += x;
    } else {
        push(v);
        int tm = (tl + tr) >> 1;
        add(v + v, tl, tm, l, r, x);
        add(v + v + 1, tm + 1, tr, l, r, x);
        t[v] = max(get(v + v), get(v + v + 1));
    }
}

ll getMax(int v, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) return -INF;
    if (tl >= l && tr <= r) {
        return get(v);
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        ll ans = max(getMax(v + v, tl, tm, l, r), getMax(v + v + 1, tm + 1, tr, l, r));
        t[v] = max(get(v + v), get(v + v + 1));
        return ans;
    }
}

ll slw(int n) {
    ll ans = -INF;
    for (int i = 1; i <= n; i++) {
        ll s = 0, m = -INF, g = a[i];
        for (int j = i; j <= n; j++) {
            s += a[j];
            m = max(m, (ll)a[j]);
            g = gcd(g, a[j]);
            if (g * (s - m) == 16) {
                cout << i << " " << j << endl;
            }
            ans = max(ans, g * (s - m));
        }
    }
    return ans;
}
int main() {
#ifdef AZINO777
    freopen("in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(nullptr); cin.tie(nullptr);
    pw[1] = 0;
    for (int i = 2; i < MX; i++) {
        pw[i] = pw[i - 1];
        if ((1 << (pw[i] + 1)) < i) pw[i]++;
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sp[i][0] = a[i];
    }
    for (int j = 1; j < LG; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            sp[i][j] = gcd(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
        }
    }
    vector<pair<int, int> > st;
    st.emplace_back(IINF, 0);
    ll ans = -INF;
    for (int i = 1; i <= n; i++) {
        add(1, 1, n, 1, i, a[i]);
        while (st.back().first <= a[i]) {
            add(1, 1, n, st[st.size() - 2].second + 1, st.back().second, st.back().first);
            st.pop_back();
        }
        add(1, 1, n, st.back().second + 1, i, -a[i]);
        st.emplace_back(a[i], i);
        int cgcd = a[i];
        int firstPos = i;
        while (true) {
            int lg = 0, rg = firstPos;
            while (rg - lg > 1) {
                int mg = (lg + rg) >> 1;
                if (isdiv(mg, firstPos, cgcd)) {
                    rg = mg;
                } else {
                    lg = mg;
                }
            }
            ll cans = getMax(1, 1, n, rg, firstPos) * cgcd;
            ans = max(ans, cans);
            if (rg == 1) break;
            cgcd = gcd(cgcd, a[rg - 1]);
            firstPos = rg - 1;
        }
    }
    //cerr << slw(n) << endl;
   // assert(ans == slw(n));
    cout << ans << endl;
}
