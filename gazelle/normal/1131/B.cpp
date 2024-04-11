#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using pint=pair<int,int>;
using pll=pair<ll,ll>;
#define MOD 998244353LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll> a(n + 1), b(n + 1);
	a[0] = 0; b[0] = 0;
	REP(i, n) cin >> a[i + 1] >> b[i + 1];
	ll ans = 1;
	ll mx = 0;
	FOR(i, 1, n + 1) {
		ans += max(0ll, min(a[i], b[i]) - max(max(a[i - 1], b[i - 1]) - 1, mx));
		mx = max(mx, min(a[i], b[i]));
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */