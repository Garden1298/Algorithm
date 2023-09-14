#include <iostream>
#include <string>
using namespace std;

int n, m, smallSide;
int map[51][51];

int main()
{
	cin >> n >> m;

	smallSide = n > m ? m : n;

	string input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = input[j] - '0';
		}
	}

	int max = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 1; k < smallSide; k++)
			{
				//범위체크
				if (i + k < n && j + k < m)
				{
					if (map[i][j] == map[i + k][j] && map[i][j] == map[i][j + k] && map[i][j] == map[i + k][j + k])
					{
						max = max > k + 1 ? max : k + 1;
					}
				}
			}
		}
	}

	cout << max * max;
}