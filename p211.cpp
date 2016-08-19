/* ***********************************************
Author        :Stomach_ache
Created Time  :Fri 12 Aug 2016 08:10:15 AM CST
File Name     :p211.cpp
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

int64 ans[64000010];
bool is[640000010];
int m[640000010];

int main(void) {

    real s = (real)clock() / CLOCKS_PER_SEC;

    int N = 64000000;
    for (int i = 1; i < N; ++ i) {
        for (int j = i; j < N; j += i) {
            ans[j] += (int64)i * i;
        }
    }

    int64 ret = 0;
    for (int i = 1; i < N; ++ i) {
        int64 k = sqrt(ans[i] + .0);
        if (ans[i] == k * k) ret += i;
    }

    cout << ret << endl;

    real e = (real)clock() / CLOCKS_PER_SEC;
    cerr << "time used: " << e - s << "s\n";

    return 0;
}
