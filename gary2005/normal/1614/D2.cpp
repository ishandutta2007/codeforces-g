/**
 *    author:  gary
 *    created: 26.11.2021 19:02:07
**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
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
using namespace __gnu_pbds;
int n,cnt[20000000+20];
LL dp[20000000+20];
const int bound=20000000;
int p[bound+1];
int m[bound+1];
bool v[bound+1];
int pri[bound+1];
int tot=0;
void xxs(){
	m[1]=p[1]=1;
	rb(i,2,bound){
		if(!v[i]){
			pri[++tot]=i;
			m[i]=-1;	
			p[i]=i-1;
		}
		rb(j,1,tot){
			if(i>bound/pri[j]) break;
			v[i*pri[j]]=1;
			if(i%pri[j]){
				p[i*pri[j]]=p[i]*(pri[j]-1);
				m[i*pri[j]]=-m[i];
			} 
			else{
				p[i*pri[j]]=p[i]*pri[j];
				m[i*pri[j]]=0;
				break;
			}
		}
	}
}
int main(){
    xxs();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n){
        int ai;
        cin>>ai;
        rb(j,1,1000){
            if(ai%j==0) cnt[j]++;
        }
        if(ai<=1000);
        else
            cnt[ai]++;
    }
    rb(i,1001,20000000){
        for(int j=i+i;j<=20000000;j+=i){
            cnt[i]+=cnt[j];
        }
    }
    rl(i,20000000,1){
        dp[i]=1ll*i*cnt[i];
        rb(k,1,tot){
            if(pri[k]>bound/i) break;
            int j=pri[k]*i;
            check_max(dp[i],dp[j]+1ll*i*(cnt[i]-cnt[j]));
        }
    }
    cout<<*max_element(dp+1,dp+1+20000000)<<endl;
    return 0;
}