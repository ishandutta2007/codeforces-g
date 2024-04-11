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

string sum(string A, string B) {
    bool carry = false;
    vector<int> digA, digB;
    F0Rd(i, sz(A)) {
        digA.pb(A[i] - '0');
    }
    F0Rd(i, sz(B)) {
        digB.pb(B[i] - '0');
    }
    while (sz(digA) < sz(digB)) {
        digA.pb(0);
    }
    while (sz(digB) < sz(digA)) {
        digB.pb(0);
    }

    vector<int> digC;
    F0R(i, sz(digA)) {
        int cur = digA[i] + digB[i];
        if (carry) {
            cur++;
        }
        if (cur < 10) {
            carry = false;
        } else {
            carry = true; cur -= 10;
        }
        digC.pb(cur);
    }
    if (carry) digC.pb(1);
    reverse(all(digC));
    string C;
    F0R(i, sz(digC)) {
        C += (char) ('0' + digC[i]);
    }
    return C;
}

bool bigString(string A, string B) {
    if (sz(A) > sz(B)) {
        return true;
    }
    if (sz(B) < sz(A)) {
        return false;
    }

    F0R(i, sz(A)) {
        if (A[i] > B[i]) return true;
        if (B[i] > A[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    string S; cin >> S;
    int bestDigits = N+1;
    FOR(i, 1, S.length()) {
        if (S[i] != '0') {
            bestDigits = min(bestDigits, max(i, N-i));
        }
    }

    string best; F0R(i, N+10) best += '9';

    int breakpoint = bestDigits;
    string S1, S2;
    F0R(i, S.length()) {
        if (i < breakpoint) {
            S1 += S[i];
        } else {
            S2 += S[i];
        }
    }
    if (S2[0] > '0' && bigString(best, sum(S1, S2))) {
        best = sum(S1, S2);
    }

    breakpoint = N - breakpoint;
    S1 = ""; S2 = "";

    F0R(i, S.length()) {
        if (i < breakpoint) {
            S1 += S[i];
        } else {
            S2 += S[i];
        }
    }
    if (S2[0] > '0' && bigString(best, sum(S1, S2))) {
        best = sum(S1, S2);
    }

    cout << best << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343