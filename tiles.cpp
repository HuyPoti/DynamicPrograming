#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, maxWeight;
    cin >> n >> maxWeight;
    vector<int> weight(n);
    for (int i = 0; i < n; i++) cin >> weight[i];

    vector<pair<int, int>> dp(1 << n, { INF, 0 });
    dp[0] = { 1, 0 };  // ban đầu không có ai trên thang máy

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {  // nếu người thứ i chưa lên
                auto [rides, currentWeight] = dp[mask];
                if (currentWeight + weight[i] <= maxWeight) {
                    dp[mask | (1 << i)] = min(dp[mask | (1 << i)], { rides, currentWeight + weight[i] });
                }
                else {
                    dp[mask | (1 << i)] = min(dp[mask | (1 << i)], { rides + 1, weight[i] });
                }
            }
        }
    }

    cout << dp[(1 << n) - 1].first << endl;
    return 0;
}
