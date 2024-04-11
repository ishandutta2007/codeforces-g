#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
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
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy

void solve() {

    int N, M; cin >> N >> M;
    vi A(N), B(N), C(M); F0R(i, N) cin >> A[i];
    F0R(i, N) cin >> B[i];
    F0R(i, M) cin >> C[i];

    F0R(i, N) {
        A[i]--; B[i]--;
    }
    F0R(i, M) C[i]--;

    set<int> need[N];
    F0R(i, N) {
        if (A[i] != B[i]) need[B[i]].ins(i);
    }
    int p = -1;
    F0R(i, N) {
        if (B[i] == C[M-1]) {
            if (A[i] != B[i] || p == -1) {
                p = i;
            }
        }
    }
    if (p == -1) {
        cout << "NO" << nl; return;
    }
    int ans[M];
    need[B[p]].erase(p);
    ans[M-1] = p;
    F0R(i, M-1) {
        if (sz(need[C[i]])) {
            ans[i] = *need[C[i]].begin();
            need[C[i]].erase(ans[i]);
        } else {
            ans[i] = p;
        }
    }

    F0R(i, N) {
        if (sz(need[i])) {
            cout << "NO" << nl; return;
        }
    }
    cout << "YES" << nl;
    F0R(i, M) {
        cout << ans[i] + 1 << " ";
    }
    cout << nl;

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343