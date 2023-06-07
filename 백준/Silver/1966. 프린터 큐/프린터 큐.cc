#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int TC = 0;
	cin >> TC;

	for (int i = 0; i < TC; i++)
	{
		int N = 0;//문서의 개수
		int M = 0;//몇 번째로 인쇄되는지 궁금한 문서

		cin >> N >> M;

		queue<pair<int, int>> paper;//index,value
		priority_queue<int> order;

		int num;
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			paper.push({ j,num });
			order.push(num);
		}
		
		int index, value;
		int cnt = 0;

		while (!paper.empty())
		{
			index = paper.front().first;
			value = paper.front().second;

			paper.pop();

			if (order.top() == value)
			{
				order.pop();
				cnt++;
				if (index == M)
				{
					cout << cnt << endl;
					break;
				}
			}
			else
			{
				paper.push({ index,value });
			}
		}
	}
}