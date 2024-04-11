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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vvi adj(n + 1);
        rep(i, n - 1) {
            int u, v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vi par[2];
        auto dfs = [&](int u, int p = -1, int c = 0) -> void {
            auto dfs = [&](int u, int p, int c, const auto& self) -> void {
                par[c].pb(u);
                for(int v: adj[u]) if(v != p) self(v, u, c ^ 1, self);
            };
            dfs(u, p, c, dfs);
        };
        dfs(1);
        vi idx[__lg(n) + 1];
        rep1(i, n) idx[__lg(i)].pb(i);
        vi ans(n + 1);
        for(int i = __lg(n); ~i; i--) {
            if(par[0].size() < par[1].size()) par[0].swap(par[1]);
            for(int v: idx[i]) {
                ans[par[0].back()] = v;
                par[0].pop_back();
            }
        }
        rep1(i, n) cout << ans[i] << ' '; cout << endl;
    }
}