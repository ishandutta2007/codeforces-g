#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//#pragma GCC optimize ("O3")
//#pragma GCC target("tune=native")

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10;
int t, n, k;
int a[nax];
ll sum[nax];

void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	if(k <= n) {
		ll ans = 0;
		for(int i = 1; i + k - 1 <= n; ++i) {
			ans = max(ans, sum[i + k - 1] - sum[i - 1] + (ll)k * (k - 1) / 2);
		}
		cout << ans << "\n";
		return;
	} else {
		ll ans = sum[n];
		for(int i = 1; i <= n; ++i) {
			ans += (k - i);
		}
		cout << ans << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		solve();
	}
}