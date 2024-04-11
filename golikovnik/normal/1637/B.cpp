//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

void solveTest() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  ll ans = 0;
  ll const INF = ll(1e18);
  vector<ll> dp(n+1);
  for (int l = 0; l < n; ++l) {
    for (int j = l; j <= n; ++j) {
      dp[j] = 0;
    }
    for (int r = l; r < n; ++r) {
      set<int> have;
      int mex = 0;
      for (int rr = r; rr < n; ++rr) {
        have.insert(a[rr]);
        while (have.count(mex)) mex++;
        smax(dp[rr+1], dp[r]+1+mex);
      }
    }
    for (int j = l; j <= n; ++j) {
      ans += dp[j];
    }
  }
  cout << ans << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}