#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxE = (int)1e6 + 100;
int a[maxE], b[maxE], we[maxE];
bool in_tree[maxE];
const int maxN = (int)1e5 + 100;
int p[maxN];
int get(int x) {
    if (x == p[x]) return x;
    p[x] = get(p[x]);
    return p[x];
}
bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (rand() % 2) swap(a, b);
    p[a] = b;
    return true;
}
const int LG = 20;
vector < pair < int, int > > g[maxN];
int up[LG][maxN];
int mx[LG][maxN];
int h[maxN];

void dfs(int v, int p) {
    for (auto t : g[v]) {
        int to = t.first;
        if (p == to) continue;
        h[to] = h[v] + 1;
        up[0][to] = v;
        mx[0][to] = we[t.second];
        dfs(to, v);
    }
}

int get(int a, int b) {
    int val = 0;
    if (h[a] < h[b]) swap(a, b);
    for (int i = LG - 1; i >= 0; i--) {
        if (h[a] - (1 << i) < h[b]) continue;
        val = max(val, mx[i][a]);
        a = up[i][a];
    }
    if (a == b) return val;
    for (int i = LG - 1; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            val = max(val, max(mx[i][a], mx[i][b]));
            a = up[i][a];
            b = up[i][b];
        }
    }
    return max({val, mx[0][a], mx[0][b]});
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    vector < pair < int, int > > ed;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> we[i];
        ed.emplace_back(we[i], i);
    }
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    sort(ed.begin(), ed.end());
    for (auto t : ed) {
        if (unite(a[t.second], b[t.second])) {
            in_tree[t.second] = true;
            g[a[t.second]].emplace_back(make_pair(b[t.second], t.second));
            g[b[t.second]].emplace_back(make_pair(a[t.second], t.second));
        }
    }
    dfs(1, -1);
    for (int i = 0; i + 1 < LG; i++) {
        for (int j = 1; j <= n; j++) {
            up[i + 1][j] = up[i][up[i][j]];
            mx[i + 1][j] = max(mx[i][j], mx[i][up[i][j]]);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (in_tree[i]) continue;
        cout << get(a[i], b[i]) << '\n';
    }
    return 0;
}