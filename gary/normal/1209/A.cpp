//* AuThOr GaRyMr *//
//Codeforces ID: GaryMr
//Atcoder ID: Gary
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a[101],use[101];
int main(){
	int n;
	cin>>n;
	rb(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	int res=0;
	rb(i,1,n){
		if(!use[i]){
			use[i]=1;
			res++;
			rb(j,i+1,n){
				if(a[j]%a[i]==0){
					if(!use[j]) use[j]=1;
				}
			}
		}
	}
	cout<<res<<endl;
	return 0;
}