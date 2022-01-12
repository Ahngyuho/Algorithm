#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int E[1001][1001];

int main() 
{
	string S, T;

	cin >> S >> T;

	int m = S.size();
	int n = T.size();

	for (int i = m - 1; i >= 0; i--)
		S[i + 1] = S[i];

	for (int i = n - 1; i >= 0; i--)
		T[i + 1] = T[i];

	/*for (int i = 1; i <= m; i++)
		cout << S[i];

	for (int i = 1; i <= n; i++)
		cout << T[i];*/

	for (int i = 0; i <= m; i++)
		E[i][0] = i;

	for (int i = 0; i <= n; i++)
		E[0][i] = i;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int a;

			if (S[i] == T[j])
				a = 0;
			else
				a = 1;

			E[i][j] = min({ E[i - 1][j - 1] + a,E[i][j - 1] + 1,E[i - 1][j] + 1 });
		}
	}

	/*for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			cout << E[i][j] << " ";
		}
		cout << "\n";
	}*/

	cout << E[m][n];
}