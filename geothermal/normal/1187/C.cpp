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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    vpi badQueries;
    bool inc[N-1];
    F0R(i, N-1) inc[i] = false;
    F0R(i, M) {
        int T, L, R; cin >> T >> L >> R;
        L--; R--;
        if (T == 1) {
            FOR(j, L, R) inc[j] = true;
        } else {
            badQueries.pb(mp(L, R));
        }
    }

    F0R(i, sz(badQueries)) {
        FOR(j, badQueries[i].f, badQueries[i].s) {
            if (!inc[j]) goto okay;
        }

        cout << "NO" << endl; return 0;
        okay:;
    }

    vi ans;
    int cur = 10000;
    F0R(i, N-1) {
        ans.pb(cur);
        cur--; if (inc[i]) cur += 2;
    }
    ans.pb(cur);

    cout << "YES" << endl;
    F0R(i, N) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343