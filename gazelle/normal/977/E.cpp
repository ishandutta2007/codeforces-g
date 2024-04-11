#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

vector<bool> used;
vector<vector<ll>> adj;
bool dfs(ll pos) {
	used[pos]=true;
	bool ret=true;
	if((ll)adj[pos].size()!=2) ret=false;
	REP(i,(ll)adj[pos].size()) {
		if(used[adj[pos][i]]) continue;
		ret=ret&dfs(adj[pos][i]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	adj.resize(n);
	REP(i,m) {
		ll u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	used.resize(n,false);
	ll ans=0;
	REP(i,n) {
		if(!used[i]) {
			if(dfs(i)) ans++;
		}
	}
	cout<<ans<<endl;
}