#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt();
	vector<int> level(n, 0);
	for (int i = 1; i < n; ++i) {
		level[i] = level[nxt() - 1] + 1;
	}
	vector<int> cnt(n, 0);
	for (int x : level) {
		cnt[x] += 1;
	}

	int ans = 0;
	for (int x : cnt) {
		ans += x % 2;
	}
	printf("%d\n", ans);

	return 0;
}