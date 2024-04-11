#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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

const ll MOD=998244353;

ll exp(ll a, ll b) {
    if(!b) return 1;
    else {
        ll x=exp(a, b/2);
        if(b%2==1) return (((x*x)%MOD)*a)%MOD;
        else return (x*x)%MOD;
    }
}

int32_t main() {
    fastio;
    int n, k; cin>>n>>k;
    ll ans=0;
    ll fact[n+1]; fact[0]=1; rep1(i, n) fact[i]=(fact[i-1]*i)%MOD;
    ll inv[n+1]; inv[0]=1; rep1(i, n) inv[i]=exp(fact[i], MOD-2);
    rep1(i, n) {
        int s=n/i-1, t=k-1;
        if(s<t) continue;
        ans+=fact[s]*inv[t]%MOD*inv[s-t]; ans%=MOD;
    }
    cout<<ans<<endl;
}