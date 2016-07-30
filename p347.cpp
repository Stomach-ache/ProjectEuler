/* ***********************************************
Author        :Stomach_ache
Created Time  :Wed 27 Jul 2016 09:00:43 AM CST
File Name     :p347.cpp
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

bool vis[10000001];
int m[10000001];
typedef pair<int, int> pii;

int main(void) {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    real b = clock() / CLOCKS_PER_SEC;

    int N = 10000000;
    for (int i = 2; i <= N; ++ i) if (!vis[i]) {
        m[i] = i;
        for (int j = i + i; j <= N; j += i) {
            vis[j] = true;
            m[j] = i;
        }
    }

    set<pii> s;
    int64 ans = 0;
    for (int i = N; i >= 2; -- i) if (vis[i]) {
        int x = i;
        while (x % m[i] == 0) x /= m[i];
        if (x == 1) continue;
        int m2 = m[x];
        while (x % m2 == 0) x /= m2;
        if (x == 1 && s.find(pii(m[i], m2)) == end(s)) {
            int y = i;
            while (y % m2 == 0) y /= m2;
            while (y % m[i] == 0) {
                int z = i;
                while (z % m[i] == 0) z /= m[i];
                while (z % m2 == 0) {
                    vis[y*z] = false;
                    z /= m2;
                }
                y /= m[i];
            }
            ans += i;
            s.insert(pii(m[i], m2));
        }
    }
    cout << ans << endl;
    real e = clock() / CLOCKS_PER_SEC;

    cerr << "time used: " << (e - b) << "s"<< endl;

    return 0;
}
