
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, m) for (int i = 0; i < (int)(m); i++)
#define rep2(i, n, m) for (int i = n; i < (int)(m); i++)
typedef long long LL;
typedef pair<int, int> pii;

const int oo = (int) 1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

const int MAX_N = 2000010;
bool vis[MAX_N];
int p[MAX_N], cc;

void init() {
    cc = 0;
    memset(vis, false, sizeof(vis));
    for (int i = 2; i < MAX_N; ++i) if (!vis[i]) {
        p[++cc] = i;
        for (int j = i+i; j < MAX_N; j += i) vis[j] = true;
    }
}

int main(void) {
    init();
    int N = 2000000;
    LL ans = 0;
    for (auto &v: p) {
        if (v <= N) ans += v;
        else break;
    }
    printf("%lld\n", ans);

    return 0;
}
