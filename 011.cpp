
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

int main(void) {
    int grid[20][20];
    int ans = 0;

    for (int i = 0; i < 20; ++i) for (int j = 0; j < 20; ++j) {
        scanf("%d", &grid[i][j]);
    }
    for (int i = 0; i < 20; ++i) for (int j = 0; j < 20; ++j) {

        int tmp = 1;
        for (int k = 0; k < 4; ++k) {
            if (j - k >= 0)
                tmp *= grid[i][j - k];
        }
        if (j >= 3) ans = max(ans, tmp);
        tmp = 1;
        for (int k = 0; k < 4; ++k) {
            if (i - k >= 0)
                tmp *= grid[i - k][j];
        }
        if (i >= 3) ans = max(ans, tmp);
        tmp = 1;
        for (int k = 0; k < 4; ++k) {
            if (i - k >= 0 && j - k >= 0)
                tmp *= grid[i - k][j - k];
        }
        if (i >= 3 && j >= 3) ans = max(ans, tmp);
        tmp = 1;
        for (int k = 0; k < 4; ++k) {
            if (i - k >= 0 && j + k < 20)
                tmp *= grid[i - k][j + k];
        }
        if (i >= 3 && j <= 16) ans = max(ans, tmp);
    }
    printf("%d\n", ans);

    return 0;
}
