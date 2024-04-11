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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int32_t main() {
    //This is why O(n^(5/3)) doesn't get proposed
    //Because solutions like this exist
    fastio;
    int n, w, q; cin>>n>>w>>q;
    int a[n], ask[q], mn[q], mx[q], ans[q]={0};
    rep(i, n) cin>>a[i];
    rep(i, q) cin>>ask[i], ask[i]=w-ask[i], mn[i]=mx[i]=a[0];
    rep(j, n) {
        const int v=a[j];
        rep(i, q) {
            mn[i]=mn[i]>v?v:mn[i];
			mx[i]=mx[i]<v?v:mx[i];
			if(mx[i]-mn[i]>ask[i]) ++ans[i], mn[i]=mx[i]=v;
        }
    }
    rep(i, q) cout<<ans[i]<<endl;
}