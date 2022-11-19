import java.util.Scanner;

public class Main {
	
	static int N,M;
	static int num[];
	static boolean isVisited[];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		M = sc.nextInt();
		num = new int[M];
		isVisited = new boolean[N];
		
		perm(0);
	}
	
	static void perm(int cnt)
	{
		if(cnt == M)
		{
			for(int i = 0; i<M; i++)
			{
				System.out.print(num[i]+" ");
			}
			System.out.println();
			return;
		}
		
		for(int i = 0; i<N; i++)
		{
			if(isVisited[i])continue;
			num[cnt] = i+1;
			isVisited[i] = true;
			perm(cnt+1);
			isVisited[i] = false;
			
		}
	}

}