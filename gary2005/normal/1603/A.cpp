/**
 *    author:  gary
 *    created: 30.10.2021 22:30:30
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
int n,a[100000+1],cnt[100000+1];
void solve(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]);
    bool ok=1;
    rb(i,1,n){
        int j=i;
        while(j>=1&&a[i]%(j+1)==0) --j;
        if(j==0) ok=0;
    }
    if(ok) puts("YES");
    else puts("NO");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}