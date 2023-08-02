#include <iostream>

using namespace std;

int o, w;
char action;
int t;
int tc = 0;

int main()
{
	while (true)
	{
		tc++;

		bool die = false;

		cin >> o >> w;

		if (o == 0 && w == 0) break;

		while (true)
		{
			cin >> action >> t;

			if (action == '#') break;

			if (!die)
			{
				if (action == 'E')
				{
					w -= t;
				}
				else if (action == 'F')
				{
					w += t;
				}
			}

			if (w <= 0)
			{
				die = true;
			}
		}

		if (w > o / 2 && w < o * 2)
		{
			cout << tc << " :-)" << endl;
		}
		else if (w <= 0)
		{
			cout << tc << " RIP" << endl;
		}
		else
		{
			cout << tc << " :-(" << endl;
		}
	}
}