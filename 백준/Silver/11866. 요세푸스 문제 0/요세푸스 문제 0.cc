#include<iostream>
#include<deque>

using namespace std;

int main()
{
	int N, K;

	cin >> N >> K;

	deque<int> dq;
	deque<int> answer;

	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	int cnt = 0;

	while (dq.size() > 0)
	{
		int curNum = dq.front();
		dq.pop_front();

		cnt++;

		if (cnt != K)
		{
			dq.push_back(curNum);
		}
		else
		{
			answer.push_back(curNum);
			cnt = 0;
		}
	}

	cout << "<";

	for (int i = 0; i < N - 1; i++)
	{
		cout << answer[i] << ", ";
	}

	cout << answer[N - 1] << ">";
}