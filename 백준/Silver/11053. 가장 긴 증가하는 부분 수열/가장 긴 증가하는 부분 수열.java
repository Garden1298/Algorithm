import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		int N = Integer.parseInt(br.readLine());
		
		int arr[] = new int[N];
		int memo[] = new int[N];
		
		Arrays.fill(memo, 1);
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i<N; i++)
		{
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<i; j++)
			{
				if(arr[i]>arr[j])//련재 값이 더 크다면
				{
					memo[i] = Math.max(memo[i], memo[j]+1);
				}
			}
		}
		
		int answer = 0;
		for(int i = 0; i<N; i++)
		{
			answer = Math.max(answer, memo[i]);
		}
		
		System.out.println(answer);

	}

}
