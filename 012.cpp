
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

constexpr int MAX_N = 1000000;

int p[100000], cc;
bool vis[MAX_N];

void init() {
    memset(vis, false, sizeof(vis));
    cc = 0;
    for (int i = 2; i*i <= MAX_N; ++i) if (!vis[i]) {
        p[cc++] = i;
        for (int j = i+i; j <= MAX_N; j += i) vis[j] = true;
    }
}

int check(int n) {
    int ans = 1;
    for (int i = 0; i < cc; ++i) if (n % p[i] == 0) {
        int cnt = 1;
        while (n % p[i] == 0) {
            n /= p[i];
            ++cnt;
        }
        if (p[i] == 2) --cnt;
        ans *= cnt;
    }

    if (n > 1) ans <<= 1;
    return ans;
}

int main(void) {
    init();
    int T;
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;

        int ans = -1;
        for (int i = 1; i <= MAX_N; ++i) {
            if (check(i) * check(i + 1) > N) {
                ans = i * (i + 1) / 2;
                break;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
