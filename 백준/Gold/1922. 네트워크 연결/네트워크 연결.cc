#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];

int Find(int x)
{
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	parent[y] = parent[x];
}

int main()
{
	int n, m;
	int answer = 0;

	cin >> n >> m;

	vector<pair<int, pair<int, int>>> network;

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		
		network.push_back(make_pair(c, make_pair(a, b)));
	}

	sort(network.begin(), network.end());

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int cost = network[i].first;
		int a = network[i].second.first;
		int b = network[i].second.second;

		if (Find(a) != Find(b))
		{
			Union(a, b);
			answer += cost;
		}
	}

	cout << answer;

	return 0;
}