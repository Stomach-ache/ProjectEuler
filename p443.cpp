/* ***********************************************
Author        :Stomach_ache
Created Time  :Mon 01 Aug 2016 09:06:33 AM CST
File Name     :p443.cpp
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

vector<int64> primes;

void factorization(int64 n, vector<int64> &f) {
    for (int64 p: primes) if (n % p == 0) {
        f.emplace_back(p);
        while (n % p == 0) n /= p;
        if (p * p > n) break;
    }
    if (n > 1) f.emplace_back(n);
}

int main(void) {
     ios_base::sync_with_stdio(false);

     primesieve::generate_primes(40000000, &primes);

     int64 n = 5, g = 13, limits = 1000000000000000;
     while (true) {
         vector<int64> factor;
         factorization(g - n, factor);

         int64 L = limits;
         for (int64 f: factor) {
             if (n % f == 0) {
                 L = 0;
                 break;
             } else {
                 L = min(L, f - n % f);
             }
         }

         if (n + L + 1 > limits) break;

         g += L + __gcd(n + L, g + L);
         n += L + 1;
     }

     cout << g + limits - n + 1 << endl;

    return 0;
}
