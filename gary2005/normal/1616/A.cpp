/**
 *    author:  gary
 *    created: 31.12.2021 21:05:37
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
    map<int,int> app;
    int n;
    cin>>n;
    rb(i,1,n){
        int ai;
        cin>>ai;
        app[abs(ai)]++;
    }
    int cnt=app.size();
    for(auto ite=app.begin();ite!=app.end();ite++){
        if(ite->FIR&&ite->SEC!=1) cnt++;
    }
    // cout<<")";
    cout<<cnt<<endl;
    // cout<<")";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}