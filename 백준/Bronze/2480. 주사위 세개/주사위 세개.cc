#include <iostream>
using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	if (a == b && b == c)
	{
		cout << 10000 + a * 1000;
	}
	else if (a == b || a == c)
	{
		cout << 1000 + a * 100;
	}
	else if (b == c)
	{
		cout << 1000 + b * 100;
	}
	else
	{
		int largest = max(a, b);
		largest = max(largest, c);
		cout << largest*100;
	}
}