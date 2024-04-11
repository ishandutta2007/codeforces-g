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
	
    int K; cin >> K;
    string S; cin >> S;
    int N = sz(S);
    bool found[K]; F0R(i, K) found[i] = false;
    F0R(i, (N+1)/2) {
        if (S[i] == '?') {
            S[i] = S[N-1-i];
        }
        if (S[N-1-i] == '?') {
            S[N-1-i] = S[i];
        }
        if (S[i] != S[N-1-i]) {
            cout << "IMPOSSIBLE" << nl; return 0;
        }
        if (S[i] != '?') found[S[i]-'a'] = true;
    }
    int cur = K-1;
    F0Rd(i, (N+1)/2) {
        if (S[i] != '?') continue;
        while (cur > 0 && found[cur]) {
            cur--;
        }
        found[cur] = true;
        S[i] = 'a'+cur;
        S[N-1-i] = 'a'+cur;
        
    }
    F0R(i, K) {
        if (found[i]) continue;
        cout << "IMPOSSIBLE" << nl;
        return 0;
    }
    cout << S << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343