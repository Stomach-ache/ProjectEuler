/* ***********************************************
Author        :Stomach_ache
Created Time  :Tue 02 Aug 2016 09:30:57 AM CST
File Name     :p186.cpp
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

const int MOD = 1000000;

bool vis[MOD];
int cnt = 0;

int fa[MOD], rk[MOD];

int findfa(int x) {
    return x == fa[x] ? x : fa[x] = findfa(fa[x]);
}

void Union(int a, int b) {
    int x = findfa(a);
    int y = findfa(b);
    if (x != y) {
        fa[x] = y;
        rk[y] += rk[x];
    }
}

int main(void) {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    vector<int> s;
    s.emplace_back(MOD);
    for (int i = 1; i <= 55; ++ i) {
        s.emplace_back((100003 - 200003 * i + 300007LL * i * i * i) % MOD);
        if (!vis[s[i]]) {
            ++ cnt;
            vis[s[i]] = true;
        }
    }

    int PM = 524287;
    for (int i = 56; cnt < MOD; ++ i) {
        s.emplace_back((s[i - 24] + s[i - 55]) % MOD);
        if (!vis[s[i]]) {
            ++ cnt;
            vis[s[i]] = true;
        }
    }
    for (int i = s.size(); i < 60000000; ++ i) {
        s.emplace_back((s[i - 24] + s[i - 55]) % MOD);
    }

    //cerr << s.size() << endl;
    cerr << "generate s with size equals: " << s.size() << endl;

    for (int i = 0; i < MOD; ++ i) {
        fa[i] = i; rk[i] = 1;
    }

    memset(vis, false, sizeof(vis));

    int i = 1, j = 0, cc = 0;
    while (j < 2325629) {
        int a = s[2 * i - 1], b = s[2 * i];
        if (a == b) {
            ++ i;
            continue;
        }
        ++ j;
        Union(a, b);
        if (!vis[a]) {
            vis[a] = true;
            ++ cc;
        }
        if (!vis[b]) {
            vis[b] = true;
            ++ cc;
        }
        cerr << rk[findfa(PM)] * 100 / (MOD + .0) << endl;
        if (rk[findfa(PM)] * 100 / (MOD + .0) == 99) {
            cerr << j << endl;
            break;
        }
        ++ i;
    }

    return 0;
}
