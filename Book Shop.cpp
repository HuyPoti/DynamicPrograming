#include <iostream>
using namespace std;
void solve(int a[], int c[], int n, int s) {
	int dp[n + 1][s + 1];
	for (int i = 0; i < n; i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i <= s; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= s; j++) {
			if (j - a[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + c[i]);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][s];
}
int main() {
	int n, s;
	cin >> n >> s;
	// 	int a[1001];
	// 	int c[1001];
	int a[n + 1];
	int c[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	solve(a, c, n, s);
}