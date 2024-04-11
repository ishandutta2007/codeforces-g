#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

auto start = chrono::steady_clock::now();
struct custom_hashes {
    inline static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template<typename T1, typename T2>
    size_t operator() (const pair<T1, T2>& x) const {
        //it's just the boost function with a little stuff to account for uint64_t
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.fi+FIXED_RANDOM)^splitmix64(x.se+FIXED_RANDOM);
    }
};
template<typename _F> using safe_set=gp_hash_table<_F, null_type, custom_hashes>;
safe_set<pii> ban;

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    rep(i, m) {
        int u, v; cin>>u>>v;
        ban.insert({u, v});
        ban.insert({v, u});
    }
    int a[n];
    iota(a, a+n, 1);
    auto cur = chrono::steady_clock::now();
    while(chrono::duration_cast<chrono::milliseconds>(cur - start).count()<1234) {
        shuffle(a, a+n, rng);
        bool ok=1;
        rep(i, m) if(ban.find({a[i], a[(i+1)%n]})!=ban.end()) {ok=0; break;}
        if(ok) {
           rep(i, m) cout<<a[i]<<' '<<a[(i+1)%n]<<endl;
           return 0;
        }
        cur = chrono::steady_clock::now();
    }
    cout<<"-1\n";
    return 0;
}