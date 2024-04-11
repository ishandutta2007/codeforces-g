#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	int N; cin >> N;
	
	int data[N][N];
	F0R(i, N) F0R(j, N) data[i][j] = -1;
	data[0][0] = 1;
	data[N-1][N-1] = 0;
	
	int dx[3] = {0, 1, 2}, dy[3] = {2, 1, 0};
	for (int i = 0; i < N; i += 1) {
		for (int j = 0; j < N; j += 1) {
			if ((i+j) % 2 == 1) continue;
			F0R(k, 3) {
				int ni = i+dx[k], nj = j + dy[k];
				if (ni >= N || nj >= N || data[ni][nj] != -1) continue;
				cout << "? " << i+1 << " " << j+1 << " " << ni+1 << " " << nj+1 << endl;
				int res; cin >> res;
				if (res == -1) return 0;
				
				if (res == 1) {
					data[ni][nj] = data[i][j];
				} else data[ni][nj] = 1-data[i][j];
			}
		}
	}
	
	data[2][1] = 1;
	cout << "? 2 1 3 2" << endl;
	int curRes; cin >> curRes;
	if (curRes == -1) return 1;
	data[1][0] = (curRes == 1 ? 1 : 0);
	
	cout << "? 1 2 3 2" << endl;
	cin >> curRes;
	if (curRes == -1) return 0;
	data[0][1] = (curRes == 1 ? 1 : 0);
	
	for (int i = 0; i < N; i += 1) {
		for (int j = 0; j < N; j += 1) {
			if ((i+j)%2 == 0) continue;
			F0R(k, 3) {
				int ni = i+dx[k], nj = j + dy[k];
				if (ni >= N || nj >= N || data[ni][nj] != -1) continue;
				cout << "? " << i+1 << " " << j+1 << " " << ni+1 << " " << nj+1 << endl;
				int res; cin >> res;
				if (res == -1) return 0;
				
				if (res == 1) {
					data[ni][nj] = data[i][j];
				} else data[ni][nj] = 1-data[i][j];
			}
		}
	}
	
	bool invert = false;
	for (int i = 0; i+2 < N; i+= 2) {
			int j = i;
			if (data[i][j] == data[i+2][j+2]) continue;
			bool useEarly = false;
			if (data[i+1][j] == data[i+2][j+1] && data[i+2][j] == data[i][j]) {
				useEarly = true;
			}
			if (data[i+1][j] != data[i+2][j+1] && data[i+2][j] == data[i+2][j+2]) {
				useEarly = true;
			}
			
			if (useEarly) {
				cout << "? " << i+1 << " " << j+1 << " " << i+3 << " " << j+2 << endl;
				int res; cin >> res;
				if (res == -1) return 0;
				invert = (res && data[i+1][j] != data[i+2][j]);
				if (!invert) invert = (!res && data[i+1][j] == data[i+2][j]);
			} else {
				cout << "? " << i+2 << " " << j+1 << " " << i+3 << " " << j+3 << endl;
				int res; cin >> res;
				if (res == -1) return 0;
				invert = (res && (data[i+2][j] != data[i+2][j+1]));
				if (!invert) invert = (!res && data[i+2][j] == data[i+2][j+1]);
			}
			
			
			break;
		
	}
	if (invert) {
		for (int i = 0; i < N; i+=1) {
			for (int j = 0; j < N; j+=1) {
				if ((i+j)%2 == 1) data[i][j] = 1-data[i][j];
			}
		}
	}
	
	cout << "!" << endl;
	F0R(i, N) {
		F0R(j, N) {
			cout << data[i][j];
		}
		cout << endl;
	}
	
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343