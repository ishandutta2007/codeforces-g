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
const int MX = 300011; //check the limits, dummy

vector<vi> graph(MX);
int A[MX];
int P[MX];
int D[MX];
int invord[MX];
ll ans = 0;
int ord[MX];
int lo[MX];
int x = 1, y, z = 1;
int np = 1;
int post[MX];
void parDFS(int v, int p, int d) {
    P[v] = p;
    D[v] = d;
    lo[v] = A[v];
    trav(a, graph[v]) {
        if (a != p) {
            parDFS(a, v, d+1);
            ckmin(lo[v], lo[a]);
        }
    }
}

void go(int v, int p) {
    if (A[v] < A[0]) {
        ans += D[v];
    }
    ord[v] = z; z++;
    if (A[v] >= A[0]) {
        if (y != A[v]) {
            cout << "NO" << nl; exit(0);
        }
        y++; 
    }
    vpi vals;
    trav(a, graph[v]) {
        if (a != p) {
            vals.pb({lo[a], a});
        }
    }
    sort(all(vals));
    /*int cur = 1;
    x++;*/
    trav(a, vals) {
        /*int k = go(a.s, v, x);
        x += k; cur += k;*/
        go(a.s, v);
    }
    if (A[v] < A[0]) {
        if (x != A[v]) {
            cout << "NO" << nl; exit(0);
        }
        x++;
    }
    //return cur;
}

void postDFS(int v, int p) {
    vpi vals;
    trav(a, graph[v]) {
        if (a != p) {
            vals.pb({A[a], a});
        }
    }
    sort(all(vals));
    trav(a, vals) {
        postDFS(a.s, v);
    }
    if (np != A[v] && A[v] < A[0]) {
        cout << "NO" << nl; exit(0);
    }
}


void solve() {

    int N; cin >> N;
    F0R(i, N) cin >> A[i];
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].pb(Y); graph[Y].pb(X);
    }

    parDFS(0, -1, 0);
    if (A[0] > 1) {
        int v = 0; F0R(i, N) if (A[i] == A[0] - 1) v = i;
        int hi = 0;
        while (v != 0) {
            ans++;
            ckmax(hi, A[P[v]]);
            swap(A[P[v]], A[v]);
            v = P[v];
        }
        if (A[0] + ans != hi) {
            cout << "NO" << nl; return;
        }
    }

    y = A[0];

    /*int nxt = 0;
    FORd(i, 1, A[0] + 1) {
        invord[i] = nxt;
        nxt++;
    }
    FOR(i, A[0] + 1, N+1) {
        invord[i] = nxt; nxt++;
    }*/
    go(0, -1);
    cout << "YES" << nl;
    cout << ans << nl;
    F0R(i, N) cout << ord[i] << " ";
    cout << nl;

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