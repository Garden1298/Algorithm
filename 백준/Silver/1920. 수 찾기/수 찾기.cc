#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[100001] = { 0, };
int num;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	cin >> M;

	sort(arr, arr + N);


	for (int i = 0; i < M; i++)
	{
		cin >> num;

		// num을 찾으면 1 아니면 0을 반환한다.
		cout << binary_search(arr, arr + N, num) << '\n';
	}
}