/* ***********************************************
Author        :Stomach_ache
Created Time  :Mon 18 Jul 2016 01:22:14 PM CST
File Name     :p286.cpp
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

real dp[55][55];
real gao(real p) {
    dp[0][0] = 1.0;
    for (int i = 1; i <= 50; ++ i) {
        dp[i][0] = dp[i - 1][0] * (i / p);
        for (int j = 1; j <= i; ++ j) {
            dp[i][j] = dp[i - 1][j] * (i / p) + dp[i - 1][j - 1] * (1 - i / p);
        }
    }
    //cerr << p << ' ' << dp[50][20] << endl;
    return dp[50][20];
}

int main(void) {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    real lb = 50.0, ub = 100.0;
    for (int i = 0; i < 100; ++ i) {
        real mid = (lb + ub) * 0.5;
        real ret = gao(mid);
        if (ret > 0.02) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    cout << fixed << setprecision(10) << ub << endl;

    return 0;
}
