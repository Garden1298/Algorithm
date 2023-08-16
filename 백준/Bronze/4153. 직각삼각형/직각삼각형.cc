#include <iostream>
using namespace std;

int main()
{
	while (true)
	{
		int x, y, z;

		int tmp = 0;

		cin >> x >> y >> z;

		if (x == 0 && y == 0 && z == 0)
		{
			return 0;
		}

		if (x > y)
		{
			tmp = y;
			y = x;
			x = tmp;
		}
		if (y > z)
		{
			tmp = z;
			z = y;
			y = tmp;
		}

		if (z * z == x * x + y * y)
		{
			cout << "right" << endl;
		}
		else
		{
			cout << "wrong" << endl;
		}

	}
}