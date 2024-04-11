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
int high_bit(int x){
	int cnt=0;
	while(x>0){
		cnt++;
		x>>=1;
	}
	return cnt;
}
int n;
int a[100000+20];
int main(){
	scanf("%d",&n);
	if(n==2){
		cout<<-1<<endl;
		return 0;
	}
	rb(i,1,n){
		scanf("%d",&a[i]);
	}
	rb(i,2,n-1){
		if(high_bit(a[i])==high_bit(a[i-1])&&high_bit(a[i+1])==high_bit(a[i])){
			cout<<1<<endl;
			return 0;
		}
	}
	assert(n<=500);
	int rest=INF;
	rb(i,1,n){
		int val=0; 
		rb(j,i,n){
			val ^=a[j];
			int val2=0;
			rb(k,j+1,n){
				val2 ^= a[k];
				if(val>val2){
					check_min(rest,j-i+k-(j+1));
				}
			}
		}
	} 
	if(rest==INF) rest=-1;
	cout<<rest<<endl;	 
	return 0;
}