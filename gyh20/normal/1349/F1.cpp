#include<cstdio>
int o[5002][5002],n,i=o[0][0]=1,v[5002],f=v[1]=1,M=998244353,t,j;int main(){scanf("%d",&n);for(;i<=n;++i)for(j=o[i][0]=1;j<=i;++j)o[i][j]=(1ll*o[i-1][j-1]*(i-j)+1ll*(j+1)*o[i-1][j])%M;for(i=2;i<=n;++i)v[i]=1ll*(M-M/i)*v[M%i]%M,f=1ll*f*i%M;for(i=2;i<=n;++i)v[i]=1ll*v[i-1]*v[i]%M;for(i=1;i<=n;++i,printf("%d ",t))for(j=1,t=0;j<=n;++j)t=(t+1ll*o[j][i-1]*f%M*v[j])%M;}