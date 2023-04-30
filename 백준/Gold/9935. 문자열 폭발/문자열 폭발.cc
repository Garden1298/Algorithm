#include <iostream>
#include <algorithm>
using  namespace std;

string str, bomb, result="";
int main()
{
	ios:ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	cin >> bomb;

	for (int i = 0; i < str.size(); i++)
	{
		result += str[i];

		//문자열의 맨 뒤의 값이 일치하는지 확인
		if (result.back() == bomb.back())
		{
			bool check = true;

			//사이즈가 더 작으면 일치하는게 불가능함
			if (result.size() < bomb.size()) continue;

			//같은 문자열인지 확인
			for (int j = 0; j < bomb.size(); j++)
			{
				if (result[result.size() - bomb.size() + j] != bomb[j])
				{
					check = false;
					break;
				}
			}

			//폭발 문자열 존재
			if (check)
			{
				for (int j = 0; j < bomb.size(); j++)
				{
					result.pop_back();
				}
			}
		}
	}

	if (result.size() == 0)
	{
		cout << "FRULA" << endl;
	}
	else
	{
		cout << result << endl;
	}

}