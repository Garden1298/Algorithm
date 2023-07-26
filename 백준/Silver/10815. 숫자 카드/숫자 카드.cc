#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> card;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;

		card.push_back(num);
	}

	sort(card.begin(), card.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> num;

		cout << binary_search(card.begin(), card.end(), num) << " ";
	}
}