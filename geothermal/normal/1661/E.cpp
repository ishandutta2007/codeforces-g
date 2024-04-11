#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}
void solve() {
    int N; cin >> N;
    bool A[3][N]; F0R(i, 3) F0R(j, N) {
        char C; cin >> C;
        A[i][j] = C == '1';
    }

    int nxt[3][N][2], lst[3][N][2];
    F0R(i, 3) {
        nxt[i][N-1][0] = N;
        nxt[i][N-1][1] = N;
        nxt[i][N-1][A[i][N-1]] = N-1;
        lst[i][0][0] = -1;
        lst[i][0][1] = -1;
        lst[i][0][A[i][0]] = 0;
    }
    F0Rd(i, N-1) {
        F0R(j, 3) {
            nxt[j][i][0] = nxt[j][i+1][0];
            nxt[j][i][1] = nxt[j][i+1][1];
            nxt[j][i][A[j][i]] = i;
        }
    }
    FOR(i, 1, N) {
        F0R(j, 3) {
            lst[j][i][0] = lst[j][i-1][0];
            lst[j][i][1] = lst[j][i-1][1];
            lst[j][i][A[j][i]] = i;
        }
    }

    int cc[3][N]; F0R(i, 3) F0R(j, N) cc[i][j] = -1;
    int ncc = 0;
    int endBef[N]; F0R(i, N) endBef[i] = 0;
    int staAft[N]; F0R(i, N) staAft[i] = 0;
    F0R(rx, 3) {
        F0R(ry, N) {
            if (!A[rx][ry] || cc[rx][ry] != -1) continue;
            cc[rx][ry] = ncc;
            queue<pi> q; q.push({rx, ry});
            int lo = N, hi = 0;
            while (!q.empty()) {
                int x = q.front().f, y = q.front().s;
                ckmax(hi, y);
                ckmin(lo, y);
                q.pop();
                F0R(i, 4) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (valid(nx, ny, 3, N) && cc[nx][ny] == -1 && A[nx][ny]) {
                        q.push({nx, ny});
                        cc[nx][ny] = ncc;
                    }
                }
            }

            if (lo) {
                staAft[lo-1]++;
            }
            if (hi < N-1) {
                endBef[hi+1]++;
            }

            ncc++;

        }
    }
    FOR(i, 1, N) {
        endBef[i] += endBef[i-1];
    }
    F0Rd(i, N-1) {
        staAft[i] += staAft[i+1];
    }

    int Q; cin >> Q;
    while(Q--) {
        int L, R; cin >> L >> R; L--; R--;

        int ans = ncc - staAft[R] - endBef[L];
        int used = 0;
        if (A[0][L] && cc[0][L] == cc[2][L] && !A[1][L] && nxt[1][L][1] >= min({R+1, nxt[0][L][0], nxt[2][L][0]})) {
            ans++;
            used++;
        }
        if (A[0][R] && cc[0][R] == cc[2][R] && !A[1][R] && lst[1][R][1] <= max({L-1, lst[0][R][0], lst[2][R][0]})) {
            ans++;
            used++;
        }
        if (used == 2 && nxt[0][L][0] > R && nxt[2][L][0] > R) ans--;
        cout << ans << nl;
    }



}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}