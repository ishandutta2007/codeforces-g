#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cassert>
#include <random>
#include <iomanip>
#include <bitset>
#define FOR(i, n, m) for(ll i = n; i < (int)m; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 1000000007;
constexpr long double eps = 1e-9;
 
template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    REP(i, v.size()) {
        if(i) os << " ";
        os << to_string(v[i]);
    }
    return os;
}
 
struct modint {
    ll n;
public:
    modint(const ll n = 0) : n((n % mod + mod) % mod) {}
    static modint pow(modint a, int m) {
        modint r = 1;
        while(m > 0) {
            if(m & 1) { r *= a; }
            a = (a * a); m /= 2;
        }
        return r;
    }
    modint &operator++() { *this += 1; return *this; }
    modint &operator--() { *this -= 1; return *this; }
    modint operator++(int) { modint ret = *this; *this += 1; return ret; }
    modint operator--(int) { modint ret = *this; *this -= 1; return ret; }
    modint operator~() const { return (this -> pow(n, mod - 2)); } // inverse
    friend bool operator==(const modint& lhs, const modint& rhs) {
        return lhs.n == rhs.n;
    }
    friend bool operator<(const modint& lhs, const modint& rhs) {
        return lhs.n < rhs.n;
    }
    friend bool operator>(const modint& lhs, const modint& rhs) {
        return lhs.n > rhs.n;
    }
    friend modint &operator+=(modint& lhs, const modint& rhs) {
        lhs.n += rhs.n;
        if (lhs.n >= mod) lhs.n -= mod;
        return lhs;
    }
    friend modint &operator-=(modint& lhs, const modint& rhs) {
        lhs.n -= rhs.n;
        if (lhs.n < 0) lhs.n += mod;
        return lhs;
    }
    friend modint &operator*=(modint& lhs, const modint& rhs) {
        lhs.n = (lhs.n * rhs.n) % mod;
        return lhs;
    }
    friend modint &operator/=(modint& lhs, const modint& rhs) {
        lhs.n = (lhs.n * (~rhs).n) % mod;
        return lhs;
    }
    friend modint operator+(const modint& lhs, const modint& rhs) {
        return modint(lhs.n + rhs.n);
    }
    friend modint operator-(const modint& lhs, const modint& rhs) {
        return modint(lhs.n - rhs.n);
    }
    friend modint operator*(const modint& lhs, const modint& rhs) {
        return modint(lhs.n * rhs.n);
    }
    friend modint operator/(const modint& lhs, const modint& rhs) {
        return modint(lhs.n * (~rhs).n);
    }
};
istream& operator>>(istream& is, modint m) { is >> m.n; return is; }
ostream& operator<<(ostream& os, modint m) { os << m.n; return os; }
 
#define MAX_N 1010101
long long extgcd(long long a, long long b, long long& x, long long& y) {
    long long d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}
long long mod_inverse(long long a, long long m) {
    long long x, y;
    if(extgcd(a, m, x, y) == 1) return (m + x % m) % m;
    else return -1;
}
vector<long long> fact(MAX_N+1, inf);
long long mod_fact(long long n, long long& e) {
    if(fact[0] == inf) {
        fact[0]=1;
        if(MAX_N != 0) fact[1]=1;
        for(ll i = 2; i <= MAX_N; ++i) {
            fact[i] = (fact[i-1] * i) % mod;
        }
    }
    e = 0;
    if(n == 0) return 1;
    long long res = mod_fact(n / mod, e);
    e += n / mod;
    if((n / mod) % 2 != 0) return (res * (mod - fact[n % mod])) % mod;
    return (res * fact[n % mod]) % mod;
}
// return nCk
long long mod_comb(long long n, long long k) {
    if(n < 0 || k < 0 || n < k) return 0;
    long long e1, e2, e3;
    long long a1 = mod_fact(n, e1), a2 = mod_fact(k, e2), a3 = mod_fact(n - k, e3);
    if(e1 > e2 + e3) return 0;
    return (a1 * mod_inverse((a2 * a3) % mod, mod)) % mod;
}
 
using mi = modint;
 
mi mod_pow(mi a, ll n) {
    mi ret = 1;
    mi tmp = a;
    while(n > 0) {
        if(n % 2) ret *= tmp;
        tmp = tmp * tmp;
        n /= 2;
    }
    return ret;
}
 
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    REP(i, n) REP(j, m) cin >> g[i][j];
    if(n == 1 || m == 1) {
        int c = 0; REP(i, n) REP(j, m) if(g[i][j] == 'R') c++;
        if(c == 0) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> acmrock_tor(n, vector<int>(m, 0));
    vector<vector<int>> acmrock_tod(n, vector<int>(m, 0));
    for(int i = n - 1; i >= 0; i--) for(int j = m - 1; j >= 0; j--) {
        if(i < n - 1) acmrock_tod[i][j] += acmrock_tod[i + 1][j];
        if(j < m - 1) acmrock_tor[i][j] += acmrock_tor[i][j + 1];
        if(g[i][j] == 'R') {
            acmrock_tod[i][j]++;
            acmrock_tor[i][j]++;
        }
    }
    vector<queue<mi>> col_ans_q(n);
    vector<mi> col_ans_val(n, 0);
    vector<queue<mi>> row_ans_q(m);
    vector<mi> row_ans_val(m, 0);
    mi ans = 0;
    for(int i = n - 1; i >= 0; i--) for(int j = m - 1; j >= 0; j--) {
        int emp_tor = m - j - acmrock_tor[i][j], emp_tod = n - i - acmrock_tod[i][j];
        if(g[i][j] == 'R') {
            emp_tor++;
            emp_tod++;
        }
        mi ans_tor = 0, ans_tod = 0;
        while(!col_ans_q[i].empty() && (int)col_ans_q[i].size() > emp_tor - 1) {
            col_ans_val[i] -= col_ans_q[i].front();
            col_ans_q[i].pop();
        }
        while(!row_ans_q[j].empty() && (int)row_ans_q[j].size() > emp_tod - 1) {
            row_ans_val[j] -= row_ans_q[j].front();
            row_ans_q[j].pop();
        }
        ans_tor = col_ans_val[i];
        ans_tod = row_ans_val[j];
        if(i == n - 1 && j == m - 1) {
            ans_tor = 1;
            ans_tod = 1;
        }
        col_ans_q[i].push(ans_tod); col_ans_val[i] += ans_tod;
        row_ans_q[j].push(ans_tor); row_ans_val[j] += ans_tor;
        if(i == 0 && j == 0) ans = ans_tor + ans_tod;
    }
    cout << ans << endl;
    return 0;
}