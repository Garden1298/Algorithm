import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static class Shark {
		int r;
		int c;
		int speed;
		int direction;
		int size;

		public Shark(int r, int c, int speed, int direction, int size) {
			super();
			this.r = r;
			this.c = c;
			this.speed = speed;
			this.direction = direction;
			this.size = size;
		}
	}

	// d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미
	static int direction[][] = { { 0, 0 }, { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
	static List<Shark> sharkList = new ArrayList<>();// 낚시터의 상어 리스트
	static int R, C, sharkSizeSum = 0;// 잡은 상어 크기의 합
	static Shark map[][];// 동일한 칸에 있는 상어를 체크할 맵 정보

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		R = Integer.parseInt(st.nextToken());// (2 ≤ R ≤ 100)
		C = Integer.parseInt(st.nextToken());// (2 ≤ C ≤ 100)
		int sharkCnt = Integer.parseInt(st.nextToken());// (0 ≤ M ≤ R×C)
		map = new Shark[R][C];

		for (int i = 0; i < sharkCnt; i++) {
			st = new StringTokenizer(br.readLine());

			int r = Integer.parseInt(st.nextToken()) - 1;
			int c = Integer.parseInt(st.nextToken()) - 1;
			int speed = Integer.parseInt(st.nextToken());
			int direction = Integer.parseInt(st.nextToken());
			int size = Integer.parseInt(st.nextToken());

			if (direction <= 2) {
				speed %= (R - 1) * 2;
			} else {
				speed %= (C - 1) * 2;
			}

			Shark shark = new Shark(r, c, speed, direction, size);
			sharkList.add(shark);
			map[r][c] = shark;
		}

		for (int i = 0; i < C; i++) {
			catchShark(i);
			moveShark();
			eatShark();
		}
		System.out.println(sharkSizeSum);
	}

	//같은 칸에 상어가 있으면 잡아 먹는다.
	private static void eatShark() 
	{
		map = new Shark[R][C];

		for (int i = sharkList.size()-1; i >= 0; i--) 
		{
			Shark shark = sharkList.get(i);

			int posR = shark.r;
			int posC = shark.c;
			int size = shark.size;

			if (map[posR][posC] == null) 
			{
				map[posR][posC] = shark;
			} 
			else 
			{
				if (map[posR][posC].size < size) 
				{
					sharkList.remove(map[posR][posC]);
					map[posR][posC] = shark;
				}
				else 
				{
					sharkList.remove(shark);
				}
			}
		}
	}

//상어 움직이기
	private static void moveShark() {

		for (Shark shark:sharkList) {

			int curR = shark.r;
			int curC = shark.c;
			int dir = shark.direction;// 해당 상어의 방향 가져오기

			for (int j = 0; j < shark.speed; j++) {

				int nextR = curR + direction[dir][0];
				int nextC = curC + direction[dir][1];

				// 범위를 나갔다면 방향 바꿔주기
				if (nextR < 0 || nextC < 0 || nextR >= R || nextC >= C) 
				{
					if (dir == 1) dir = 2;
					else if (dir == 2) dir = 1;
					else if (dir == 3) dir = 4;
					else if (dir == 4) dir = 3;

				}
				
				// 반대방향 이동값 넣기
				curR += direction[dir][0];
				curC += direction[dir][1];
			}
			
			shark.direction = dir;
			shark.r = curR;
			shark.c = curC;
		}
	}

//해당 열의 가장 땅과 가까운 상어 잡기
	static void catchShark(int garo) 
	{
		for (int i = 0; i < R; i++) 
		{
			if (map[i][garo] != null) 
			{
				sharkSizeSum += map[i][garo].size;
				sharkList.remove(map[i][garo]);
				return;
			}
		}
	}
}