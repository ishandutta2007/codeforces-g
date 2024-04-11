#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma,popcnt")

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
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vi a(n), b(n);
        rep(i, n) cin >> a[i], --a[i];
        rep(i, n) cin >> b[i], --b[i];
        vi posA(n);
        rep(i, n) posA[a[i]] = i;
        rep(i, n) b[i] = posA[b[i]];
        vi cyc;
        vb vis(n);
        rep(i, n) if(!vis[i]) {
            int s = 0;
            for(int j = i; !vis[j]; j = b[j]) vis[j] = 1, s++;
            if(s > 1) cyc.pb(s - (s & 1));
        }
        sort(all(cyc));
        int l = 1, r = n;
        bool ori = 1;
        ll ans = 0;
        for(int sz: cyc) {
            int p = ori ? r : l, o = r + l - p;
            ans += r - l, r--, l++;
            rep(_, sz - 2) {
                if(ori) ans += p - l, p = l++;
                else ans += r - p, p = r--;
                ori ^= 1;
            }
            ans += abs(o - p);
        }
        cout << ans << endl;
    }
}