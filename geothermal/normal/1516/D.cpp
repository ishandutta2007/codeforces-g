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

vi primes, leastFac;
void compPrimes(int N) {
	F0R(i, N) {
		leastFac.pb(0);
	}
	leastFac[0] = 1; leastFac[1] = 1;
	FOR(i, 2, N) {
		if (leastFac[i] == 0) {
			primes.pb(i);
			leastFac[i] = i;
		}
		for (int j = 0; j < sz(primes) && i*primes[j] < N && primes[j] <= leastFac[i]; j++) {
			leastFac[i*primes[j]] = primes[j];
		}
	}
}
void solve() {
    compPrimes(400);
    int N, Q; cin >> N >> Q;
    int A[N]; F0R(i, N) cin >> A[i];
    int lst[MX]; F0R(i, MX) lst[i] = N;
    int go[N][17];
    F0Rd(i, N) {
        go[i][0] = N;
        if (i < N-1) {
            go[i][0] = go[i+1][0];
        }
        trav(a, primes) {
            if (A[i] % a == 0) {
                ckmin(go[i][0], lst[a]);
                lst[a] = i;
                while (A[i] % a == 0) A[i] /= a;
            }
        }
        if (A[i] != 1) {
            ckmin(go[i][0], lst[A[i]]);
            lst[A[i]] = i;
        }
        FOR(j, 1, 17) {
            if (go[i][j-1] == N) {
                go[i][j] = N;
            } else {
                go[i][j] = go[go[i][j-1]][j-1];
            }
        }
    }
    while(Q--) {
        int L, R; cin >> L >> R;
        L--; 
        int ans = 1;
        F0Rd(j, 17) {
            while (L < R && go[L][j] < R) {
                ans += (1 << j);
                L = go[L][j];
            }
        }
        cout << ans << nl;
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
 
// read the question correctly (ll vs int)
// template by bqi343