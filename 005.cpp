
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

LL gcd(LL a, LL b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void) {
    LL ans = 1;
    for (int i = 2; i <= 20; ++i) {
        ans = ans / gcd(ans, i) * i;
    }
    printf("%lld\n", ans);

    return 0;
}
