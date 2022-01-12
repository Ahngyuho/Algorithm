#include<iostream>
using namespace std;

int dp[1001];

int main()
{
	int N;

	dp[0] = 1;
	dp[1] = 1;

	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}

	cout << dp[N];
}