/*#include<iostream>
#include<algorithm>

#define MAX 100000 + 1
using namespace std;

int dp[MAX];
int N;

int main() {
	cin >> N;

	for (long long i = 1; i <= N; i++) {
		long long pow = i * i;

		if (pow <= 100000)
		dp[pow] = 1;

		if (dp[i] == 0) {
			long long j = i - 1;
			long long k = 1;
			dp[i] = dp[j] + dp[k];
			while (j >= k)
			{
				if (dp[i] == 2)
					break;
				dp[i] = min(dp[i], dp[j] + dp[k]);
				j--;
				k++;
			}
		}
	}

	cout << dp[N] << "\n";
}*/

#include<iostream>
#include<algorithm>

#define MAX 100000 + 1
using namespace std;

int dp[MAX];
int N;

int main() 
{
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= N; i++)
		dp[i] = i;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; i >= j * j; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[N] << "\n";
}