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

namespace Factor {
    namespace { //helper functions
        ll multmod(ll a, ll b, ll p) {
            a%=p, b%=p;
            if(a<1e18/b) return (a*b)%p;
            else {
                ll res=0;
                while(b) {
                    if(b&1) res=(res+a)%p;
                    (a*=2)%=p;
                    b>>=1;
                }
                return res;
            }
        }

        ll exp(ll x, ll y, ll p) {
            if(!y) return 1;
            else {
                ll r=exp(x, y/2, p);
                if(y%2==0) return multmod(r, r, p);
                else return multmod(multmod(r, r, p), x, p);
            }
        }

        constexpr int MAX_SIEVE_VALUE=4000000;
        bool isprime[MAX_SIEVE_VALUE+1];
        bool _init=0;
        inline void init() { //sieve for small primes
            _init=1;
            int n=MAX_SIEVE_VALUE;
            memset(isprime, true, sizeof(isprime));
            isprime[0]=isprime[1]=0;
            for(ll p=2; p*p<=n; p++) if(isprime[p]) {
                for(ll i=p*p; i<=n; i+=p) isprime[i]=0;
            }
        }

        bool test(ll n, ll a, ll d, int s) { //miller-rabin test
            ll x=exp(a, d, n);
            if(x==1||x==n-1) return 0;
            rep(_, s-1) {
                x=exp(x, 2, n);
                if (x==n-1) return 0;
            }
            return 1;
        }

        bool miller_rabin(ll n) { //miller-rabin, deterministic up until long long
            if (n<2) return 0;
            int r=0;
            ll d=n-1;
            while((d&1)==0) d>>=1, r++;
            for(int a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
                if (n==a) return 1;
                if (test(n, a, d, r)) return 0;
            }
            return 1;
        }

        long long brent(long long n, long long x0=2, long long c=1) {
            long long x = x0;
            long long g = 1;
            long long q = 1;
            long long xs, y;

            int m = 128;
            int l = 1;
            while (g == 1) {
                y = x;
                for (int i = 1; i < l; i++)
                    x = (exp(x, 2, n) + c) % n;
                int k = 0;
                while (k < l && g == 1) {
                    xs = x;
                    for (int i = 0; i < m && i < l - k; i++) {
                        x = (exp(x, 2, n) + c) % n;
                        q = multmod(q, abs(y - x), n);
                    }
                    g = gcd(q, n);
                    k += m;
                }
                l *= 2;
            }
            if (g == n) {
                do {
                    xs = (exp(xs, 2, n) + c) % n;
                    g = gcd(abs(xs - y), n);
                } while (g == 1);
            }
            return g;
        }
    }

    bool is_prime(ll n) {
        if(!_init) init();
        if(n<=MAX_SIEVE_VALUE) return isprime[n];
        else return miller_rabin(n);
    }

    ll pollard(ll n) { //get random divisor
        if (n==1) return n;
        if (n%2==0) return 2;
        ll ans=brent(n);
        while(ans==n||ans==1) {
            mt19937::result_type seed=chrono::steady_clock::now().time_since_epoch().count();
            auto rng=bind(uniform_int_distribution<ll>(2, n-1), mt19937(seed));
            ll x=rng();
            auto rng2=bind(uniform_int_distribution<ll>(1, n-1), mt19937(seed));
            ll c=rng2();
            ans=brent(n, x, c);
        }
        return ans;
    }

    vll get_prime_factors(ll n) {
        if(n==1) return vll{};
        if(is_prime(n)) return vll{n};
        vll ans;
        for(int i=2; 1LL*i*i*i<=n; i++) {
            if(n%i==0) {
                ans.pb(i);
                while(n%i==0) n/=i;
            }
        }
        if(n>1) {
            if(is_prime(n)) ans.pb(n);
            else {
                ll x=pollard(n);
                ans.pb(x); ans.pb(n/x);
            }
        }
        return ans;
    }
}

gp_hash_table<ll, vll> m, d;

bool solve_2(ll a, ll b, ll n) {
	ll inv=Factor::exp(b, a-2, a);
	ll t=(n%a)*inv%a;
	return n>=b*t;
}

constexpr ll INF=2e18;
bool solve_3(vll& a, ll n) {
    using pil=pair<int, ll>;
    using pli=pair<ll, int>;
    int mn=1e9; for(auto& it: a) mn=min(mn, (int)it);
    ll all=1; for(ll& it: a) all*=it;
    if(d.find(all)!=d.end()) return d[all][n%mn]<=n;
    vector<vector<pil>> adj(mn);
    rep(i, mn) for(auto& it: a) if(it!=mn) adj[i].eb((i+it)%mn, it);
    vll dist(mn, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.emplace(0, 0); dist[0]=0;
    while(!pq.empty()) {
        int u=pq.top().se; pq.pop();
        for(auto& v: adj[u]) if(dist[v.fi]>dist[u]+v.se) {
            dist[v.fi]=dist[u]+v.se;
            pq.emplace(dist[v.fi], v.fi);
        }
    }
    d[all]=dist;
    return dist[n%mn]<=n;
}

int32_t main() {
    fastio;
    int t; cin>>t; while(t--) {
        ll n, k; cin>>n>>k;
        if(k==1) {cout<<"NO\n"; continue;}
        if(m.find(k)==m.end()) m[k]=Factor::get_prime_factors(k);
        if(m[k].size()==1) cout<<(n%k==0?"YES\n":"NO\n");
        else if(m[k].size()==2) cout<<(solve_2(m[k][0], m[k][1], n)?"YES\n":"NO\n");
        else cout<<(solve_3(m[k], n)?"YES\n":"NO\n");
    }
}