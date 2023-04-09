#include <iostream>
using namespace std;

int main()
{
	int N; 

	cin >> N;

	cout << ((N % 7 == 0 || N % 7 == 2) ? "CY" : "SK");
}