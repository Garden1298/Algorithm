#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int num[8];
int answer[8];

void dfs(int start, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << answer[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = start; i < n; i++)
	{
		answer[cnt] = num[i];
		dfs(i,cnt+1);
	}

	return;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	sort(num,num+n);

	dfs(0,0);
}