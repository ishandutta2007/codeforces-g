#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	ll crt=0;
	bool det=true;
	REP(i,n) {
		ll t;
		string d;
		cin>>t>>d;
		if(d=="West"||d=="East") {
			if(crt==0||crt==20000) {
				det=false;
			}
		} else if(d=="South") {
			if(crt+t>20000) det=false;
			else crt+=t;
		} else if(d=="North") {
			if(crt-t<0) det=false;
			else crt-=t;
		}
	}
	if(det&&crt==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}