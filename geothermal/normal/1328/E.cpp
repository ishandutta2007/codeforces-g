#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 200001; //check the limits, dummy

vector<vi> graph(MX);
int par[MX];
int ord[MX], pos[MX], out[MX];
int ct = 0;

void dfs(int v, int p) {
    ord[ct] = v; pos[v] = ct; ct++;
    par[v] = max(p, 0);
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        dfs(nxt, v);
    }
    out[v] = ct;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    F0R(i, N-1) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B);
        graph[B].pb(A);
    }
    dfs(0, 0);

    F0R(i, M) {
        int K; cin >> K;
        vi query(K); F0R(i, K) cin >> query[i];
        F0R(i, K) {
            query[i]--; query[i] = par[query[i]];
        }
        int cur = query[0];
        FOR(i, 1, K) {
            int nxt = query[i];
            if (nxt == cur) continue;
            if (pos[nxt] < pos[cur] && pos[cur] < out[nxt]) continue;
            if (pos[cur] < pos[nxt] && pos[nxt] < out[cur]) {
                cur = nxt;
                continue;
            }
            cout << "NO" << '\n'; goto bad;
        }
        cout << "YES" << '\n';
        bad:
        ;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343