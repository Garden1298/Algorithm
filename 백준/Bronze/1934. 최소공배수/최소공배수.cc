#include <iostream>

using namespace std;

int GCD(int a,int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b,a%b);
	}
}


int main()
{
	int T;
	int a, b;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;

		if (a >= b)
		{
			cout << a * b / GCD(a,b) << endl;
		}
		else
		{
			cout << a * b / GCD(b, a) << endl;
		}
	}
}