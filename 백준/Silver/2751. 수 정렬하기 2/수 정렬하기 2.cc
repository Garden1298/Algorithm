#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> nums;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	int num;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		nums.push_back(num);
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < N; i++)
	{
		cout << nums[i] << "\n";
	}
}