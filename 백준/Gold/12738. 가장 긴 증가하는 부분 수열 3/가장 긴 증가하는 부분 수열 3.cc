#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> nums;

int main()
{
	cin >> N;

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		nums.push_back(input);
	}

	vector<int>result;
	result.push_back(nums[0]);
	for (int i = 1; i < N; i++)
	{
		if (result.back() > nums[i])
		{
			int index = lower_bound(result.begin(), result.end(), nums[i]) - result.begin();
			result[index] = nums[i];
		}
		else if(result.back() < nums[i])
		{
			result.push_back(nums[i]);
		}
	}

	cout << result.size() << endl;

	return 0;
}