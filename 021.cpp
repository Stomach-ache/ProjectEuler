
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

constexpr int MAX_N = 100010;
int d[MAX_N];
int s[MAX_N];
bool vis[MAX_N];

int main(void) {
    memset(vis, false, sizeof(vis));
    s[0] = d[0] = 0;
    for (int i = 1; i < MAX_N-10; ++i) {
        int tmp = -i;
        for (int j = 1; j <= i / j; ++j) if (i % j == 0) {
            tmp += j + i / j;
            if (j == i / j) tmp -= j;
        }
        d[i] = tmp;
        if (tmp < i && d[tmp] == i) vis[i] = vis[tmp] = true;
    }
    for (int i = 1; i < MAX_N-10; ++i) {
        s[i] = s[i - 1] + (vis[i] ? i : 0);
    }
    int T;
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;
        cout << s[N - 1] << endl;
    }

    return 0;
}
