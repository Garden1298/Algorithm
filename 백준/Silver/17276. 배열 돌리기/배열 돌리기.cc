#include <iostream>
#include <memory.h>
using namespace std;

//X의 주 대각선을((1, 1), (2, 2), …, (n, n)) 가운데 열((n + 1) / 2 번째 열)로 옮긴다.
//X의 가운데 열을 X의 부 대각선으로((n, 1), (n - 1, 2), …, (1, n)) 옮긴다.
//X의 부 대각선을 X의 가운데 행((n + 1) / 2번째 행)으로 옮긴다.
//새로운 임시 배열을 생성하여, 그 배열에 대입하는 방식으로 넣어가면서 구현했는데,
//잘 보면 시계 방향일 때와 반시계 방향일 때 배열의 인덱스가 서로 반대인 것을 알 수 있습니다.때문에 어느 방향이든 둘 중 하나만 제대로 구현해준다면 나머지 한쪽은 그냥 인덱스만 서로 바꿔주면 됩니다.

int map[501][501] = { 0, };
int temp[501][501];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, d; 
		cin >> n >> d;
		for (int i = 0; i < n; i++) 
		{
			for (int k = 0; k < n; k++) 
			{
				cin >> map[i][k];
			}
		}
		memcpy(temp, map, sizeof(temp));
		if (d > 0) 
		{
			int cnt = d / 45;
			while (cnt--) 
			{
				for (int i = 0; i < n; i++) temp[i][(n + 1) / 2 - 1] = map[i][i];
				for (int i = 0; i < n; i++) temp[i][i] = map[(n + 1) / 2 - 1][i];
				for (int i = n - 1; i >= 0; i--) temp[(n + 1) / 2 - 1][n - 1 - i] = map[i][n - 1 - i];
				for (int i = n - 1; i >= 0; i--) temp[i][n - 1 - i] = map[i][(n + 1) / 2 - 1];
				memcpy(map, temp, sizeof(map));
			}
		}
		else 
		{
			int cnt = abs(d) / 45;
			while (cnt--) 
			{
				for (int i = 0; i < n; i++) temp[i][i] = map[i][(n + 1) / 2 - 1];
				for (int i = 0; i < n; i++) temp[(n + 1) / 2 - 1][i] = map[i][i];
				for (int i = n - 1; i >= 0; i--) temp[i][n - 1 - i] = map[(n + 1) / 2 - 1][n - 1 - i];
				for (int i = n - 1; i >= 0; i--) temp[i][(n + 1) / 2 - 1] = map[i][n - 1 - i];
				memcpy(map, temp, sizeof(map));
			}
		}
		for (int i = 0; i < n; i++) 
		{
			for (int k = 0; k < n; k++) 
			{
				cout << temp[i][k] << ' ';
			}
			cout << '\n';
		}
	}
}