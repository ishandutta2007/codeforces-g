/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int las=-1;
		bool ok=1;
		rb(i,1,n){
			int ai;
			R(ai);
			if(las==-1) las=ai;
			else{
				if(ai!=las){
					ok=0;
				}
			}
		}
		if(ok){
			cout<<n<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	return 0;
}