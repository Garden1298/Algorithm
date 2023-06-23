#include <iostream>
#include <map>

using namespace std;

int main()
{
	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;

		cin >> n;

		map<string, int> fashion;

		string cloth, category;

		for (int j = 0; j < n; j++)
		{
			cin >> cloth >> category;
			fashion[category] += 1;
		}

		int result = 1;

		for (auto a : fashion)
		{
			result *= a.second + 1;
		}

		cout << result - 1 << endl;
	}
}