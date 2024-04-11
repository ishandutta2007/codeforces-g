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
    fastio;
    constexpr int N=1e7+1;
    vi pos[N]; rep(i, N) pos[i].reserve(2); 
    int x, y; ll mn=LLONG_MAX;
    int n; cin>>n;
    int a[n+1];
    rep1(i, n) {
        cin>>a[i]; if(pos[a[i]].size()<2) pos[a[i]].pb(i);
    }
    for(int i=1; i<N; i++) {
        vi p;
        for(int j=i; j<N; j+=i) {
            for(int k=0; k<pos[j].size()&&p.size()<2; k++) p.pb(pos[j][k]);
            if(p.size()>=2) {
                const int cx=p[0], cy=p[1];
                if(mn>1LL*a[cx]*a[cy]/i) {
                    mn=1LL*a[cx]*a[p[1]]/i;
                    x=cx, y=cy;
                }
                break;
            }
        }
    }
    if(x>y) swap(x, y);
    cout<<x<<' '<<y<<endl;
}