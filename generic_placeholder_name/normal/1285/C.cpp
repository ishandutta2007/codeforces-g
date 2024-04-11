#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#pragma 03

using namespace std;
using namespace __gnu_pbds;

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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define lcm(a, b) (a)*(b)/gcd((a), (b))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (ll i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

ll exp(ll a, ll b) {
    if(b==0) return 1;
    else {
        ll x=exp(a, b/2);
        if(b%2) return x*x*a;
        else return x*x;
    }
}

void solve(ll n) {
    if(n==1) cout<<"1 1";
    else {
        pll ans=mp(n, n);
        map<ll, int> m;
        ll tmp=n;
        for(ll i=2; i<=sqrt(tmp); i++) while(!(tmp%i)) {tmp/=i; m[i]++;}
        if(tmp!=1) m[tmp]++;
        vll v; for(auto it: m) v.pb(exp(it.fi, it.se));
        rep(i, 1<<v.size()) {
            ll num=1;
            rep(j, v.size()){
                ll x=i&(1<<j);
                if(x) num*=v[j];
            }
		if (max(num, n/num)<max(ans.fi, ans.se)) ans=mp(num, n/num);
        }
        cout<<ans.fi<<' '<<ans.se;
    }
}

int32_t main() {
    fastio;
    ll n; cin>>n; solve(n);
}