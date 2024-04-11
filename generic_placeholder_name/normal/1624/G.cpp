#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

struct dsu {
    vi d;
    int cmp;
    dsu(int n): d(n, -1), cmp(n) {}
    int find(int x) {return d[x] < 0 ? x : d[x] = find(d[x]);}
    void join(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(d[x] > d[y]) swap(x, y);
        d[x] += d[y]; d[y] = x;
        --cmp;
    }
};

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        vector<tuple<int, int, int>> edges(m);
        for(auto& e: edges) {
            int u, v, c; cin >> u >> v >> c; --u, --v;
            e = {u, v, c};
        }
        int ans = 0;
        for(int bit = 30; ~bit; bit--) {
            vector<tuple<int, int, int>> zero;
            for(auto& [u, v, c]: edges) if(!((c >> bit) & 1)) zero.eb(u, v, c);
            dsu d(n);
            for(auto& [u, v, c]: zero) d.join(u, v);
            if(d.cmp == 1) edges = move(zero);
            else ans += 1 << bit;
        }
        cout << ans << endl;
    }
}