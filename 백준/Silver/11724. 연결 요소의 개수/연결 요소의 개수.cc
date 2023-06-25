#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> connect[1001];
bool visited[1001];

void bfs(int start)
{
	queue<int> q;
	q.push(start);

	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		int curSize = connect[cur].size();
		for (int i = 0; i < curSize; i++)
		{
			int next = connect[cur][i];
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;

		cin >> u >> v;

		//양방향 연결
		connect[u].push_back(v);
		connect[v].push_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			cnt++;
			bfs(i);
		}
	}
	cout << cnt;
}