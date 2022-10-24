import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int vilage = Integer.parseInt(st.nextToken());
		int road = Integer.parseInt(st.nextToken());
		
		int graph[][] = new int[vilage+1][vilage+1];
		for(int i = 0; i<=vilage; i++)
		{
			Arrays.fill(graph[i], Integer.MAX_VALUE);
		}
		
		for(int i = 0; i<road; i++)
		{
			st = new StringTokenizer(br.readLine());
			int vilageA = Integer.parseInt(st.nextToken());
			int vilageB = Integer.parseInt(st.nextToken());
			int distance = Integer.parseInt(st.nextToken());
			
			graph[vilageA][vilageB] = distance;
		}
		
		for(int i = 1; i<=vilage; i++)
		{
			for(int j = 1; j<=vilage; j++)
			{
				for(int k = 1; k<=vilage; k++)
				{
					if(graph[j][i]==Integer.MAX_VALUE)continue;
					if(graph[i][k]==Integer.MAX_VALUE)continue;
					graph[j][k] = Math.min(graph[j][k], graph[j][i]+graph[i][k]);
				}
			}
		}
		
		int answer = Integer.MAX_VALUE;
		
		for(int i = 1; i<=vilage; i++)
		{
			answer = Math.min(answer, graph[i][i]);
		}
		
		if(answer == Integer.MAX_VALUE)
		{
			System.out.println(-1);
		}
		else
		{
			System.out.println(answer);
		}
	}

}
