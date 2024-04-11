#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
typedef std::decay<decltype(MOD)>::type mod_t;
struct mi {
	mod_t val;
	explicit operator mod_t() const { return val; }
	mi() { val = 0; }
	mi(const long long& v) {
		val = (-MOD <= v && v < MOD) ? v : v % MOD;
		if (val < 0) val += MOD; }
	friend std::istream& operator >> (std::istream& in, mi& a) {
		long long x; std::cin >> x; a = mi(x); return in; }
	friend std::ostream& operator << (std::ostream& os, const mi& a) { return os << a.val; }
	friend bool operator == (const mi& a, const mi& b) { return a.val == b.val; }
	friend bool operator != (const mi& a, const mi& b) { return !(a == b); }
	friend bool operator < (const mi& a, const mi& b) { return a.val < b.val; }
	friend bool operator > (const mi& a, const mi& b) { return a.val > b.val; }
	friend bool operator <= (const mi& a, const mi& b) { return a.val <= b.val; }
	friend bool operator >= (const mi& a, const mi& b) { return a.val >= b.val; }
	mi operator - () const { return mi(-val); }
	mi& operator += (const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this; }
	mi& operator -= (const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this; }
	mi& operator *= (const mi& m) { val = (long long) val * m.val % MOD;
		return *this; }
	friend mi pow(mi a, long long p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans; }
	friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
	mi& operator /= (const mi& m) { return (*this) *= inv(m); }
	friend mi operator + (mi a, const mi& b) { return a += b; }
	friend mi operator - (mi a, const mi& b) { return a -= b; }
	friend mi operator * (mi a, const mi& b) { return a *= b; }
	friend mi operator / (mi a, const mi& b) { return a /= b; }
};

template <class T> struct SegmentTree {
	int n;
	std::vector<T> seg;

	const T ID = 0;		//Null value

	T comb(T a, T b) {
		return a + b;	//Edit operation here
	}

	SegmentTree() {}
	SegmentTree(int _n) { init(_n);	}
	void init(int _n) {
		n = _n;
		seg.assign(2 * n, ID);
	}

	void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }

	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	void add(int p, T val) {
		seg[p += n] += val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) ra = comb(ra, seg[l++]);
			if (r & 1) rb = comb(seg[--r], rb);
		}
		return comb(ra, rb);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n;
		cin >> n;

		vector<int> a(n);
		set<pii> vals;
		map<pii, int> ind;
		forn(i, n){
			cin >> a[i];
			vals.insert(mp(a[i], -i));
		}
		int curr = 1;
		for(pii x: vals){
			ind[x] = curr++;
		}
		curr++;
		forn(i, n){
			a[i] = ind[mp(a[i], -i)];
		}

		SegmentTree<mi> seg(curr), seg2(curr), seg3(curr);
		vector<mi> left(n), right(n), sub(n);
		forn(i, n){
			mi ways = seg.query(0, a[i]-1) + 1;
			left[i] = ways;
			seg.add(a[i], ways);
		}

		for(int i=n-1; i>=0; i--){
			mi ways = seg2.query(a[i]+1, curr-1) + 1;
			right[i] = ways;
			seg2.add(a[i], ways);
		}

		set<int> cliff;
		vector<bool> oncliff(n);
		int high = -1;
		for(int i=n-1; i>=0; i--){
			if(a[i] >= high){
				high = a[i];
				oncliff[i] = true;
				cliff.insert(high);
			}
		}
		cliff.insert(curr-1);

		for(int i=n-1; i>=0; i--){
			// cout << "cu " << *(cliff.upper_bound(a[i])) << "\n";
			mi ways = seg3.query(a[i]+1, *(cliff.upper_bound(a[i]))) + (oncliff[i] ? 1 : 0);
			sub[i] = ways;
			seg3.add(a[i], ways);
		}

		mi ans = 0;
		forn(i, n){
			ans += left[i] * (right[i] - sub[i]);
		}
		// cout << left << " " << right << " " << sub << "\n";

		cout << ans << "\n";


	}
}