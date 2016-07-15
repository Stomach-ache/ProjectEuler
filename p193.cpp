/* ***********************************************
Author        :Stomach_ache
Created Time  :Thu 14 Jul 2016 09:06:08 AM CST
File Name     :p193.cpp
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


bool isNotPrime[40000010];
vector<int> p;
int64 N = (1LL<<50) - 1;
int len;

int64 k = (int64)sqrt(N + .0);

int64 sqr(int64 x) {
    return x * x;
}

// inclusive-exclusive
int64 gao(int i, int64 n, int r) {
    if (i >= len) return 0;
    int64 ret = 0;
    for (int j = i; j < len; ++ j) {
        if (n * p[j] <= k) {
            ret += r * (N / sqr(n * p[j]));
            ret += gao(j + 1, n * p[j], r * -1);
        } else {
            break;
        }
    }

    return ret;
}


int main(void) {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    int64 ans = N;
    for (int64 i = 2; i <= k; ++ i) if (!isNotPrime[i]) {
        p.push_back(i);
        for (int64 j = i * i; j <= k; j += i) isNotPrime[j] = true;
    }

    //cout << p.size() << endl;
    len = p.size();

    cout << N - gao(0, 1, 1) << endl;

    return 0;
}
