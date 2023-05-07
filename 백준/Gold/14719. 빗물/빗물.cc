#include <iostream>
using namespace std;

int block[501][501];

int main()
{
	int H, W;
	cin >> H >> W;

	int height;
	for (int i = 0; i < W; i++)
	{
		cin >> height;
		for (int j = 0; j < height; j++)
		{
			block[j][i] = 1;
		}
	}

	//위에서부터 아래로
	for (int i = H - 1; i >= 0; i--)
	{
		int left = 0;
		int right = W - 1;

		//가장 왼쪽 블럭과 오른쪽 블럭이 있다면 해당하는 라인은 모두 물로 채우기 가능
		if (block[i][left] == 1 && block[i][right] == 1) break;

		while (block[i][left] == 0)
		{
			block[i][left] = -1;
			left++;
		}

		while (block[i][right] == 0)
		{
			block[i][right] = -1;
			right--;
		}
	}

	int answer = 0;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (block[i][j] == 0)
			{
				answer++;
			}
		}
	}

	cout << answer << endl;
}