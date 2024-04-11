#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200001; 

vector<vi> facs(MX);
vector<vector<bool>> spec(MX);

struct Seg {

ll SZ = 262144; //set this to power of two
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

ll combine(ll a, ll b) { return a+b; }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] += value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = 0, resR = 0; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}
};

Seg seg1, seg2;

void solve() {

    FOR(i, 1, MX) {
        int val = i;
        if (val % 2 == 0) val /= 2;
        for (int j = val; j < MX; j += val) {
            if (j > i) { 
                facs[j].pb(i);
                spec[j].pb((j%i)!=0);
            }
        }
    }

    int N; cin >> N;
    vector<pair<int, pi>> qs;
    F0R(i, N) {
        int X, Y; cin >> X >> Y;
        qs.pb({Y, {X, i}});
    }

    int p = 1;
    sort(all(qs));
    ll ans[N];
    trav(a, qs) {
        while (p <= a.f) {
            vi curSpec, nonSpec;
            F0Rd(i, sz(facs[p])) {
                seg1.update(facs[p][i], sz(facs[p]) - i - 1);
                seg2.update(facs[p][i], ub(all(curSpec), p - facs[p][i]) - curSpec.begin());
                if (spec[p][i]) {
                    curSpec.pb(facs[p][i]);
                    seg2.update(facs[p][i], ub(all(nonSpec), p - facs[p][i]) - nonSpec.begin());
                } else { 
                    nonSpec.pb(facs[p][i]);
                }
            }
            //dbg(p, facs[p], seg1.query(3, 3), seg2.query(3, 3));
            p++;
        }
        ll dif = (a.f - a.s.f + 1);
        ans[a.s.s] = dif * (dif-1) * (dif-2) / 6;
        ans[a.s.s] -= seg1.query(a.s.f, a.f);
        ans[a.s.s] += seg2.query(a.s.f, a.f);
    }

    F0R(i, N) {
        cout << ans[i] << nl;
    }


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}