/* ***********************************************
Author        :Stomach_ache
Created Time  :Thu 14 Jul 2016 10:30:24 AM CST
File Name     :p193_mobius.cpp
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


const int64 N = (1LL<<50) - 1;
const int64 k = (int64)sqrt(N + .0);

int64 sqr(int64 x) {
    return x * x;
}

int main(void) {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    vector<int> u(k + 2, 0);
    vector<bool> isP(k + 2, false);
    vector<int64> p(k + 2);

    for (int64 i = 2; i <= k; ++ i) if (!isP[i]) {
        for (int64 j = i; j <= k; j += i) {
            p[j] = i;
            isP[j] = true;
        }
    }

    u[1] = 1;
    for (int64 i = 2; i <= k; ++ i) {
        if (i % sqr(p[i]) == 0) u[i] = 0;
        else u[i] = -u[i / p[i]];
    }
    int64 ret = 0;
    for (int64 i = 1; i <= k; ++ i) {
        ret += u[i] * (N / sqr(i));
    }
    cout << ret << endl;

    return 0;
}
