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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll mi = INF, ma = -INF;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		ans += assign_min(mi, a);
		ans += assign_max(ma, a);
	}
	cout << ans - 2;
}

/*
















*/