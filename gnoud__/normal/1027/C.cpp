#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
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
#define db double
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
#define int long long
using namespace std;
typedef vector<int> vt;
int dd[10010],a[1000010],fre[10010];
void read(int & x)
{
    x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
}
vector<int> e,luu;
struct oo
{
    db ma;int x1,x2,x3,x4;
};
db cheq(int u,int v)
{
    return db(4)*db(u+v)*db(u+v)/db(u*v);
}
main()
{
    //freopen("bai1.inp","r",stdin);
    int t;
    read(t);
    while(t--)
    {
        forv(v,luu) {dd[v]=0;fre[v]=0;} luu.clear();
        e.clear();
        int n;
        read(n);
        forinc(i,1,n) {read(a[i]);luu.pb(a[i]);dd[a[i]]++;}
        forinc(i,1,n) if(!fre[a[i]])
        {
            fre[a[i]]=1;
            if(dd[a[i]]>=2)
            {
                e.pb(a[i]);
                if(dd[a[i]]>=4) e.pb(a[i]);
            }
        }
        sort(e.begin(),e.end());
        oo kq;kq.ma=db(1e17);
        forinc(i,0,e.size()-2)
        {
            db tg=cheq(e[i],e[i+1]);
            if(tg<kq.ma) kq={tg,e[i],e[i],e[i+1],e[i+1]};
        }
        cout<<kq.x1<<" "<<kq.x2<<" "<<kq.x3<<" "<<kq.x4<<"\n";
    }
}