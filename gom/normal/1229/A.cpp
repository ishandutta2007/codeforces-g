#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int,int> TP;
typedef vector<vector<ll>> mat;
const ll mod=1e9+7;
mat operator *(const mat &a,const mat &b)
{
	int n=a.size(),w=b.size(),m=b[0].size();
	mat c(n,vector<ll>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<w;j++){
			for(int k=0;k<m;k++){
				(c[i][k]+=a[i][j]*b[j][k]%mod)%=mod;
			}
		}
	}
	return c;
}
namespace fastIO{
	int cntF = 0;
	int lenF = 0;
	char bufF[1000000];
	void re() {
		cntF = 0;
		lenF = fread(bufF, 1, 1000000, stdin);
	}
	int nextint() {
		if (lenF == cntF) re();
		while (!(bufF[cntF] >= '0' && bufF[cntF] <= '9')) {
			cntF++;
			if (lenF == cntF) re();
			if (lenF == cntF) return -1;
		}
		int retF = 0;
		while ((bufF[cntF] >= '0' && bufF[cntF] <= '9')) {
			retF *= 10;
			retF += bufF[cntF]-'0';
			cntF++;
			if (lenF == cntF) re();
			if (lenF == cntF) return retF;
		}
		return retF;
	}
};
using namespace fastIO;
const int N=1e5+5;
int n;
ll a[N],b[N],s[N],ans;
bool ok[N];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(a[i]==a[j]) ok[i]=true;
		}
		if(!ok[i]) continue;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if((a[i]|a[j])==a[i]) ok[j]=true;
		}
	}
	for(int i=1;i<=n;i++) if(ok[i]) ans+=b[i];
	cout<<ans;
    return 0;
}