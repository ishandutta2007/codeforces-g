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


const ll identity = 0;
const ll SZ = 131072*4;

ll lsum[2*SZ], hsum[2*SZ], lazy[2*SZ];

ll combine(ll A, ll B) {
    return A+B;
}

ll combineUpd(ll A, ll B) {
    return A+B;
}

void push(int index, ll L, ll R) {
    lsum[index] = lsum[index] + lazy[index];
    hsum[index] = hsum[index] + lazy[index];
    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
    lazy[index] = identity;
}

void pull(int index) {
    lsum[index] = min(lsum[2*index], lsum[2*index+1]);
    hsum[index] = max(hsum[2*index], hsum[2*index+1]);
}

ll queryMin(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return 2000000000;
    if (lo <= L && R <= hi) return lsum[index];

    int M = (L+R) / 2;
    return min(queryMin(lo, hi, 2*index, L, M), queryMin(lo, hi, 2*index+1, M+1, R));
}

ll queryMax(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return -2000000000;
    if (lo <= L && R <= hi) return hsum[index];

    int M = (L+R) / 2;
    return max(queryMax(lo, hi, 2*index, L, M), queryMax(lo, hi, 2*index+1, M+1, R));
}


void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, P; cin >> N >> P;

    vi A(N); F0R(i, N) cin >> A[i];

    map<int, int> C;
    F0R(i, N) {
        C[A[i]]++;
    }

    sort(all(A));
    int lop = max(A[N-1] - N - 5, 1);
    int cur = 0, hi = 0, lo = 0;
    int hiPos = -1, loPos = -1;
    deque<int> q;
    int lower = 0;
    F0R(i, N) if (A[i] <= lop) lower++;
    FOR(i, 1, N) {
        int X = C[lop + i] - 1;
        cur += X;
        update(i, SZ-1, X);
        q.push_back(X);
    }
    vi ans;
    FOR(i, lop, A[N-1]+1) {
        lo = queryMin(i+1-lop, i+N-1); hi = queryMax(i+1-lop, i+N-1);
        lo = min(0, lo); hi = max(0, hi);
//        cout << cur << " " << lo << " " << hi << " " << lower << " " << i << nl;
        if (lower % P + lo > 0 && lower % P + hi < P) {
            ans.pb(i);
        }
        int X = q.front();
        q.pop_front();
        lower += X+1;
        update(i-lop+1, SZ-1, -X);

        X = C[i+N]-1;
        update(i-lop+N, SZ-1, X);
        q.push_back(X);

    }

    cout << sz(ans) << nl;
    F0R(i, sz(ans)) {
        cout << ans[i] << " ";
    }
    cout << nl;



	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343