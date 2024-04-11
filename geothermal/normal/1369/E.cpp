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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    int W[N]; F0R(i, N) cin >> W[i];

    int C[N];
    vpi E[N];
    F0R(i, N) {
        C[i] = 0;
    }
    F0R(i, M) {
        int A, B; cin >> A >> B; A--; B--;
        E[A].pb({B, i});
        E[B].pb({A, i});
        C[A]++;
        C[B]++;
    }

    bool found[M]; F0R(i, M) found[i] = false;
    queue<int> q;
    F0R(i, N) {
        if (C[i] <= W[i]) {
            q.push(i);
        }
    }
    vi ans;
    while (!q.empty()) {
        int c = q.front(); q.pop();
        trav(a, E[c]) {
            if (!found[a.s]) {
                found[a.s] = true; ans.pb(a.s);
                C[a.f]--;
                if (C[a.f] == W[a.f]) q.push(a.f);
            }
        }
    }

    if (sz(ans) == M) {
        cout << "ALIVE" << nl;
        F0Rd(i, M) {
            cout << ans[i]+1 << " ";
        }
        cout << nl;
    } else {
        cout << "DEAD" << nl;
    }


	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343