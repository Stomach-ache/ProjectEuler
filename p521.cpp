/* ***********************************************
Author        :Stomach_ache
Created Time  :Sat 20 Aug 2016 07:31:59 PM CST
File Name     :p521.cpp
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
#include <unordered_set>
#include <unordered_map>

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

const int MOD = 1000000000;

#include <omp.h>

int64 f(int64 n) {
    int r = sqrt(n + .0);
    vector<int64> V;
    for (int i = 1; i <= r; ++ i) V.emplace_back(n / i);
    for (int i = (*V.rbegin()) - 1; i >= 1; -- i) V.emplace_back(i);

    unordered_map<int64, int64> dp;
    for (int64 v: V) {
        if (v & 1) dp[v] = (((1 + v) / 2 % MOD * (v % MOD) % MOD - 1) % MOD + MOD) % MOD;
        else dp[v] = ((v / 2 % MOD * ((1 + v) % MOD) % MOD - 1) % MOD + MOD) % MOD;
    }
    for (int64 p = 2; p <= r; ++ p) if (dp[p] != dp[p - 1]) {
        int64 p2 = p * p;
        for (int64 v: V) {
            if (v < p2) break;
            dp[v] = ((dp[v] - p * ((dp[v / p] - dp[p - 1]) % MOD) % MOD) % MOD + MOD) % MOD;
        }
    }
    return dp[n];
}

int64 g(int64 n) {
    int r = sqrt(n + .0);
    vector<int64> V;
    for (int i = 1; i <= r; ++ i) V.emplace_back(n / i);
    for (int i = (*V.rbegin()) - 1; i >= 1; -- i) V.emplace_back(i);

    unordered_map<int64, int64> dp;
    for (int64 v: V) {
        dp[v] = v - 1;
    }

    int64 ret = 0;
    for (int64 p = 2; p <= r; ++ p) if (dp[p] > dp[p - 1]) {
        int64 p2 = p * p;
        int64 pre = dp[n];
        for (int64 v: V) {
            if (v < p2) break;
            dp[v] -= dp[v / p] - dp[p - 1];
        }
        ret = (ret + p * ((pre - dp[n]) % MOD) % MOD) % MOD;
    }
    return ret;
}

int main(void) {

    int64 N = 1000000000000LL;
    int64 ret1(0), ret2(0);

    omp_set_num_threads(2);
#pragma omp parallel
    {
        if (omp_get_thread_num() == 0) {
            ret1 = f(N);
        } else {
            ret2 = g(N);
        }
    }

    cout << (ret1 + ret2) % MOD << endl;

    return 0;
}
