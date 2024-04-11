#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
T square(T& a) {
	return a * a;
}

ll nod(ll a, ll b) {
	if (min(a, b) == 0) {
		return max(a, b);
	}
	return nod(max(a, b) % min(a, b), min(a, b));
}

bool is_sorted(vector<ll>& arr) {
	for (ll i = 1; i < arr.size(); i++) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}
	return true;
}

ll sum(ll x) {
	ll ans = 0;
	while (x > 0) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

bool is_gcdsum(ll x) {
	return gcd(x, sum(x)) > 1;
}

bool is_prime(ll x) {
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

ll col_add(ll a, ll b) {
	ll ans = 0;
	while (a * 2 < b) {
		a *= 2;
		ans++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n, m;
		cin >> n >> m;
		vector<ll> arr(n, 0), b(m, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (ll i = 0; i < m; i++) {
			cin >> b[i];
		}
		bool f = false;
		ll ans;
		for (auto i : arr) {
			for (auto j : b) {
				if (i == j) {
					f = !f;
					ans = i;
					break;
				}
			}
			if (f) {
				break;
			}
		}
		if (f) {
			cout << "YES\n" << ' ' << 1 << ' ' << ans << '\n';
		} else {
			cout << "NO\n";
		}
	}
}
/*
















*/