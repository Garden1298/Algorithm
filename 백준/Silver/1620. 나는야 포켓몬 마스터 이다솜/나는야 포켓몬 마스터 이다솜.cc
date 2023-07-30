#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M;
map<int, string> num2Name;
map<string, int> name2Num;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int num;
	string name;
	for (int i = 1; i <= N; i++)
	{
		cin >> name;

		num2Name.insert(make_pair(i, name));
		name2Num.insert(make_pair(name, i));
	}

	string question;
	for (int i = 0; i < M; i++)
	{
		cin >> question;

		//포켓몬 이름일때
		if (question[0] >= 65 && question[0] <= 90)
		{
			cout <<name2Num[question] << "\n";
		}
		//번호 일때
		else
		{
			cout << num2Name[stoi(question)] << "\n";
		}
	}
}
