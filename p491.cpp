/* ***********************************************
Author        :Stomach_ache
Created Time  :Fri 19 Aug 2016 09:15:15 AM CST
File Name     :p491.cpp
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

int64 dp[11][60000];
int64 power[12];

int main(void) {

    real s = (real)clock() / CLOCKS_PER_SEC;

    power[0] = 1;
    for (int i = 1; i <= 10; ++ i) power[i] = power[i - 1] * 3;
    dp[0][0] = 1;
    for (int i = 0; i < power[10]; ++ i) {
        for (int j = 0; j <= 9; ++ j) {
            if (j == 0 && i == 0) continue;
            if (i / power[j] % 3 >= 2) continue;
            for (int k = 0; k < 11; ++ k) {
                dp[(k * 10 + j) % 11][i + power[j]] += dp[k][i];
            }
        }
    }
    cout << dp[0][power[10] - 1] << endl;

    real e = (real)clock() / CLOCKS_PER_SEC;
    cerr << "time used: " << e - s << "s\n";
    return 0;
}
