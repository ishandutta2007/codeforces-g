/**
 *    author:  gary
 *    created: 31.05.2022 22:34:12
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
    int n;
    cin>>n;
    vector<int> v(n),p(n);
    rep(i,n) cin>>v[i],p[i]=i;
    rep(i,n){
        int j=i;
        while (j<n&&v[j]==v[i]){
            j++;
        }
        --j;
        if(j==i){
            cout<<-1<<endl;
            return ;
        }
        rotate(p.begin()+i,p.begin()+i+1,p.begin()+j+1);
        i=j;
    }
    rep(i,n) cout<<p[i]+1<<' ';
    cout<<endl;
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