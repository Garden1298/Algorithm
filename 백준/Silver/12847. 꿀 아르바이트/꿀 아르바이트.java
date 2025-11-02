import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken()); //월세를 내기 바로 전 날 (1 ≤ n ≤ 100,000)
		int M = Integer.parseInt(st.nextToken()); //일과 일을 할 수 있는 날 (0 ≤ m ≤ n) 
		long answer = 0;
		
		int days[] = new int[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i<N; i++)
		{
			days[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i = 0; i<M; i++)
		{
			answer += days[i];
		}
		
		long current = answer;

		for(int i = 0; i<N-M; i++)
		{
			//전체적으로 한칸씩 오른쪽으로 이동한다고 생각해보면
            // 한칸 이동한 맨 왼쪽 값은 빼고
            // 한칸 이동한 맨 오른쪽 값은 더해준다!
			int a = i;
			int b = i+M;
			int c = days[i];
			int d = days[i+M];
			
			//System.out.println(a+":"+c+"   "+b+":"+d);
			
			current = current - days[i] + days[i+M];
			
			answer = Math.max(answer, current);
		}
		
		System.out.println(answer);

	}

}