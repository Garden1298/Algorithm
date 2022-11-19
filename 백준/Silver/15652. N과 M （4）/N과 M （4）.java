import java.util.Scanner;

public class Main {
	
	static int N,M;
	static int num[];
//	static boolean isVisited[];
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		M = sc.nextInt();
		num = new int[M];
//		isVisited = new boolean[N];
		
		comb(0, 0);
		
		System.out.println(sb);
	}
	
	static void comb(int cnt, int start)
	{
		if(cnt == M)
		{
			for(int i = 0; i<M; i++)
			{
				sb.append(num[i]+" ");
			}
			sb.append('\n');
			return;
		}
		
		for(int i = start; i<N; i++)
		{
//			if(isVisited[i])continue;
			num[cnt] = i+1;
//			isVisited[i] = true;
			comb(cnt+1, i);
//			isVisited[i] = false;
			
		}
	}

}