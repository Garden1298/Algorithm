#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int N, M;
vector<int> a, b;

int main()
{
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		a.clear();
		b.clear();

		cin >> N >> M;

		int num;
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			a.push_back(num);
		}
		for (int i = 0; i < M; i++)
		{
			cin >> num;
			b.push_back(num);
		}

		//오름차순 정렬
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int result = 0;
		for (int num : a)
		{
			result += (lower_bound(b.begin(), b.end(), num) - b.begin());
		}

		cout << result << endl;
	}
}