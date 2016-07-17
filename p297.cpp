/* ***********************************************
Author        :Stomach_ache
Created Time  :Sun 17 Jul 2016 10:31:30 AM CST
File Name     :p297.cpp
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


int64 fib[100];

map<int64, __int128> dp;
__int128 gao(int64 n, int i) {
    if (dp.find(n) != dp.end()) return dp[n];
    if (n <= 0) return 0;
    while (i > 0 && fib[i] > n) -- i;
    return dp[n] = gao(n - fib[i], i - 1) + gao(fib[i] - 1, i - 1) + n - fib[i] + 1;
}

int main(void) {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    fib[0] = fib[1] = 1;
    for (int i = 2; i <= 85; ++ i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        //if (fib[i] >= 1e17) cout << i << endl;
    }

    cout << (1e7 - 1) << endl;
    __int128 res = gao((int64)1e17 - 1, 83);
    //__int128 res = gao(100000000000000000LL - 1, 83);
    string ans = "";
    while (res > 0) {
        ans.push_back(res % 10 + '0');
        res /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    //cout << gao(1e15 - 1, 82) << endl;

    return 0;
}
