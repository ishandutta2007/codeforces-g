#include <algorithm>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>
#define FOR(i, n, m) for (ll i = n; i < (int)m; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 1000000007;
constexpr long double eps = 1e-9;

template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    REP(i, v.size()) {
        if (i) os << " ";
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
        while (m > 0) {
            if (m & 1) {
                r *= a;
            }
            a = (a * a);
            m /= 2;
        }
        return r;
    }
    modint& operator++() {
        *this += 1;
        return *this;
    }
    modint& operator--() {
        *this -= 1;
        return *this;
    }
    modint operator++(int) {
        modint ret = *this;
        *this += 1;
        return ret;
    }
    modint operator--(int) {
        modint ret = *this;
        *this -= 1;
        return ret;
    }
    modint operator~() const { return (this->pow(n, mod - 2)); }  // inverse
    friend bool operator==(const modint& lhs, const modint& rhs) {
        return lhs.n == rhs.n;
    }
    friend bool operator<(const modint& lhs, const modint& rhs) {
        return lhs.n < rhs.n;
    }
    friend bool operator>(const modint& lhs, const modint& rhs) {
        return lhs.n > rhs.n;
    }
    friend modint& operator+=(modint& lhs, const modint& rhs) {
        lhs.n += rhs.n;
        if (lhs.n >= mod) lhs.n -= mod;
        return lhs;
    }
    friend modint& operator-=(modint& lhs, const modint& rhs) {
        lhs.n -= rhs.n;
        if (lhs.n < 0) lhs.n += mod;
        return lhs;
    }
    friend modint& operator*=(modint& lhs, const modint& rhs) {
        lhs.n = (lhs.n * rhs.n) % mod;
        return lhs;
    }
    friend modint& operator/=(modint& lhs, const modint& rhs) {
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
istream& operator>>(istream& is, modint m) {
    is >> m.n;
    return is;
}
ostream& operator<<(ostream& os, modint m) {
    os << m.n;
    return os;
}

#define MAX_N 3030303
long long extgcd(long long a, long long b, long long& x, long long& y) {
    long long d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}
long long mod_inverse(long long a, long long m) {
    long long x, y;
    if (extgcd(a, m, x, y) == 1)
        return (m + x % m) % m;
    else
        return -1;
}
vector<long long> fact(MAX_N + 1, inf);
long long mod_fact(long long n, long long& e) {
    if (fact[0] == inf) {
        fact[0] = 1;
        if (MAX_N != 0) fact[1] = 1;
        for (ll i = 2; i <= MAX_N; ++i) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
    }
    e = 0;
    if (n == 0) return 1;
    long long res = mod_fact(n / mod, e);
    e += n / mod;
    if ((n / mod) % 2 != 0) return (res * (mod - fact[n % mod])) % mod;
    return (res * fact[n % mod]) % mod;
}
// return nCk
long long mod_comb(long long n, long long k) {
    if (n < 0 || k < 0 || n < k) return 0;
    long long e1, e2, e3;
    long long a1 = mod_fact(n, e1), a2 = mod_fact(k, e2),
              a3 = mod_fact(n - k, e3);
    if (e1 > e2 + e3) return 0;
    return (a1 * mod_inverse((a2 * a3) % mod, mod)) % mod;
}

using mi = modint;

mi linear_sum(mi a, mi b) {
    mi ret = b * (b + 1) / 2;
    if (a.n != 0) ret -= (a - 1) * a / 2;
    return ret;
}

mi quad_sum(mi a, mi b) {
    mi ret = b * (b + 1) * (2 * b + 1) / 6;
    if (a.n != 0) ret -= (a - 1) * a * (2 * a - 1) / 6;
    return ret;
}

mi mod_pow(mi a, ll n) {
    mi ret = 1;
    mi tmp = a;
    while (n > 0) {
        if (n % 2) ret *= tmp;
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

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    vector<int> sorted_a = a;
    sort(ALL(sorted_a));

    int ans = (sorted_a[0] + 1) / 2 + (sorted_a[1] + 1) / 2;

    REP(i, n - 2) {
        if (a[i] % 2 == 1 && a[i + 2] % 2 == 1) {
            ans = min(ans, (a[i] + a[i + 2]) / 2);
        }
    }

    REP(i, n - 1) {
        int mn = min(a[i], a[i + 1]), mx = max(a[i], a[i + 1]);
        if (mx >= 2 * mn) {
            ans = min(ans, (mx + 1) / 2);
        } else {
            int diff = mx - mn;
            ans = min(ans, diff + (2 * (mn - diff) + 2) / 3);
        }
    }

    cout << ans << endl;

    return 0;
}