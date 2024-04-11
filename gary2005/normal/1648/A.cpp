/**
 *    author:  gary
 *    created: 06.03.2022 17:47:55
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    map<int,vector<int> > col,row;
    rb(i,1,n){
        rb(j,1,m){
            int c;
            cin>>c;
            col[c].PB(j);
            row[c].PB(i);
        }
    }
    LL ans=0;
    for(auto ite=col.begin();ite!=col.end();ite++){
        auto tmp=ite->second;
        sort(ALL(tmp));
        rep(i,tmp.size()-1){
            ans+=1ll*(i+1)*(tmp.size()-1-i)*(tmp[i+1]-tmp[i]);
        }
    }
    col=row;
    for(auto ite=col.begin();ite!=col.end();ite++){
        auto tmp=ite->second;
        sort(ALL(tmp));
        rep(i,tmp.size()-1){
            ans+=1ll*(i+1)*(tmp.size()-1-i)*(tmp[i+1]-tmp[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}