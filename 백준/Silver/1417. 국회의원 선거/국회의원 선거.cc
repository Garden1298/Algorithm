#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int n, me;
int answer = 0;

int main()
{
	cin >> n >> me;

	int input;
	for (int i = 1; i < n; i++)
	{
		cin >> input;
		pq.push(input);
	}

	while (pq.size()) 
	{
		if (pq.top() < me)
		{
			break;
		}

		int cur = pq.top();
		pq.pop();

		answer++;
		me++;

		pq.push(cur-1);

	}

	cout << answer;
}