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
string s;
int main()
{
    //freopen("a.inp","r",stdin);
    cin>>s;
    int n=s.size();
    if(n<=20)
    {
        cout<<1<<" "<<n<<"\n"<<s;
        return 0;
    }
    forinc(t,2,5)
    {
        if((n%t==0&&n/t<=20)||(n/t+1<=20))
        {
            cout<<t<<" "<<(n/t+(n%t!=0))<<"\n";
            int d=t-n%t,p=0;
            if(d==t) {d=0;p=1;}
            int o=0;
            forinc(i,1,d)
            {
                int I=o;
                forinc(j,I,I+n/t-1) {cout<<s[j];o=j;}
                cout<<"*"<<"\n";
                o++;
            }
            forinc(i,d+1,t)
            {
                int I=o;
                forinc(j,I,I+n/t-p) {cout<<s[j];o=j;}
                cout<<"\n";
                o++;
            }
            return 0;
        }
    }
}