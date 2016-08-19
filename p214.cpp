/* ***********************************************
Author        :Stomach_ache
Created Time  :Sat 13 Aug 2016 08:03:35 AM CST
File Name     :p214.cpp
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


int phi[40000010];
int stp[40000010];

int main(void) {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    real s = (real)clock() / CLOCKS_PER_SEC;

    int N = 40000000;
    phi[1] = 1;
    for (int i = 2; i <= N; ++ i) if (!phi[i]) {
        for (int j = i; j <= N; j += i) {
            if (!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    }

    stp[1] = 0;
    for (int i = 2; i <= N; ++ i) stp[i] = stp[phi[i]] + 1;
    int64 ret = 0;
    for (int i = 2; i <= N; ++ i) if (phi[i] == i - 1) {
        if (stp[i] == 24) ret += i;
    }
    cout << ret << endl;

    real e = (real)clock() / CLOCKS_PER_SEC;
    cerr << "time used: " << e - s << "s\n";

    return 0;
}
