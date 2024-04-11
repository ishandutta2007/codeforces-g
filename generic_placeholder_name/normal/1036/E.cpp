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

struct custom_hashes {
    inline static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template<typename T1, typename T2>
    size_t operator() (pair<T1, T2> x) const {
        //it's just the boost function with a little stuff to account for uint64_t
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.fi+FIXED_RANDOM)^splitmix64(x.se+FIXED_RANDOM);
    }
};
template<typename _F, typename _T> using safe_map=gp_hash_table<_F, _T, custom_hashes>;

struct seg {
    int x1, x2, y1, y2;
    seg() {}
    seg(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {}
    int get() {return gcd(abs(x1-x2), abs(y1-y2))+1;}
};

struct line {
    ll a, b, c;
    line() {}
    line(seg& x): a(x.y1-x.y2), b(x.x2-x.x1), c(-1LL*a*x.x1-1LL*b*x.y1) {}
};

ll det(ll a, ll b, ll c, ll d){
    return a*d-b*c;
}

bool in(int x, int l, int r) {
    if(l>r) swap(l, r);
    return l<=x&&x<=r;
}

safe_map<pii, bool> m;
void process(seg& A, seg& B) {
    line X(A), Y(B);
    ll dx=det(X.c, X.b, Y.c, Y.b);
    ll dy=det(X.a, X.c, Y.a, Y.c);
    ll d=det(X.a, X.b, Y.a, Y.b);
    if(d==0||dx%d||dy%d) return;
    int x=-dx/d, y=-dy/d;
    if(!in(x, A.x1, A.x2)||!in(y, A.y1, A.y2)||!in(x, B.x1, B.x2)||!in(y, B.y1, B.y2)) return;
    m[{x, y}]=1;
}

constexpr int N=5000;
seg a[N];
ll ans=0;

int32_t main() {
    fastio;
    int n; cin>>n;
    rep(i, n) {
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        a[i]=seg(x1, y1, x2, y2);
        ans+=a[i].get();
    }
    rep(i, n) {
        m.clear();
        rep(j, i) process(a[i], a[j]);
        ans-=m.size();
    }
    cout<<ans<<endl;
}