#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, M;
map<string, bool> m;
int answer = 0;

int main()
{

	cin >> N >> M;

	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		m.insert(make_pair(str, true));
	}

	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (m[str] == true)
		{
			answer++;
		}
	}

	cout << answer;
}