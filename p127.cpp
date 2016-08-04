/* ***********************************************
Author        :Stomach_ache
Created Time  :Wed 03 Aug 2016 10:52:38 AM CST
File Name     :p127.cpp
************************************************ */

#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <utility>
#include <cassert>
#include <iomanip>
#include <vector>
#include <bitset>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <map>
#if __cplusplus > 201103L
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#endif

using namespace std;

#define oo 0x3F3F3F3F
#define PB push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int _end_ = (b), i = (a); i <= _end_; ++i)
#define ROF(i, a, b) for (int _end_ = (b), i = (a); i >= _end_; --i)

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;


int64 fpm(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T sqr(T x) {return x * x;}
template <typename T> T gcd(T x, T y) {for (T t; x; ) t = x, x = y % x, y = t; return y; }

int64 rad[120010];
bool vis[120010];

typedef pair<int64, int> pii;

int main(void) {
    ios_base::sync_with_stdio(false);

    real s = clock() / CLOCKS_PER_SEC;

    int N = 120000;

    for (int i = 1; i < N; ++ i) rad[i] = 1;
    for (int i = 2; i < N; ++ i) if (!vis[i]) {
        rad[i] = i;
        for (int j = i + i; j < N; j += i) {
            rad[j] *= i;
            vis[j] = true;
        }
    }

    vector<pii> v;
    for (int i = 1; i < N; ++ i) {
        v.emplace_back(pii(rad[i], i));
    }
    sort(begin(v), end(v));

    int64 ans = 0;
    for (int c = 3; c < N; ++ c) {
        for (auto p: v) {
            if (p.first * rad[c] >= c) break;
            int a = p.second;
            int b = c - a;
            //cerr << a << ' ' << b << ' ' << c << endl;
            if (a >= b) continue;
            if (__gcd(a, c) * __gcd(a, b) * __gcd(b, c) != 1) continue;
            if (rad[a] * rad[b] * rad[c] >= c) continue;
            ans += c;
        }
    }
    cout << ans << endl;

    real e = clock() / CLOCKS_PER_SEC;
    cerr << "time used: " << e - s << "s" << endl;
    return 0;
}
