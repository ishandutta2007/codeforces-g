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
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vi A(N); F0R(i, N) cin >> A[i];
        ll a1 = A[0], a2 = 0;
        ll cnt = 1;
        ll lst = A[0];
        int p1 = 1, p2 = N-1;
        bool sec = true;
        while (p1 <= p2) {
            ll cur = 0;
            if (sec) {
                while (p1 <= p2 && cur <= lst) {
                    cur += A[p2]; p2--;
                }
                a2 += cur;
            } else {
                while (p1 <= p2 && cur <= lst) {
                    cur += A[p1]; p1++;
                }
                a1+=cur;
            }
            lst = cur; cnt++; sec = !sec;
        }
        cout << cnt << " " << a1 << " " << a2 << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343