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

constexpr int N=1<<23;
int n, m;
bitset<N> vis;

inline int read() {
	int x=0, f=1; char c=getchar();
	while (c<'0'||c>'9') {if(c=='-') f=-f; c=getchar();}
	while (c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-'0'; c=getchar();}
	return x*f;
}

void dfs(int x) {
    vis[x]=1;
    if(x<(1<<n)) dfs(x+(1<<n));
    else {
        rep(i, n) if((!(x&(1<<i)))&&!vis[x|(1<<i)]) dfs(x|(1<<i));
        if(!vis[(2<<n)-x-1]) dfs((2<<n)-x-1);
    }
}

int32_t main() {
    n=read(), m=read();
    rep(i, 1<<n) vis[i]=1;
    rep(i, m) {int x=read(); vis[x]=0;}
    int ans=0;
    rep(i, 1<<n) if(!vis[i]) ans++, dfs(i);
    cout<<ans<<endl;
}