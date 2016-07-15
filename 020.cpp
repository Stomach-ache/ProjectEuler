
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

constexpr int MAX_N = 1010;
int ans[MAX_N];

int main(void) {
    int num[3000], len = 0;
    num[len++] = ans[0] = 1;
    for (int i = 1; i <= 1000; ++i) {
        int cc = 0, s = 0;
        for (int j = 0; j < len; ++j) {
            int tmp = num[j] * i + cc;
            num[j] = tmp % 10;
            cc = tmp / 10;
            s += num[j];
        }
        while (cc > 0) {
            num[len++] = cc % 10;
            cc /= 10;
            s += num[len - 1];
        }
        ans[i] = s;
    }
    int T;
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;
        cout << ans[N] << endl;
    }

    return 0;
}
