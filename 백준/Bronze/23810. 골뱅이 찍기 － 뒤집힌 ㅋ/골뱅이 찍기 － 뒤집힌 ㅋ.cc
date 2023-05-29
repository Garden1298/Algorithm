#include <iostream>
using namespace std;

void EmptyBox(int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << "@";
		}

		//for (int j = 0; j < N * 3; j++)
		//{
		//	cout << " ";
		//}

		cout << endl;
	}
}

void FullBox(int N)
{
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N * 5; i++)
		{
			cout << "@";
		}
		cout << endl;
	}
}

int main()
{
	int N;
	cin >> N;

	FullBox(N);

	EmptyBox(N);

	FullBox(N);

	EmptyBox(N);

	EmptyBox(N);

}