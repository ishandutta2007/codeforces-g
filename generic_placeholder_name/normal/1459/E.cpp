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

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) {
        int n, _; cin>>n>>_;
        vector<array<int, 3>> a;
        rep(i, n) rep(j, n) {
            int x; cin>>x;
            a.pb({i, j, --x});
        }
        auto inc = [&n](int& x) mutable {x++; if(x==n) x=0;};
        auto dec = [&n](int& x) mutable {if(x==0) x=n; x--;};
        pii x={0, 0}, y={1, 0}, z={2, 0};
        string q; cin>>q;
        for(char t: q) {
            switch(t) {
                case 'D':
                    inc(x.se);
                    break;
                case 'U':
                    dec(x.se);
                    break;
                case 'L':
                    dec(y.se);
                    break;
                case 'R':
                    inc(y.se);
                    break;
                case 'C':
                    swap(x, z);
                    break;
                case 'I':
                    swap(y, z);
                    break;
                default:
                    assert(0);
                    break;
            }
        }
        vvi ans(n, vi(n));
        for(auto& v: a) {
            ans[(v[x.fi]+x.se)%n][(v[y.fi]+y.se)%n]=(v[z.fi]+z.se)%n;
        }
        rep(i, n) rep(j, n) cout<<ans[i][j]+1<<" \n"[j+1==n];
        cout<<endl;
    }
}