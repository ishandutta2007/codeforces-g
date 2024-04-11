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
#define shandom_ruffle random_shuffle

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);	
	
	int N; cin >> N;
	bool adj[N][N];
	F0R(i, N) {
		F0R(j, N) {
			char cur; cin >> cur; adj[i][j] = cur == '1';
		}
	}
	
	int dist[N][N];
	F0R(root, N) {
		queue<int> q;
		q.push(root);
		F0R(i, N) dist[root][i] = -1;
		dist[root][root] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			F0R(i, N) {
				if (!adj[cur][i] || dist[root][i] != -1) continue;
				dist[root][i] = dist[root][cur] + 1;
				q.push(i);
			}
		}
	}
	
	int M; cin >> M;
	int data[M]; F0R(i, M) {
		cin >> data[i]; data[i]--;
	}
	
	int dp[M], last[M];
	dp[0] = 0;
	last[0] = -1;
	int lastPos[N];
	F0R(i, N) lastPos[i] = -1;
	lastPos[data[0]] = 0;
	
	FOR(i, 1, M) {
		dp[i] = 1000010;
		last[i] = -1;
		int cur = data[i];

		F0R(j, N) {
			if (lastPos[j] != -1 && i - lastPos[j] == dist[j][cur]) {
				dp[i] = min(dp[i], dp[lastPos[j]]+1);
				if (dp[i] == dp[lastPos[j]]+1) last[i] = lastPos[j];
			}
		}
		
		if (dp[i] < 1000010) {
			lastPos[cur] = i;
		}
	}
	
	/*F0R(i, M) {
		cout << dp[i] << " " << last[i] << endl;
	}*/
	
	vi ans;
	int cur = M-1;
	while (cur != -1) {
		ans.pb(data[cur]);
		cur = last[cur];
	}
	reverse(all(ans));
	cout << sz(ans) << endl;
	F0R(i, sz(ans)) {
		cout << ans[i]+1 << " ";
	} cout << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE