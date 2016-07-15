
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

constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 510;
int dp[MAX_N][MAX_N];

int main(void) {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int N, M;
        scanf("%d %d", &N, &M);
        ++N; ++M;
        for (int i = 1; i <= N; ++i) dp[i][M] = 1;
        for (int j = 1; j <= M; ++j) dp[N][j] = 1;
        for (int i = N-1; i >= 1; --i) for (int j = M-1; j >= 1; --j)
            dp[i][j] = ((LL)dp[i + 1][j] + dp[i][j + 1]) % MOD;

        printf("%d\n", dp[1][1]);
    }

    return 0;
}
