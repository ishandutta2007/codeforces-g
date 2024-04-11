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
const int MX = 100001;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    map<int, int> data;
    int n; cin >> n;
    ll ans = 0;
    F0R(i, n) {
        int cur = 0, minVal = 0;
        string str; cin >> str;
        F0R(j, sz(str)) {
            if (str.at(j) == '(') {
                cur++;
            } else {
                cur--;
                minVal = min(minVal, cur);
            }
        }
        if (minVal >= 0 || minVal >= cur) {
            if (data.count(cur * -1) > 0) {
                ans += data.at(cur * -1);
                if (cur == 0) ans += data.at(0);
            }
            if (cur == 0) ans++;
            if (data.count(cur) > 0) {
                int c = data.at(cur);
                data.erase(cur);
                data.insert(mp(cur, c + 1));
            } else {
                data.insert(mp(cur, 1));
            }
        }
    }

    cout << ans;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343