import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	
	static int map[][];
	static boolean isVisited[][];
	static int mapLength, maxConsDepth, maxHeight = 0, maxLength = 0;
	static int direction[][] = {{0,1},{0,-1},{1,0},{-1,0}};//상하좌우

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc<=T; tc++)
		{
			st = new StringTokenizer(br.readLine());
			
			maxLength = 0;
			maxHeight = 0;
			
			mapLength = Integer.parseInt(st.nextToken());//지도의 한 변의 길이 N
			maxConsDepth = Integer.parseInt(st.nextToken());//최대 공사 가능 깊이 K
			
			map = new int[mapLength][mapLength];
			
			for(int i = 0; i<mapLength; i++)
			{
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j<mapLength; j++)
				{
					int input = Integer.parseInt(st.nextToken());
					map[i][j] = input;
					maxHeight = Math.max(maxHeight, input);//가장 높은 지점의 높이 찾기
				}
			}
			
			for(int i = 0; i<mapLength; i++)
			{
				for(int j = 0; j<mapLength; j++)
				{
					if(map[i][j]==maxHeight)//가장 높은 지형일 경우만 탐색
					{
						isVisited = new boolean[mapLength][mapLength];//방문배열 초기화
						isVisited[i][j] = true;
						dfs(i,j, maxHeight, 1, false);//현재 좌표, 현재 높이, 길이, 공사 여부
					}
				}
			}
			
			System.out.println("#"+tc+" "+maxLength);
		}

	}
	
	//현재 좌표, 현재 높이, 등산로 길이, 공사 여부
	private static void dfs(int curA, int curB, int curHeight, int curLength, boolean isConstructed) {
		
		maxLength = Math.max(maxLength, curLength);//최대 길이 갱신
		
		for(int dir = 0; dir<direction.length; dir++)
		{
			int nextA = curA + direction[dir][0];
			int nextB = curB + direction[dir][1];
			
			if(nextA<0||nextB<0||nextA>=mapLength||nextB>=mapLength) continue;//범위체크
			if(isVisited[nextA][nextB]) continue;//방문체크
			isVisited[nextA][nextB] = true;
			
			int nextHeight = map[nextA][nextB];
			
			if(curHeight>nextHeight)//현재 높이가 다음 높이보다 크다면 공사없이 등산로를 지을 수 있다
			{
				dfs(nextA, nextB, nextHeight, curLength+1, isConstructed);
			}
			else//현재 높이가 다음 높이보다 작거나 같다면 공사를 해야 등산로를 지을 수 있다
			{
				if(!isConstructed)//공사 횟수가 남아있다면
				{
					if(curHeight>nextHeight-maxConsDepth)//공사해서 현재 높이보다 낮아진다면
					{
						nextHeight = curHeight-1;//최소한으로만 깍는다
						dfs(nextA, nextB, nextHeight, curLength+1, true);
					}
				}
			}
			
			isVisited[nextA][nextB] = false;
		}
	}

}
