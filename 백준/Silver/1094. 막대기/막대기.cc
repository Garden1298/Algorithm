#include <iostream>
using namespace std;

int X;
int sum = 64;
int minStick = 64;
int answer = 1;

int main()
{
	cin >> X;

	while (sum > X)
	{
		minStick = minStick / 2;

		if (sum - minStick >= X)
		{
			sum -= minStick;
		}
		else
		{
			answer++;
		}
	}

	cout << answer;
}