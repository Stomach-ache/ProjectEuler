/* ***********************************************
Author        :Stomach_ache
Created Time  :Wed 17 Aug 2016 03:12:54 PM CST
File Name     :p549.cpp
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

int m[100000010];
int ans[100000010];

int main(void) {

    real s = (real)clock() / CLOCKS_PER_SEC;
    int N = 100000000;
    for (int i = 2; i <= N; ++ i) if (!m[i]) {
        m[i] = i;
        for (int j = i + i; j <= N; j += i) {
            m[j] = i;
        }
    }

    cerr << "prime generating done.\n";

    int64 ret = 0;
    for (int i = 2; i <= N; ++ i) {
        if (m[i] == i) {
            ret += i;
            ans[i] = i;
        } else {
            int x = i;
            int p = m[x], q = 1, t = 0;
            while (x % p == 0) {
                x /= p;
                q *= p;
                ++ t;
            }

            if (x == 1) {
                int x = 0, cnt = 0;
                while (cnt < t) {
                    x += p;
                    int y = x;
                    while (y % p == 0) y /= p, ++ cnt;
                }
                ans[i] = x;
            } else {
                ans[i] = max(ans[i], ans[q]);
                ans[i] = max(ans[i], ans[i/q]);
            }
            ret += ans[i];
        }
    }

    cout << ret << endl;
    real e = (real)clock() / CLOCKS_PER_SEC;
    cerr << "time used: " << e - s << "s\n";

    return 0;
}
