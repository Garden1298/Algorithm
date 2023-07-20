#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
map<string, int> m;
vector<string> v;

int main()
{
	cin >> N >> M;

	string input;
	for (int i = 0; i < N + M; i++)
	{
		cin >> input;
		m[input]++;
		if (m[input]>1)//1개 보다 많다면 (듣도 보도 못했다면,,!)
		{
			v.push_back(input);//명단에 넣기
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}