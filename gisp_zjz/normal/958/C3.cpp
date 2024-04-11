#include<bits/stdc++.h>
#define maxn 129
#define N 500050

using namespace std;
typedef long long ll;
int n,m,p,q,dp[maxn][maxn],k,s,r;
int a[N],b[N];

int qry(int x,int y)
{
    int rt=dp[x][y];
    while (y) {
        rt=min(rt,dp[x][y]);
        y-=y&(-y);
    }
    return rt;
}

void add_(int x,int y,int z)
{
    while (y<maxn){
        dp[x][y]=min(dp[x][y],z);
        y+=y&(-y);
    }
}

int main()
{
    scanf("%d%d%d",&n,&k,&p);s=0;
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) s=(s+a[i])%p,b[i]=s;
    for (int i=0;i<maxn;i++)
        for (int j=0;j<maxn;j++)
            dp[i][j]=i;
    for (int i=1;i<=n;i++)
        for (int j=min(i,k);j>=1;j--)
        {
            r=min(qry(j-1,p)+1,qry(j-1,b[i]+1));
            add_(j,b[i]+1,r);
            if (j==k&&i==n) printf("%lld\n",1ll*r*p+b[n]);
        }
    return 0;
}