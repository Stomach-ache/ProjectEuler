/* ***********************************************
Author        :Stomach_ache
Created Time  :Tue 26 Jul 2016 08:31:32 AM CST
File Name     :p250.cpp
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

int64 dp[252][250252];
const int64 MOD = 1e16;

int64 mul(int64 a, int64 b) {
    int64 ret = 0;
    while (b > 0) {
        if (b & 1) ret = (ret + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return ret;
}

int64 mod_pow(int64 a, int64 b) {
    int64 ret = 1;
    while (b > 0) {
        if (b & 1) ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

int64 p[250252];

int main(void) {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    for (int i = 1; i <= 250250; ++ i) {
        p[i] = mod_pow(i, i);
    }

    dp[1][1] = dp[0][1] = 1;
    for (int i = 2; i <= 250250; ++ i) {
        for (int j = 0; j < 250; ++ j) {
            dp[j][i] = dp[j][i - 1];
        }
        for (int j = 0; j < 250; ++ j) {
            dp[(j + p[i]) % 250][i] = (dp[(j + p[i]) % 250][i] + dp[j][i - 1]) % MOD;
        }
    }

    // eliminate one empty subset
    cout << dp[0][250250] - 1 << endl;

    return 0;
}
