
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int count = 0;
	static int N;
	static int map[][];

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		N = Integer.parseInt(br.readLine());
		map= new int[N+1][N+1];
		int garo[][] = new int[N+1][N+1]; 
		int sero[][] = new int[N+1][N+1]; 
		int deagak[][] = new int[N+1][N+1]; 
		
		for(int i = 1; i<=N; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j = 1; j<=N; j++)
			{
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		garo[1][2] =1;
		
		for(int i = 1; i<=N; i++)
		{
			for(int j = 1; j<=N; j++)
			{
				if((i==1&&j<=2)||map[i][j]==1) continue;
				
				garo[i][j] = garo[i][j-1]+deagak[i][j-1];
				sero[i][j] = sero[i-1][j]+deagak[i-1][j];
				
				if(map[i-1][j]==1||map[i][j-1]==1)continue;
				deagak[i][j] = garo[i-1][j-1]+sero[i-1][j-1]+deagak[i-1][j-1];
			}
		}
		
		System.out.println(garo[N][N]+sero[N][N]+deagak[N][N]);

	}
	
	public static void pipeMove(int x, int y, int dir)
	{
		if(x == N && y == N)
		{
			count++;
			return;
		}
		
		if(x>N||y>N)
		{
			return;
		}
		
		if(map[x][y] == 1)
		{
			return;
		}
		
		if(dir == 0)
		{
			pipeMove(x,y+1,0);
		}
		else if(dir == 1)
		{
			pipeMove(x+1,y,1);
		}
		else
		{
			pipeMove(x,y+1,0);
			pipeMove(x+1,y,1);
		}
		pipeMove(x+1,y+1,2);
	}

}
