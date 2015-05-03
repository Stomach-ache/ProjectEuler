
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

string num1[] = {
    "Zero", "One","Two","Three","Four","Five","Six","Seven","Eight","Nine"
};
string num2[] = {
    "Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"
};
string num3[] = {
    "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"
};
string num4[] = {
    "Hundred", "Thousand", "Million", "Billion", "Trillion"
};

string gao1(const string &num) {
    return num1[num[0] - '0'];
}

string gao2(const string &num) {
    if (num[0] == '0') return gao1(num.substr(1, 1));
    else if (num[0] == '1') {
        return num2[num[1] - '0'];
    } else {
        string stmp = gao1(num.substr(1, 1));
        return num3[num[0] - '2'] + (stmp == "Zero" ? "" : " " + stmp);
    }
}

string gao3(const string &num) {
    if (num[0] == '0') return gao2(num.substr(1, 2));
    else {
        string ans = gao1(num.substr(0, 1)) + " " + num4[0];
        string stmp = gao2(num.substr(1, 2));
        ans += stmp == "Zero" ? "" : " " + stmp;
        return ans;
    }
}

string solve(const string &num) {
    int len = num.size();
    string ans = "";
    if (len == 1) {
        ans += gao1(num);
    } else if (len == 2) {
        ans += gao2(num);
    } else if (len == 3) {
        ans += gao3(num);
    }

    return ans;
}

int main(void) {
    int T;
    cin >> T;
    while (T-- > 0) {
        string str;
        cin >> str;

        int len = str.size();
        vector<string> ans;
        for (int i = len-3; i >= 0; i -= 3) {
            ans.pb(solve(str.substr(i, 3)));
        }
        if (len % 3 != 0) {
            ans.pb(solve(str.substr(0, len%3)));
        }

        string result = "";
        len = ans.size();
        while (len > 1 && ans[len - 1] == "Zero") --len;
        for (int i = len - 1; i >= 0; --i) {
            string stmp = "";
            if (ans[i] == "Zero" && i == 0 && result.size() == 0) stmp += ans[i];
            else if (ans[i] != "Zero") stmp += ans[i];
            if (stmp.size() == 0) continue;
           if (i) stmp += " " + num4[i];
           if (result.size()) result += " ";
           result += stmp;
        }
        cout << result << endl;
    }

    return 0;
}
