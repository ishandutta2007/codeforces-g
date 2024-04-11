#include <bits/stdc++.h>
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
struct dijkstra {
  int n;
  const ll inf = 4e18;
  vector<ll> dists; /* for a single run */
  vector<int> par;
  vector<bool> vis;
  vector<vector<pair<ll, int> > > edges; /* weight, to */
  
  void init(int s) {
    n = s;
    dists = vector<ll>(n);
	  vis = vector<bool>(n);
    par = vector<int>(n);
    edges = vector<vector<pair<ll, int> > >(n);
  }

  void edge(int a, int b, ll wt) {
    edges[a].push_back(make_pair(wt, b));
    edges[b].push_back(make_pair(wt, a));
  }

  using ptype = pair<ll, int>;
  void run(int src) {
    fill(dists.begin(), dists.end(), inf);
	  fill(vis.begin(), vis.end(), false);
    fill(par.begin(), par.end(), -1);

    priority_queue<ptype, vector<ptype>, greater<ptype>> pq;
    dists[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
      ptype foc = pq.top();
      pq.pop();
	  
	    if (vis[foc.s]) continue;
	    vis[foc.s] = 1;
	  
      dists[foc.s] = min(dists[foc.s], foc.f);
      for (ptype x: edges[foc.s]) {
        ll d = dists[foc.s] + x.f;
        if (d < dists[x.s]) {
          dists[x.s] = d;
          par[x.s] = foc.s;
          pq.push(make_pair(d, x.s));
        }
      }
    }
  }
};
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 2940;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;
 
ll row_dp[75][75];
ll mat[75][75];
ll total_dp[75][75];

const ll inf = 1e17;
 
void solve(int tc = 0) {
	cin >> n >> m >> k;
	
	ll mx = m / 2;
	
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j < k; j++) {
			row_dp[i][j] = -inf;
			total_dp[i][j] = -inf;
		}
	}
	
	total_dp[0][0] = 0;
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
		
		ll dp[m + 1][mx + 1][k]; // (column, number, mod) -> max sum
		
		for (ll j = 0; j <= m; j++) {
			for (ll taken = 0; taken <= mx; taken++) {
				for (ll rem = 0; rem < k; rem++) {
					dp[j][taken][rem] = -inf;
				}
			}
		}
		
		dp[0][0][0] = 0;
		
		for (ll j = 0; j < m; j++) {
			for (ll taken = 0; taken <= mx; taken++) {
				for (ll rem = 0; rem < k; rem++) {
					// don't take element
					dp[j + 1][taken][rem] = max(dp[j + 1][taken][rem], dp[j][taken][rem]);
					
					// do take element
					ll n_rem = (rem + mat[i][j]) % k;
					if (taken < mx) dp[j + 1][taken + 1][n_rem] = max(dp[j + 1][taken + 1][n_rem], dp[j][taken][rem] + mat[i][j]);
				}
			}
		}
		
		for (ll rem = 0; rem < k; rem++) {
			for (ll taken = 0; taken <= mx; taken++) {
				row_dp[i][rem] = max(row_dp[i][rem], dp[m][taken][rem]);
			}
		}
		
		// for (ll rem = 0; rem < k; rem++) {
			// cout << i << " " << rem << " " << row_dp[i][rem] << '\n';
		// }
		
		for (ll old_rem = 0; old_rem < k; old_rem++) {
			for (ll rem = 0; rem < k; rem++) {
				ll new_rem = old_rem + rem;
				if (new_rem >= k) new_rem -= k;
				
				total_dp[i + 1][new_rem] = max(total_dp[i + 1][new_rem], total_dp[i][old_rem] + row_dp[i][rem]);
			}
		}
	}
	
	cout << total_dp[n][0] << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("moop");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 
	
	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}