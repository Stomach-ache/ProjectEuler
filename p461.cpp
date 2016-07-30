/* ***********************************************
Author        :Stomach_ache
Created Time  :Fri 29 Jul 2016 09:34:30 AM CST
File Name     :p461.cpp
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

const real pi = acos(-1.0);
const real e  = 2.718281828459045;

real f(int n, int k) {
    return pow(e, (k + .0) / n) - 1;
}

int64 sqr(int x) {
    return x * x;
}

int64 g(int a, int b, int c, int d) {
    return sqr(a) + sqr(b) + sqr(c) + sqr(d);
}

typedef pair<int, int> pii;

const real inf = 1e-12;
real fi[30010];


struct Node {
    real v; int a, b;
    Node() {}
    Node(real _v, int _a, int _b): v(_v), a(_a), b(_b) {}
    bool operator <(const Node &b) const {
        return v < b.v;
    }
};

int main(void) {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    real b = clock() / CLOCKS_PER_SEC;

    int n = 10000, N = 15000;
    vector<Node> v;
    for (int i = 0; i < N; ++ i) fi[i] = f(n, i);
    for (int i = 0; i < N; ++ i) {
        for (int j = i; j < N; ++ j) {
            real sum = fi[i] + fi[j];
            if (sum > pi) break;
            v.emplace_back(Node {sum, i, j});
        }
    }

    sort(begin(v), end(v));

    real ans = pi; int64 ret = 0;
    for (int i = 0; i <= (int)v.size() / 2; ++ i) {
        real p = v[i].v;
        auto it = lower_bound(begin(v), end(v), Node{pi - p, 0, 0});
        if (abs(it->v + p - pi) < ans) {
            ret = g(it->a, it->b, v[i].a, v[i].b);
            ans = abs(it->v + p - pi);
        }
        if (it != begin(v)) {
            -- it;
            if (abs(it->v + p - pi) < ans) {
                ret = g(it->a, it->b, v[i].a, v[i].b);
                ans = abs(it->v + p - pi);
            }
        }
    }

    cout << ans << endl;
    cout << ret << endl;

    real e = clock() / CLOCKS_PER_SEC;

    cerr << "time used: " <<  e - b << "s" << endl;
    return 0;
}

// time used 82s
