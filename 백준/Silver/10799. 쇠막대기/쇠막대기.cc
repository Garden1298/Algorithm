#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> S;
string input;
int total = 0;

int main() {
	cin >> input;
	for (int i = 0; i < input.length(); i++) 
    {
		if (input[i] == '(') 
        {
			S.push(input[i]);
		}
		else if (input[i] == ')' and input[i - 1] == '(') 
        {
			S.pop();
			total += S.size();
		}
		else 
        {
			total++;
			S.pop();
		}
	}
	cout << total << endl;
}