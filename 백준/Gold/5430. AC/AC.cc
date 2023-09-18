#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;

	string p, input;
	int num;

	for (int TC = 0; TC < T; TC++)
	{
		deque<string> nums;
		cin >> p >> num >> input;

		string tmp = "";
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '[') continue;
			else if (input[i] == ',' || input[i] == ']')
			{
				if (tmp == "") continue;
				nums.push_back(tmp);
				tmp = "";
			}
			else
			{
				tmp.push_back(input[i]);
			}
		}

		bool reversed = false;
		bool error = false;
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
			{
				reversed = reversed ? false : true;
			}
			else if (p[i] == 'D')
			{
				if (nums.size() == 0)
				{
					error = true;
					break;
				}
				if (reversed)
				{
					nums.pop_back();
				}
				else
				{
					nums.pop_front();
				}
			}
		}

		if (error)
		{
			cout << "error" << '\n';
		}
		else
		{
			if (reversed)
			{
				reverse(nums.begin(), nums.end());
			}

			cout << '[';
			for (int i = 0; i < nums.size(); i++)
			{
				cout << nums[i];
				if (i != nums.size() - 1)
				{
					cout << ',';
				}
			}
			cout << ']' << '\n';
		}
	}
}