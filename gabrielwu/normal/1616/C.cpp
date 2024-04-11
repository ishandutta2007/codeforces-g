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


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n;
		cin >> n;
		vector<int> v(n);
		forn(i, n){
			cin >> v[i];
		}
		lld EPS = 1e-6;
		ll best = n-1;
		forn(i, n){
			forn(j, i){
				int cnt = 1;
				lld diff = ((lld) v[i]-v[j])/(i-j);
				// cout << setprecision(16) << diff << "\n";
				for(int k=1; k<=i; k++){
					if(abs(v[i-k] - (v[i]-diff*k)) < EPS){
						cnt++;
					}
				}
				for(int k=1; k+i<n; k++){
					if(abs(v[i+k] - (v[i]+diff*k)) < EPS){
						cnt++;
					}
				}
				ckmin(best, (ll) n-cnt);

			}
		}
		cout << best << "\n";
	}
}