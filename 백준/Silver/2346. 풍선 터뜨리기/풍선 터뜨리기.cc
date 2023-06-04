#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque<int> index;
vector<int> answer;
int value[1001] = { 0, };
int N;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> value[i];
		index.push_back(i + 1);
	}

	for (int i = 0; i < N; i++)
	{
		int curIndex = index.front();
		cout << curIndex<<" ";

		if (index.size() == 1)return 0;

		answer.push_back(curIndex);
		index.pop_front();

		int curValue = value[curIndex - 1];

		if (curValue > 0)
		{
			for (int j = 0; j < curValue - 1; j++)
			{
				index.push_back(index.front());
				index.pop_front();
			}
		}
		else
		{
			for (int j = 0; j < -curValue; j++)
			{
				index.push_front(index.back());
				index.pop_back();
			}
		}
	}
}
