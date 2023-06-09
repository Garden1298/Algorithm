#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	cin >> N;

	priority_queue<int,vector<int>, greater<int>> pq;
	int size = N * N;
	int input;
	for (int i = 0; i < size; i++)
	{
		cin >> input;
		pq.push(input);
		if (pq.size() > N)
		{
			pq.pop();
		}
	}

	cout << pq.top();
	
	return 0;
}