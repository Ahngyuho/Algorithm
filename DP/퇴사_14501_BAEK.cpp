#include<iostream>
#include<algorithm>

using namespace std;

int arr[16][2];
int dp[16];
int N;
int ans;

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		if (i + arr[i][0] - 1 <= N) {
			int idx = i + arr[i][0] - 1;
			dp[idx] = max(dp[idx], dp[i - 1] + arr[i][1]);
		}
		dp[i] = max(dp[i - 1], dp[i]);
	}

	for (int i = 1; i <= N; i++) {
		ans = max(dp[i], ans);
	}


	cout << ans;

}