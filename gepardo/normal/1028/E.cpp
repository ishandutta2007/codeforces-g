// Code written by gepardo
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;
using namespace chrono;

#ifdef DEBUG
	#define LOCAL_INPUT_FILE
#else
	//#define USE_FILE_IO
#endif

#ifdef USE_FILE_IO
	#define INPUT_FILE "input.txt"
	#define OUTPUT_FILE "output.txt"
	#define cin ____cin
	#define cout ____cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#else
	#ifdef LOCAL_INPUT_FILE
		#define cin ____cin
		ifstream cin("input.txt");
	#endif
#endif

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

#define int int64_t

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	vector<int> v(n);
	int best = 0;
	int bval = 0;
	int64_t sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		best = max(best, v[i]);
		if (v[i] == best) {
			bval = i;
		}
		sum += v[i];
	}
	if (best == 0) {
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			cout << 1 << " ";
		}
		cout << endl;
		return 0;
	}
	if ((int64_t)best * n == sum) {
		cout << "NO\n";
		return 0;
	}
	while (v[bval] == best) {
		bval += n-1;
		bval %= n;
	}
	bval++;
	bval %= n;
	vector<int64_t> a(n);
	a[bval] = v[bval];
	for (int i = 1; i < n; i++) {
		int nval = (bval + n-1) % n;
		if (i == 1) {
			a[nval] = 2*a[bval] + v[nval];
		} else {
			a[nval] = 1*a[bval] + v[nval];
		}
		bval = nval;
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}