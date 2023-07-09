#include <iostream>

using namespace std;

int N;
pair<int, int> chart[51];

int main()
{
	cin >> N;

	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;

		chart[i].first = x;
		chart[i].second = y;
	}

	for (int i = 0; i < N; i++)
	{
		int rank = 0;
		for (int j = 0; j < N; j++)
		{
			if (chart[i].first < chart[j].first && chart[i].second < chart[j].second)
			{
				rank++;
			}
		}
		cout << rank + 1<<" ";
	}
}