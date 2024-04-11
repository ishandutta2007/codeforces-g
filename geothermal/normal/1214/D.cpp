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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	int N, M; cin >> N >> M;
	
	bool works[N][M];
	
	F0R(i, N) {
		F0R(j, M) {
			char C; cin >> C;
			works[i][j] = C == '.';
		}
	}
	
	queue<int> q;
	bool valid[N][M];
	F0R(i, N) F0R(j, M) valid[i][j] = false;
	valid[N-1][M-1] = true;
	
	q.push(N*M-1);
	
	while (!q.empty()) {
		int point = q.front(); q.pop();
		int X = point/M; int Y = point%M;
		
		int nxt = (X-1)*M+Y;
		
		if (X > 0 && works[X-1][Y] && !valid[X-1][Y]) {
			valid[X-1][Y] = true;
			q.push(nxt);
		}
		
		
		nxt = X*M+Y-1;
		if (Y > 0 && works[X][Y-1] && !valid[X][Y-1]) {
			valid[X][Y-1] = true;
			q.push(nxt);
		}
		
		
	}
	
	if (!valid[0][0]) {
		cout << 0 << endl; return 0;
	}
	
	bool visit[N][M]; F0R(i, N) F0R(j, M) visit[i][j] = false;
	visit[0][0] = true;
	q.push(0);
	
	int ans = 2;
	
	/*F0R(i, N) {
		F0R(j, M) {
			cout << (valid[i][j] ? 1 : 0);
		}
		cout << endl;
	}*/
	
	while (!q.empty()) {
		
		int point = q.front(); q.pop();
		int X = point/M; int Y = point%M;
		
		int nxt = (X+1)*M+Y;
		
		if (X < N-1 && valid[X+1][Y] && !visit[X+1][Y]) {
			visit[X+1][Y] = true;
			q.push(nxt);
		}
		
		
		nxt = X*M+Y+1;
		if (Y < M-1 && valid[X][Y+1] && !visit[X][Y+1]) {
			visit[X][Y+1] = true;
			q.push(nxt);
		}
		
		//cout << q.size() << endl;
		
		if (q.size() == 1 && q.front() != N*M-1) {
			ans = 1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343