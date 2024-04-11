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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

template<typename T, typename U>
void ckmax(T& a, U b) {a=a<b?b:a;}

constexpr int16_t N=105, M=105;
int16_t dp[N][N*M];

int32_t main() {
    fastio;
    int n; cin>>n;
    memset(dp, -1, sizeof(dp));
    dp[0][0]=0;
    int16_t sa=0, sb=0;
    rep(c, n) {
        int16_t a, b; cin>>a>>b;
        for(auto i=c; ~i; i--) {
            for(auto j=sa; ~j; j--) {
                if(~dp[i][j]) ckmax(dp[i+1][j+a], dp[i][j]+b);
            }
        }
        sa+=a, sb+=b;
    }
    rep1(i, n) {
        int16_t ans=0;
        rep(j, sa+1) if(~dp[i][j]) ckmax(ans, min(2*j, dp[i][j]+sb));
        cout<<ans/2<<(ans&1?".5 ":" ");
    }
    cout<<endl;
}