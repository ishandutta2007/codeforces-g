#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

int t,n,r;

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> r;
		ll ans;
		if(r >= n) {
			ans = (ll)n*(n-1)/2 + 1;
		} else {
			ans =  (ll)r*(r+1)/2;
		}
		//~ ll ans = min((ll)n*(n-1)/2, (ll)r*(r+1)/2);
		cout << ans << "\n";
	}
		
	
}