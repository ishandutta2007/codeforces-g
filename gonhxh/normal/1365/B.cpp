#include <bits/stdc++.h>
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
//#define per(i, a, b) for(int i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define td(v) v.begin(),v.end()
#define sz(v) (int)v.size()
//#define M   1000000007 // 1e9 + 7
//#define int long long
using namespace std;
typedef vector<int> vi;
#define y1 abacaba
typedef long long ll;
typedef pair<int,int> pii;
inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll a,ll b,ll m){
    if(b==0LL) return 1LL;
    if(b==1LL) return mod(a,m);
    ll k = mod(exp(a,b/2,m),m);
    if(b&1LL){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}

void solve(){
  int n;
  cin>>n;
  int a=0,b=0;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      if(x==0)a=1;
      else b=1;
    }
  vector<int> v2 = v;
  sort(all(v2));
  if(v==v2 or (a==1 and b==1)){
    cout<<"Yes"<<endl;
  }else cout<<"No" << endl;
}

int32_t main(){
  fastio;
  int t;
  cin>>t;
  while(t--){
    solve();
  }

  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}