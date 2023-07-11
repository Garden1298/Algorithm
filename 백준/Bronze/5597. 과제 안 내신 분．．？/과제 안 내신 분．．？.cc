#include <iostream>
using namespace std;

int main()
{
	bool assignment[30] = { false, };

	int input;
	for (int i = 0; i < 28; i++)
	{
		cin >> input;
		assignment[input - 1] = true;
	}

	for (int i = 0; i < 30; i++)
	{
		if (!assignment[i])
		{
			cout << (i + 1) << endl;
		}
	}
}