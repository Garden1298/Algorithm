import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int map[][];
	static boolean isVisited[];
	
	static int index[];
	static long minDist = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		isVisited = new boolean[N];
		index = new int[N];
		
		for(int i = 0; i<N; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j<N; j++)
			{
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		perm(0);

		System.out.println(minDist);
	}

	private static void perm(int cnt) 
	{
		if(cnt==N)
		{
			calculateDistance();
			
			return;
		}
		
		for(int i = 0; i<N; i++)
		{
			if(isVisited[i] == true) continue;
			isVisited[i] = true;
			index[cnt]=i;
			perm(cnt+1);
			isVisited[i] = false;
		}
	}
	
	private static void calculateDistance()
	{
		long dist = 0;
		
		for(int i = 0; i<N-1; i++)
		{
			if(map[index[i]][index[i+1]]==0)return;
			
			dist += map[index[i]][index[i+1]];
		}
		
		if(map[index[N-1]][index[0]]==0)return;
		
		dist += map[index[N-1]][index[0]];
		
		minDist = Math.min(minDist, dist);
	}


}
