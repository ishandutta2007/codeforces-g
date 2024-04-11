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
const int MX = 100001; 

struct Node {
    int len;
    ll numLeft, numRight;
    ll value;
    Node() {
        len = 0;
        numLeft = 0;
        numRight = 0;
        value = 0;
    }
};

Node combine(Node &a, Node &b) {
    Node res;
    res.len = a.len + b.len;
    res.numLeft = a.numLeft;
    if (a.numLeft == a.len) {
        res.numLeft += b.numLeft;
    }
    res.numRight = b.numRight;
    if (b.numRight == b.len) {
        res.numRight += a.numRight;
    }
    res.value = a.value + b.value + a.numRight * b.numLeft;
    return res;
}


const ll SZ = 262144; //set this to power of two
Node seg[2*SZ]; //segtree implementation by bqi343's Github

void update(int p, Node value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

Node query(int l, int r) {  // sum on interval [l, r]
    Node resL, resR; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);

    }
    return combine(resL,resR);
}

Node zero, one;

void solve() {
    zero.len = 1; zero.numLeft = 0; zero.numRight = 0; zero.value = 0;
    one.len = 1; one.numLeft = 1; one.numRight = 1; one.value = 1;
    int N, Q; cin >> N >> Q;
    int A[N]; F0R(i, N) cin >> A[i];
    F0R(i, N-1) {
        if(A[i] <= A[i+1]) {
            update(i, one);
        } else update(i, zero);
    }


    while(Q--) {
        int T; cin >> T;
        if (T == 1) {
            int X, Y; cin >> X >> Y; X--;
            A[X] = Y;
            if (X > 0) {
                if (A[X-1] <= A[X]) {
                    update(X-1, one);
                } else update(X-1, zero);
            } 
            if (X < N-1) {
                if (A[X] <= A[X+1]) {
                    update(X, one);
                } else update(X, zero);
            }
        } else {
            int L, R; cin >> L >> R;
            L--; R--;
            ll ans = R-L+1;
            if (R > L) ans += query(L, R-1).value;
            cout << ans << nl;
        }
    }

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}