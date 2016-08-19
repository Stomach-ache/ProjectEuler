/* ***********************************************
Author        :Stomach_ache
Created Time  :Tue 09 Aug 2016 09:55:04 PM CST
File Name     :p129.cpp
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

int64 A(int64 n) {
    if (n % 2 == 0 || n % 5 == 0) return -1;

    int64 x = 1, ans = 1;
    while ( x ) {
        x = (x * 10 + 1) % n;
        ++ ans;
    }
    return ans;
}

int main(void) {

    /*
     * the most important observation is that we always have A(n) <= n.
     * so let's just iterate n start from 10^6 rather than 1.
     */
    for (int64 i = 1000000; ; ++ i) {
        if (A(i) > 1000000) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
