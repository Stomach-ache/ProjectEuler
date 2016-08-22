#include <bits/stdc++.h>
using std::cout;
using std::endl;

typedef long long ll;
const ll MOD = 1e18;
int sg[10010];
ll cache[10010][10010];

ll solve(int n, int target) {
    if (target == -1) return 1;
    if (n == 1) return 0;
    if (n == 2) return target == 0 ? 1 : 0;

    if (cache[n][target] != -1) return cache[n][target];

    ll lft = solve(n - 1, (target ^ sg[n - 2] + 1) - 1);
    ll rgt = solve(n - 2, (target ^ sg[n - 1] + 1) - 1);
    return cache[n][target] = (lft + rgt) % MOD;
}

int main(void) {
    sg[1] = 0, sg[2] = 1;
    for (int i = 3; i <= 10000; ++ i) {
        sg[i] = sg[i - 1] + 1 ^ sg[i - 2] + 1;
    }
    memset(cache, -1, sizeof(cache));

    cout << solve(5, 0) << endl;
    cout << solve(10, 0) << endl;
    cout << solve(10000, 0) << endl;

    return 0;
}
