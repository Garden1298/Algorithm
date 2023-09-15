#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n;
map<string, int> savefile;
vector<string> names;

int main()
{
	cin >> n;

	string name, state;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> state;

		savefile[name] = state == "enter" ? 1 : 0;
	}

	for (auto data : savefile)
	{
		if (data.second == 1)
		{
			names.push_back(data.first);
		}
	}

	sort(names.rbegin(),names.rend());

	for (auto name : names)
	{
		cout << name << "\n";
	}
}