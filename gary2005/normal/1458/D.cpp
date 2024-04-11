/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int T;
string s;
const int MAXN=1e6+20;
const int ADDI=5e5+10;
int edges[MAXN][2];
int n=0;
void dfs(int now,int tot){
	if(tot==n+1) return;
	if(edges[now][0]&&(!edges[now][1]||edges[now-1][1])){
		edges[now][0]--;
		printf("0");
		dfs(now-1,tot+1);
	}
	else{
		printf("1");
		edges[now][1]--;
		dfs(now+1,tot+1);
	}
}
void solve(){
	cin>>s;
	n=s.length(); 
	int st=0;
	rep(i,s.length()){
		if(s[i]=='0'){
			edges[st+ADDI][0]++;
			st--;
		}
		else{
			edges[st+ADDI][1]++;
			st++;
		}
	}
	dfs(ADDI,1);
	printf("\n");
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}