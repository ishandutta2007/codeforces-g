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


const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001; 

ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

ll inv(ll base) {
    int g = MOD, r = base, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }
    return x < 0 ? x+MOD : x;
}

ll mul(ll A, ll B) {
	return (A*B)%MOD;
}

ll add(ll A, ll B) {
	return (A+B)%MOD;
}

ll dvd(ll A, ll B) {
    return mul(A, inv(B));
}

ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}
namespace NTT { //Source: Codeforces user neal
    vector<ll> roots = {0, 1};
    vector<int> bit_reverse;
    int max_size = -1;
    ll root;
 
    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }
 
    int round_up_power_two(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;
 
        return max(n, 1);
    }
 
    // Given n (a power of two), finds k such that n == 1 << k.
    int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }
 
    // Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
    // This makes even-odd div-conquer much easier.
    void bit_reorder(int n, vector<ll> &values) {
        if ((int) bit_reverse.size() != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);
 
            for (int i = 0; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
        }
 
        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }
 
    void find_root() {
        max_size = 1 << __builtin_ctz(MOD - 1);
        root = 2;
 
        // Find a max_size-th primitive root of MOD.
        while (!(modExp(root, max_size) == 1 && modExp(root, max_size/2) != 1))
            root++;
    }
 
    void prepare_roots(int n) {
        if (max_size < 0)
            find_root();
 
        assert(n <= max_size);
 
        if ((int) roots.size() >= n)
            return;
 
        int length = get_length(roots.size());
        roots.resize(n);
 
        // The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
        // the first half of the n-th primitive roots of MOD.
        while (1 << length < n) {
            // z is a 2^(length + 1)-th primitive root of MOD.
            ll z = modExp(root, max_size >> (length+1));
 
            for (int i = 1 << (length - 1); i < 1 << length; i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = (roots[i] * z)%MOD;
            }
 
            length++;
        }
    }
 
    void fft_iterative(int N, vector<ll> &values) {
        assert(is_power_of_two(N));
        prepare_roots(N);
        bit_reorder(N, values);
 
        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    ll even = values[start + i];
                    ll odd = values[start + n + i] * roots[n + i];
                    odd %= MOD;
                    values[start + n + i] = even - odd + MOD;
                    values[start + i] = even + odd;
                    values[start + n + i] %= MOD;
                    values[start + i] %= MOD;
                }
    }
 
    const int FFT_CUTOFF = 150;
 
    vector<ll> mod_multiply(vector<ll> left, vector<ll> right) {
        int n = left.size();
        int m = right.size();
 
        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;
            vector<uint64_t> result(n + m - 1, 0);
 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) ((int) left[i]) * ((int) right[j]);
 
                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= MOD;
                }
 
            for (uint64_t &x : result)
                if (x >= MOD)
                    x %= MOD;
 
            return vector<ll>(result.begin(), result.end());
        }
 
        int N = round_up_power_two(n + m - 1);
        left.resize(N);
        right.resize(N);
 
        bool equal = left == right;
        fft_iterative(N, left);
 
        if (equal)
            right = left;
        else
            fft_iterative(N, right);
 
        ll inv_N = inv(N);

        for (int i = 0; i < N; i++) {
            left[i] *= (right[i] * inv_N)%MOD;
            left[i] %= MOD;
        }
 
        reverse(left.begin() + 1, left.end());
        fft_iterative(N, left);
        left.resize(n + m - 1);
        return left;
    }
 
    vector<ll> mod_power(const vector<ll> &v, int exponent) {
        assert(exponent >= 0);
        vector<ll> result = {1};
 
        if (exponent == 0)
            return result;
 
        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = mod_multiply(result, result);
 
            if (exponent >> k & 1)
                result = mod_multiply(result, v);
        }
 
        return result;
    }
 
    vector<ll> mod_multiply_all(const vector<vector<ll>> &polynomials) {
        if (polynomials.empty())
            return {1};
 
        struct compare_size {
            bool operator()(const vector<ll> &x, const vector<ll> &y) {
                return x.size() > y.size();
            }
        };
 
        priority_queue<vector<ll>, vector<vector<ll>>, compare_size> pq(polynomials.begin(), polynomials.end());
 
        while (pq.size() > 1) {
            vector<ll> a = pq.top(); pq.pop();
            vector<ll> b = pq.top(); pq.pop();
            pq.push(mod_multiply(a, b));
        }
 
        return pq.top();
    }
}
void solve() {
    ll N, K, F; cin >> N >> K >> F;

    vl A; F0R(i, K+1) A.pb(1);
    while (sz(A) > F+2) {
        A[F+1] += A.back();
        A[F+1] %= MOD;
        A.pop_back();
    }
    while (sz(A) < F+2) A.pb(0);
    F0R(iter, N) {
        A = NTT::mod_multiply(A, A);
        while (sz(A) > F+2) {
            A[F+1] += A.back();
            A[F+1] %= MOD;
            A.pop_back();
        }
        if (iter == N-1) break;
        vl B(F+2);
        F0R(i, F+2) {
            B[i] += A[i] * max(0ll, K+1-i);
            B[i] %= MOD;
        }
        ll curTot = 0;
        F0Rd(i, F+2) {
            if (i <= K) B[i] += curTot;
            B[i] %= MOD;
            curTot += A[i];
            curTot %= MOD;
        }
        A = B;
        /*trav(a, B) {
            cout << a << " ";
        }
        cout << endl;*/
    }

    cout << A[F] << nl;


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