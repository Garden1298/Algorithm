#include <iostream>
using namespace std;

int main()
{
	int answer = 0;
	char map[8][8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> map[i][j];
		}
	}


	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < 8; j += 2)
			{
				if (map[i][j] == 'F')
				{
					answer++;
				}
			}
		}
		else
		{
			for (int j = 1; j < 8; j += 2)
			{
				if (map[i][j] == 'F')
				{
					answer++;
				}
			}
		}

	}

	cout << answer;
}