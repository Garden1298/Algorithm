#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int>> input;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		input.push_back(make_pair(a,b));
	}

	sort(input.begin(), input.end());

	for (int i = 0; i < n; i++)
	{
		cout << input[i].first << " " << input[i].second << '\n';
	}

	return 0;
}