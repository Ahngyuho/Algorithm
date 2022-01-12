#include<iostream>
#include<cstring>
#include<vector>

#define MAX 2000 + 1

using namespace std;

int n, m;
bool visited[MAX], ans = false;
vector<int> v[MAX];

void dfs(int idx, int cnt) {
	if (cnt == 4) {
		ans = true;
		return;
	}

	visited[idx] = true;

	for (int i = 0; i < v[idx].size(); i++) {
		int x = v[idx][i];
		if (visited[x] == false) {
			dfs(x, cnt + 1);
		}
		if (ans == true) return;
	}
    visited[idx] = false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 0; i < n; i++) {
		memset(visited, false, sizeof(visited));
		dfs(i, 0);
		if (ans == true) break;
	}
	if (ans == true) cout << 1 << "\n";
	else cout << 0 << "\n";
}