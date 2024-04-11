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

constexpr int N=2e5+5;
int a[N];
ll pf[N];

int ans=0;
set<pii> s;
void chk(int i, int j) {
    if(s.find({i, j})!=s.end()) return;
    if((a[i]^a[j])==pf[j-1]-pf[i]) {
        ans++;
        s.emplace(i, j);
    }
}

int32_t main() {
    fastio;
    int n; cin>>n;
    rep1(i, n) cin>>a[i];
    rep1(i, n) pf[i]=pf[i-1]+a[i];
    rep1(i, n) {
        for(auto [j, sum]=tuple{i+1, (ll)a[i+1]}; sum<=a[i]*2&&j<n; j++, sum+=a[j]) {
            chk(i, j+1);
        }
        for(auto [j, sum]=tuple{i-1, (ll)a[i-1]}; sum<=a[i]*2&&j>1; j--, sum+=a[j]) {
            chk(j-1, i);
        }
    }
    cout<<ans<<endl;
}