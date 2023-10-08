#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) 
{
	if (a.second == b.second) 
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}


int main()
{
	vector<pair<int, int>> a;
	int n;

	cin >> n;

	int x; int y;

	for (int i = 0; i < n; i++) 
	{
		cin >> x >> y;

		a.push_back(make_pair(x, y));
	}

	sort(a.begin(), a.end(), compare);

	for (int i = 0; i < n; i++) 
	{
		cout << a[i].first << " " << a[i].second << "\n";
	}
}