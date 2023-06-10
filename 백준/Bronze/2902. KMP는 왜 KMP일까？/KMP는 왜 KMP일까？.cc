#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	string kmp;
	kmp += str[0];

	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == '-')
		{
			kmp += str[i + 1];
		}
	}

	cout << kmp;
}