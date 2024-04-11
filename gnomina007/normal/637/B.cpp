#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

#define all(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long uli;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const int P = 1e9 + 7, Q = 1e9 + 9;
const int base = 41;
const double PI = 3.141592653589793238;
const double eps = 1e-7;

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif // DEBUG

#ifdef DEBUG
#define END {cout << endl; return main ();}
#else
#define END return 0
#endif

set< string > name;
string order[200005];

int main()
{
#ifdef DEBUG
    freopen ("test.in", "r", stdin);
#endif // DEBUG

    int n;
    cin >> n;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> order[i];
    }
    for (int i = n - 1 ; i >= 0 ; --i)
    {
        if (name.count (order[i]))
            continue;
        else
        {
            cout << order[i] << endl;
            name.insert (order[i]);
        }
    }
    return 0;
}