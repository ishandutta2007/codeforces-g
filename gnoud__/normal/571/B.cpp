#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define int long long
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forv(a,b) for(auto&a:b)
#define stop system("pause")
#define fi first
#define se second
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define pb push_back
#define mp make_pair
#define pp pop_back()
#define mp3(a,b,c) mp(a,mp(b,c))
#define mp4(a,b,c,d) mp(mp(a,b),mp(c,d))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define min4(a,b,c,d) min(min(a,d),min(b,c))
#define pii pair<int,int>
#define piii pair<int,pii >
#define pi4 pair<pair<int,int>,pair<int,int>>
#define all(a) a.begin(),a.end()
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define two(n) (1<<n)
#define bit(x,i) ((x>>(i-1))&1)
#define batbit(x,i) (x|(1ll<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
#define read4(a,b,c,d) read(a),read(b),read(c),read(d)
#define gcd(a,b) abs(__gcd(a,b))
#define lim 2139062143
using namespace std;
const int N=300010,_N=5010;
int n,k,a[N],f[_N][_N],s[N];
void read( int &x)
{
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') c = getchar(), nega = 1;
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
}
main()
{
    //freopen("571B.inp","r",stdin);
    read2(n,k);
    forinc(i,1,n) read(a[i]);
    sort(a+1,a+n+1);
    s[1]=0;
    forinc(i,2,n) s[i]=s[i-1]+a[i]-a[i-1];
    int m=n%k,sl=n/k;
    reset(f,127);
    int oo=f[0][0];
    f[0][0]=0;
    forinc(i,0,k-1) forinc(j,0,m) if(f[i][j]!=oo)
    {
        int o=i*sl+j+1;
        f[i+1][j]=min(f[i+1][j],f[i][j]+s[o+sl-1]-s[o]);
        f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+s[o+sl]-s[o]);
    }
    cout<<f[k][m];
}