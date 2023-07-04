#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int a = 1, b = 1;

		cin >> a >> b;

		b = b % 4 == 0 ? 4 : b % 4;

		long long answer = pow(a, b);
	
		if (answer % 10 == 0)
		{
			cout << 10 << endl;
		}
		else
		{
			cout << answer % 10 << endl;
		}
	}
}