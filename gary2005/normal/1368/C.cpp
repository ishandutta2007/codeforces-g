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
vector<mp> res;
void print(int x,int y,int k){
	if(!k) return;
	res.PB(II(x,y));
	res.PB(II(x,y+1));
	res.PB(II(x+1,y));
	res.PB(II(x+2,y));
	res.PB(II(x,y+2));
	res.PB(II(x+2,y+1));
	res.PB(II(x+1,y+2));
	print(x-2,y-2,k-1);
}
int main(){
	fastio;
	int k;
	cin>>k;
	res.PB(II(102,102));
	print(100,100,k+1);
	cout<<res.size()<<endl;
	for(auto it:res){
		cout<<it.FIR<<" "<<it.SEC<<endl;
	}
	return 0;
}