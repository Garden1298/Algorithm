#include <iostream>

using namespace std;

int main()
{
	int x, n;

	cin >> n >> x;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		if (num < x)
		{
			cout << num;

			if (i < n - 1)
			{
				cout << " ";
			}
		}
	}
}