/*
AuThOr Gwj
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int cnt[31];
int main(){
	fastio;
	int n;
	cin>>n;
	rb(i,1,n)
	{
		int ai;
		cin>>ai;
		rep(j,31){
			if(ai&(1<<j))
		
			{
				cnt[j]++;
			}
		}
		
	}
	LL res=0;
	rb(i,1,n){
		LL ai=0;
		rep(j,31){
			if(cnt[j]){
				ai+=1<<j;
				cnt[j]--;
			}
		}
		res+=ai*ai;
	}
	cout<<res<<endl;
	return 0;
}