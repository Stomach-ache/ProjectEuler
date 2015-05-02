#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
LL get(LL a1, LL n, LL d) { return a1 * n + n * (n - 1) * d / 2; }

int main() {
    int T;
    scanf("%d", &T);
    while (T-- ) {
        LL N;
        scanf("%lld", &N);
        --N;
        printf("%lld\n", get(3, N / 3, 3) + get(5, N / 5, 5) - get(15, N / 15, 15));
    }
    return 0;
}

