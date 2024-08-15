#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve(int a[], int n, int s) {
	int dp[n + 1][s + 1];
	vector<int> v;
	for (int i = 0; i < n; i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i <= s; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= s; j++) {
			if (j - a[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
			}
			else dp[i][j] = dp[i - 1][j];
			if (find(v.begin(),v.end(),dp[i][j])==v.end()&&dp[i][j]!=0) v.push_back(dp[i][j]);
		}
	}
	cout<<v.size()<<endl;
	sort(v.begin(),v.end());
	for (int i=0;i<v.size();i++){
	    cout<<v[i]<<" ";
	}
}
int main() {
	int n;
	cin >> n;
	int a[n+1];
	int sum=0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum+=a[i];
	}
	solve(a, n, sum);
}