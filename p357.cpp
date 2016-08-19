/* ***********************************************
Author        :Stomach_ache
Created Time  :Thu 18 Aug 2016 09:47:49 AM CST
File Name     :p357.cpp
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

bool is[100000010];

int main(void) {

    real s = (real)clock() / CLOCKS_PER_SEC;

    int N = 100000000;
    for (int i = 2; i <= N; ++ i) if (!is[i]) {
        for (int j = i + i; j <= N; j += i) {
            is[j] = true;
        }
    }
    int64 ret = 1;
    for (int j = 2; j <= N; j += 2) if (!is[j + 1] && !is[j / 2 + 2]) {
        int i;
        for (i = 3; i * i <= j; ++ i) if (j % i == 0 && is[j/i+i]) {
            break;
        }
        if (i * i > j) ret += j;
    }

    cerr << ret << endl;
    real e = (real)clock() / CLOCKS_PER_SEC;
    cerr << "time used: " << e - s << "s\n";

    return 0;
}
