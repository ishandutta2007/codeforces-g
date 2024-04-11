/**
 *    author:  gary
 *    created: 16.06.2022 22:23:58
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
const int MAXN=2e5+20;
int outedge[MAXN];
vector<int> rg[MAXN];
int n,m;
LL dist[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        rg[v].PB(u);
        outedge[u]++;
    }
    rb(i,1,n) dist[i]=1e18;
    dist[n]=0;
    priority_queue<pair<LL,int> ,vector<pair<LL,int> > ,greater<pair<LL,int> > > pq;
    pq.push(II(0,n));
    while (!pq.empty()){
        auto now=pq.top();
        pq.pop();
        if(dist[now.second]!=now.first) continue;
        for(auto it:rg[now.second]){
            outedge[it]--;
            if(dist[it]>now.first+1+outedge[it]){
                dist[it]=now.first+1+outedge[it];
                pq.push(II(dist[it],it));
            }
        }
    }
    cout<<dist[1]<<endl;
    return 0;
}