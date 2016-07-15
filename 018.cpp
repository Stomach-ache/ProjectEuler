
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
    int T;
    cin >> T;
    while (T-- > 0) {
        int a[16][16];
        int N;
        cin >> N;
        for (int i = 1; i <= N; ++i) for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
        for (int i = N - 1; i >= 1; --i) for (int j = 1; j <= i; ++j) {
            a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
        }
        cout << a[1][1] << endl;
    }

    return 0;
}
