
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

int main(void) {
    int N;
    cin >> N;
    vector<string> str(N);
    for (int i = 0; i < N; ++i) {
        cin >> str[i];
    }

    int cc = 0;
    vector<int> vec(60);
    int len = 0;
    for (int i = 49; i >= 0; --i) {
        int tmp = cc;
        for (int j = 0; j < N; ++j) tmp += str[j][i] - '0';
        vec[len++] = tmp % 10;
        cc = tmp /= 10;
    }
    while (cc > 0) {
        vec[len++] = cc % 10;
        cc /= 10;
    }

    for (int i = 1; i <= 10; ++i) cout << vec[len - i];
    cout << endl;

    return 0;
}
