#include <bits/stdc++.h>
using namespace std;
int64_t inf = (int64_t)1e+18;
int64_t mod = 1000000007;

// @author: ZhockDen

void runCase(int64_t &testCase) {
    // cout << "#Case " << testCase << ": \n";

    int64_t n, m, k;
    cin >> n >> m >> k;
    vector<int64_t> A(m);
    set<int64_t> B;
    for (auto &e : A) cin >> e;
    for (int64_t i = 0; i < k; i++) {
        int64_t x;
        cin >> x;
        B.insert(x);
    }
    string ans;
    for (int64_t i = 0; i < m; i++) {
        if (B.size() < n - 1) {
            ans.push_back('0');
        } else {
            if (B.size() == n) {
                ans.push_back('1');
            } else {
                if (B.count(A[i])) {
                    ans.push_back('0');
                } else {
                    ans.push_back('1');
                }
            }
        }
    }
    cout << ans << "\n";
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t tests = 1;
    cin >> tests;
    for (int64_t i = 1; i <= tests; i++) runCase(i);

    return 0;
}