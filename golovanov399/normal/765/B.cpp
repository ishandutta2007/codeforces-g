#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	string s;
	cin >> s;
	char cur = 'a';
	for (char c : s) {
		if (c > cur) {
			puts("NO");
			return 0;
		} else if (c == cur) {
			++cur;
		}
	}

	puts("YES");

	return 0;
}