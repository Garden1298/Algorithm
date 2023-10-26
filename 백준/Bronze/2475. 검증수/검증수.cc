#include <iostream>
using namespace std;

int main() 
{
	int input, answer = 0;
	int result = 0;

	for (int i = 0; i < 5; i++) 
    {
		cin >> input;

		result += input * input;
	}
	answer = result % 10;

	cout << answer;
}