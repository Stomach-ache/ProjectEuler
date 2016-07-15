
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
        int N;
        cin >> N;

        int ans = -1;
        for (int a = 1; a < N; ++a) {
            int b = 0, c = 0;
            if (((N-a)*(N-a)-a*a) % (2*(N-a)) == 0) {
                b = ((N-a)*(N-a)-a*a) / (2*(N-a));
                c = N - a - b;
                if (a < b && b < c) ans = max(ans, a * b * c);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
