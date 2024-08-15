#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void solve(int a[], int n, int s) {
	int* dp = new int[s + 1];
	dp[0] = 0;
	for (int i = 1; i <= s; i++) {
		dp[i] = s+1;
		for (int j = 0; j < n; j++) {
			if (i - a[j] >= 0) {
				dp[i] = min(dp[i], dp[i - a[j]] + 1);
			}
		}
	}
	if (dp[s] == s+1) {
		cout << -1;
		return;
	}
	cout << dp[s];
	int sum = dp[s];
	delete[] dp;
}
int main() {
	int n, s; cin >> n >> s;
	int  a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	solve(a, n, s);
}