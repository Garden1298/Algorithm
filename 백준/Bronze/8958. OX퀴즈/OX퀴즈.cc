#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	string str;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> str;
		int sum = 0, cnt = 0;

		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == 'O')
			{
				cnt++;
			}
			else
			{
				cnt = 0;
			}
			sum += cnt;
		}
		cout << sum << endl;
	}
}