/**
 *    author:  gary
 *    created: 01.09.2021
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
const int MAXN=1e5+1;
int n,a[MAXN];
void solve(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	int answer=0;
	rb(i,2,n){
		if(a[i]<a[i-1]){
			check_max(answer,a[i-1]-a[i]);
			a[i]=a[i-1];
		}
	}
	int rest=0;
	while(answer) rest++,answer>>=1;
	cout<<rest<<endl;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}