/* ***********************************************
Author        :Stomach_ache
Created Time  :Fri 15 Jul 2016 01:55:38 PM CST
File Name     :p345.cpp
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


string s = "7  53 183 439 863 497 383 563  79 973 287  63 343 169 583"
" 627 343 773 959 943 767 473 103 699 303 957 703 583 639 913"
" 447 283 463  29  23 487 463 993 119 883 327 493 423 159 743"
" 217 623 3 399 853 407 103 983  89 463 290 516 212 462 350"
" 960 376 682 962 300 780 486 502 912 800 250 346 172 812 350"
" 870 456 192 162 593 473 915  45 989 873 823 965 425 329 803"
" 973 965 905 919 133 673 665 235 509 613 673 815 165 992 326"
" 322 148 972 962 286 255 941 541 265 323 925 281 601  95 973"
" 445 721 11 525 473  65 511 164 138 672  18 428 154 448 848"
" 414 456 310 312 798 104 566 520 302 248 694 976 430 392 198"
" 184 829 373 181 631 101 969 613 840 740 778 458 284 760 390"
" 821 461 843 513  17 901 711 993 293 157 274  94 192 156 574"
" 34 124  4 878 450 476 712 914 838 669 875 299 823 329 699"
" 815 559 813 459 522 788 168 586 966 232 308 833 251 631 107"
" 813 883 451 509 615  77 281 613 459 205 380 274 302  35 805";

int a[20][20];

// dynamic programming
// besides, this problem can also be solved using "mincost maxflow Algorithm"
int dp[15][1<<15];

int main(void) {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    // istringstream is really an amazing tool.
    istringstream sin(s);

    // size of the square matrix
    int n = 15;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            sin >> a[i][j];
            //cout << a[i][j] << ' ';
        }
        //cout << endl;
    }

    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < (1<<n); ++ j) {
            int cc = __builtin_popcount(j);
            if (cc != i) continue;

            for (int k = 0; k < n; ++ k) if (!((1<<k) & j)) {
                chkmax(dp[i][j | (1<<k)], (i == 0 ? 0 : dp[i - 1][j]) + a[i][k]);
            }
        }
    }

    cout << dp[n - 1][(1<<n) - 1] << endl;

    return 0;
}
