/**
 *    author:  gary
 *    created: 24.03.2022 22:31:19
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
void solve(){
    int n,k;
    cin>>n>>k;
    set<int> s;
    bool ok=0;
    rb(i,1,n){
        int a;
        cin>>a;
        s.insert(a);
        if(s.find(a+k)!=s.end()){
            ok=1;
        }
        if(s.find(a-k)!=s.end()){
            ok=1;
        }
    }
    if(ok) cout<<"Yes\n";
    else
    cout<<"No\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}