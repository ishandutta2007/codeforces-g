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

constexpr int N=1e5+5;
int a[N];
int ans=0;

int32_t main() {
    fastio;
    int n; cin>>n;
    rep(i, n) cin>>a[i];
    int q; cin>>q;
    while(q--) {
        int t; cin>>t;
        if(t==1) {
            int l, r; cin>>l>>r;
            l=(l+ans-1)%n;
            r=(r+ans-1)%n;
            if(l>r) swap(l, r);
            int prv=a[r];
            memmove(a+l+1, a+l, (r-l)*sizeof(int));
            a[l]=prv;
        }
        else {
            int l, r, k; cin>>l>>r>>k;
            l=(l+ans-1)%n;
            r=(r+ans-1)%n;
            k=((k+ans-1)%n)+1;
            if(l>r) swap(l, r);
            ans=0;
            for(int i=l; i<=r; i++) ans+=(a[i]==k);
            cout<<ans<<endl;
        }
    }
}