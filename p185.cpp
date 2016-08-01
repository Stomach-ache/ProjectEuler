/* ***********************************************
Author        :Stomach_ache
Created Time  :Sat 30 Jul 2016 03:16:58 PM CST
File Name     :p185.cpp
************************************************ */

#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <utility>
#include <cassert>
#include <iomanip>
#include <vector>
#include <bitset>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <map>
#if __cplusplus > 201103L
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#endif

using namespace std;

#define oo 0x3F3F3F3F
#define PB push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int _end_ = (b), i = (a); i <= _end_; ++i)
#define ROF(i, a, b) for (int _end_ = (b), i = (a); i >= _end_; --i)

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;


int64 fpm(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T sqr(T x) {return x * x;}
template <typename T> T gcd(T x, T y) {for (T t; x; ) t = x, x = y % x, y = t; return y; }

const int DIGITS = 16;

vector<string> clue = {
"5616185650518293",
"3847439647293047",
"5855462940810587",
"9742855507068353",
"4296849643607543",
"3174248439465858",
"4513559094146117",
"7890971548908067",
"8157356344118483",
"2615250744386899",
"8690095851526254",
"6375711915077050",
"6913859173121360",
"6442889055042768",
"2321386104303845",
"2326509471271448",
"5251583379644322",
"1748270476758276",
"4895722652190306",
"3041631117224635",
"1841236454324589",
"2659862637316867"};

vector<int> correct_digits = {2,1,3,3,3,1,2,3,1,2,3,1,1,2,0,2,2,3,1,3,3,2};

// loss function
int getErr(vector<int> &guess) {
    int err = 0;
    for (size_t i = 0; i < clue.size(); ++ i) {
        int x = 0;
        for (int j = 0; j < DIGITS; ++ j) {
            if (guess[j] == clue[i][j] - '0')
                ++ x;
        }
        err += abs(x - correct_digits[i]);
    }
    return err;
}

// 模拟退火
void SA() {
    srand(time(0));

    vector<int> guess(DIGITS);

    while (true) {
        for (int i = 0; i < DIGITS; ++ i) guess[i] = rand() % 10;
        int err = getErr(guess);
        real T = 0.9;

        for (int i = 0; i < 5000; ++ i) {
            int rid = rand() % DIGITS;

            int oldDigit = guess[rid];
            guess[rid] = rand() % 10;

            int newErr = getErr(guess);

            if (newErr == 0) {
                for (int i = 0; i < DIGITS; ++ i) cout << guess[i];
                cout << endl;
                return ;
            }

            if (newErr <= err || (rand() % 100 / 100.0) <= T) {
                T = T * 0.85;
                err = newErr;
            } else {
                guess[rid] = oldDigit;
            }
        }
    }
}

int main(void) {

    real start = clock() / CLOCKS_PER_SEC;
    SA();
    real end = clock() / CLOCKS_PER_SEC;

    cout << "time used: " << end - start << "s" << endl;

    return 0;
}
