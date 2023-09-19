#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n, answer = 0;
	string str;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		stack<char> alpha;

		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			if (alpha.empty())
			{
				alpha.push(str[j]);
			}
			else
			{
				int preAlpha = alpha.top();
				int curAlpha = str[j];

				if (preAlpha == curAlpha)
				{
					alpha.pop();
				}
				else
				{
					alpha.push(curAlpha);
				}
			}
		}

		if (alpha.empty())
		{
			answer++;
		}
	}

	cout << answer;

	return 0;
}