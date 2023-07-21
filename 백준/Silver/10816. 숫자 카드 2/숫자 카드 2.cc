#include <iostream>
//#include <map>
#include<algorithm>

using namespace std;

int N, M;
int num;
//map<int, int> m;
int arr[500002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	//for (int i = 0; i < N; i++)
	//{
	//	cin >> num;
	//	m[num]++;
	//}

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		arr[i] = num;
	}

	sort(arr, arr + N);

	//cin >> M;

	cin >> M;

	//for (int i = 0; i < M; i++)
	//{
	//	cin >> num;
	//	cout << m[num] << " ";
	//}

	for (int i = 0; i < M; i++)
	{
		cin >> num;
		cout << upper_bound(arr, arr + N, num) - lower_bound(arr, arr + N, num) << " ";
	}
}