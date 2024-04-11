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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		string s;
		cin >> s;
		if (s.back() == 'o') {
			cout << "FILIPINO" << '\n';
		} else {
			if (s.back() == 'a') {
				cout << "KOREAN" << '\n';
			} else {
				cout << "JAPANESE" << '\n';
			}
		}
	}
}
/*
















*/