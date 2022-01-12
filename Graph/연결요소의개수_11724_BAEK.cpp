#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define MAX 1000 + 1

vector<int> v[MAX];
bool visited[MAX];
int N, M;
int cnt;

void dfs(int idx);

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y;

		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;

}

void dfs(int idx) {
	visited[idx] = true;

	for (int i = 0; i < v[idx].size(); i++) {
		int x = v[idx][i];

		if (visited[x] == false) {
			dfs(x);
		}
	}
}