/* ***********************************************
Author        :Stomach_ache
Created Time  :Mon 25 Jul 2016 08:55:54 PM CST
File Name     :p190.cpp
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


int gao(int m) {
    real p = 1, pre = 1;
    for (int i = 2; i <= m; ++ i) {
        pre = (i / (i - 1.0)) * pre;
        p += pre;
    }
    real ans = m / p; pre = ans;
    for (int i = 2; i <= m; ++ i) {
        ans *= pow(pre * i / (i - 1.0), i);
        pre = pre * i / (i - 1.0);
    }
    return (int)ans;
}

int main(void) {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    int ans = 0;
    for (int i = 2; i <= 15; ++ i) {
        int tmp = gao(i);
        //cerr << tmp << endl;
        ans += tmp;
    }

    cout << ans << endl;

    return 0;
}
