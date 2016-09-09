/* ***********************************************
Author        :Stomach_ache
Created Time  :Fri 09 Sep 2016 10:51:54 AM CST
File Name     :p104.cpp
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

const int MOD = 1e9;

bool vis[10];
bool check(int n) {
    memset(vis, false, sizeof(vis));
    int cc = 0;
    while (n > 0) {
        if (n % 10 == 0) return false;
        if (!vis[n % 10]) ++ cc;
        vis[n % 10] = true;
        n /= 10;
    }
    return cc == 9;
}

int main(void) {

    int f1 = 1, f2 = 1, f3;
    real g = (sqrt(5.0) + 1) * 0.5;
    for (int i = 3; i < 1000000; ++ i) {
        f3 = (f1 + f2) % MOD;
        real tmp = log10(1 / sqrt(5.0)) + i * log10(g);
        if (check(f3) && check(pow(10.0, tmp - (int)tmp + 8))) {
            cout << i << endl;
            break;
        }
        f1 = f2, f2 = f3;
    }

    return 0;
}
