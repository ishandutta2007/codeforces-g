/**
 *    author:  gary
 *    created: 08.05.2022 22:28:00
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int n;
int p[5005],cnt[5005][5005];
void solve(){
    cin>>n;
    rb(i,1,n) cin>>p[i];
    rb(i,1,n){
        rb(j,1,n) cnt[i][j]=cnt[i-1][j];
        rb(j,p[i],n) cnt[i][j]++;
    }
    LL ans=0;
    rb(b,1,n) rb(c,b+1,n){
        ans+=cnt[b-1][p[c]]*(p[b]-cnt[c][p[b]]);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}