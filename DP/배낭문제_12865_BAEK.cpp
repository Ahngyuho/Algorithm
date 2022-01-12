#include<stdio.h>

int max(int x, int y);

int dp[101][100001];

int main() {
	int V[101], W[101];
	int N, K;
	

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &W[i], &V[i]);
	}

	for (int i = 0; i <= N; i++) {
		dp[i][0] = 0;
	}

	for (int i = 0; i <= K; i++) {
		dp[0][i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			/*if (W[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}*/
			dp[i][j] = dp[i - 1][j];
			if (j - W[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i]] + V[i]);
			}
		}
	}

	printf("%d\n", dp[N][K]);
}

int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}