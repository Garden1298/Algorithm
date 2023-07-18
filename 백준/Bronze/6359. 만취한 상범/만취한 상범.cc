#include <iostream>

using namespace std;


int main()
{
	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int room[101] = { 0, };
		int n;

		cin >> n;

		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; j * k <= n; k++)
			{
				room[j * k] = room[j * k] == 1 ? 0 : 1;
			}
		}

		int cnt = 0;

		for (int j = 1; j <= n; j++)
		{
			if (room[j] == 1) cnt++;
		}

		cout << cnt << endl;
	}
}