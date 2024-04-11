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

ll gcd(ll A, ll B) {
    if (A == 0) return B;
    if (A > B) {
        ll C = A;
        A = B;
        B = C;
    }
    return gcd(B % A, A);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, K; cin >> N >> K;
    bool valid[K]; F0R(i, K) valid[i] = false;
    valid[0] = true;
    set<int> used;
    int GCD = K;
    F0R(i, N) {
        int A; cin >> A; A = A % K;
        if (A == 0) {
            continue;
        }
        GCD = gcd(GCD, A);

    }
    for (int j = 0; j < K; j += GCD) {
        valid[j] = true;
    }

    int count = 0; F0R(i, K) if (valid[i]) count++;
    cout << count << endl;
    F0R(i, K) {
        if (valid[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343