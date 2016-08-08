/* ***********************************************
Author        :Stomach_ache
Created Time  :Mon 08 Aug 2016 09:33:08 AM CST
File Name     :p118.cpp
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


#include <primesieve.hpp>

bool check(int x) {
    bool vis[10];
    memset(vis, false, sizeof(vis));
    while (x > 0) {
        if (x % 10 == 0 || vis[x % 10]) return false;
        vis[x % 10] = true;
        x /= 10;
    }
    return true;
}

int64 ans[1<<10];
int main(void) {

    real s = clock() / CLOCKS_PER_SEC;

    primesieve::iterator it;
    int prime;
    vector<int> dp;
    while ((prime = it.next_prime()) <= 987654321) {
        if (check(prime)) {
            dp.emplace_back(prime);
        }
    }

    ans[0] = 1;
    for (int p: dp) {
        int bit = 0;
        while (p > 0) {
            bit += (1<<(p%10-1));
            p /= 10;
        }
        for (int i = 0; i < (1<<9); ++ i) if (ans[i]) {
            if ((bit & i) == 0) {
                ans[i | bit] += ans[i];
            }
        }
    }
    cout << ans[(1<<9) - 1] << endl;

    real e = clock() / CLOCKS_PER_SEC;
    cerr << "time used: " << e - s << "s\n";

    return 0;
}
