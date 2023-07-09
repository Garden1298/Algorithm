#include <iostream>
#include <string>

using namespace std;

string N;
int set[10] = { 0, };

int main()
{
	cin >> N;

	int sixNine = 0;

	for (int i = 0; i < N.length(); i++)
	{
		int curInt = (int)N[i] - '0';

		if (curInt == 6 || curInt == 9)
		{
			sixNine++;
		}
		else
		{
			set[curInt]++;
		}
	}

	sixNine = (sixNine + 1) / 2;

	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		max = set[i] > max ? set[i] : max;
	}

	int answer = sixNine > max ? sixNine : max;

	cout << answer;
}