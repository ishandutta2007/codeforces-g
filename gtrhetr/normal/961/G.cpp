#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

ll fac[200010],ifac[200010];
int num[200010],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }
inline ll C(const int &x,const int &y) { return fac[x]*ifac[y]%mod*ifac[x-y]%mod; }

inline void pre_gao()
{
	fac[0]=1;
	for (int i=1;i<=200000;i++) fac[i]=fac[i-1]*i%mod;
	ifac[200000]=ksm(fac[200000],mod-2);
	for (int i=199999;~i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}

inline ll calc(int n,int m)
{
	if (n<m) return 0;
	ll ans=0;
	for (int i=0;i<=m;i++)
	{
		if ((m-i)&1) ans=mns(ans,C(m,i)*ksm(i,n)%mod);
		else ans=pls(ans,C(m,i)*ksm(i,n)%mod);
	}
	return ans*ifac[n]%mod;
}

int main()
{
	n=rd();m=rd();pre_gao();
	for (int i=1;i<=n;i++) num[i]=rd();
	ll ans=(calc(n-1,m)+calc(n-2,m)+calc(n-1,m-1)+calc(n-2,m-1))*ifac[m-1]%mod*fac[n-1]%mod;
	ll sum=0;
	for (int i=1;i<=n;i++) sum=pls(sum,num[i]);
	printf("%lld\n",ans*sum%mod);
	return 0;
}