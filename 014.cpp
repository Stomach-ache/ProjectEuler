
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
#include<unordered_map>
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

constexpr int MAX_N = 5000010;
// $mmax[i] holds the longest chain produced by starting at [1, i]
int mmax[MAX_N];
int ans[MAX_N];
// cache the answer between range [1..MAX_N)
int cnt[MAX_N];

int main(void) {
    memset(cnt, -1, sizeof(cnt));
    cnt[1] = 1;
    mmax[1] = ans[1] = 1;
    for (int i = 2; i <= MAX_N-10; ++i) {
        int cc = 0;
        LL n = i;
        while (n >= i || cnt[n] == -1) {
            if ((n & 1) == 0) n >>= 1;
            else n = (n<<1) + n + 1;
            ++cc;
        }
        cc += cnt[n];
        if (cc >= mmax[i - 1]) {
            mmax[i] = cc;
            ans[i] = i;
        } else {
            mmax[i] = mmax[i - 1];
            ans[i] = ans[i - 1];
        }
    }
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int N;
        scanf("%d", &N);
        cout << ans[N] << endl;
    }

    return 0;
}
